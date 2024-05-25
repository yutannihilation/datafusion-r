mod expr;

use std::sync::Arc;

use arrow::{
    error::ArrowError,
    ffi_stream::{ArrowArrayStreamReader, FFI_ArrowArrayStream},
    record_batch::RecordBatchReader,
};
use datafusion::{
    arrow::{array::RecordBatch, util::pretty},
    dataframe::DataFrame,
    datasource::MemTable,
    execution::{context::SessionContext, options::ParquetReadOptions},
};
use expr::DataFusionRExprs;
use pollster::block_on;
use savvy::{r_eprintln, r_println, savvy, OwnedIntegerSexp, OwnedStringSexp, Sexp, StringSexp};

#[savvy]
struct DataFusionRDataFrame {
    df: Arc<DataFrame>,
}

impl DataFusionRDataFrame {
    fn new(df: DataFrame) -> Self {
        Self { df: Arc::new(df) }
    }
}

#[savvy]
struct RawArrayStream(FFI_ArrowArrayStream);

#[savvy]
impl RawArrayStream {
    fn new_without_init() -> savvy::Result<Self> {
        Ok(Self(FFI_ArrowArrayStream::empty()))
    }
}

#[savvy]
struct DataFusionRSessionContext {
    pub ctx: SessionContext,
}

#[savvy]
impl DataFusionRSessionContext {
    fn new() -> savvy::Result<Self> {
        Ok(Self {
            ctx: SessionContext::new(),
        })
    }

    fn create_data_frame(
        &mut self,
        mut raw_stream: RawArrayStream,
        table_name: &str,
    ) -> savvy::Result<DataFusionRDataFrame> {
        let stream_reader = unsafe { ArrowArrayStreamReader::from_raw(&mut raw_stream.0) }
            .map_err(|e| savvy::Error::from(e.to_string()))?;
        let schema = stream_reader.schema();
        let batches: Vec<RecordBatch> = stream_reader
            .collect::<Result<Vec<RecordBatch>, ArrowError>>()
            .map_err(|e| savvy::Error::from(e.to_string()))?;

        let table = MemTable::try_new(schema, vec![batches])
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;

        self.ctx
            .register_table(table_name, Arc::new(table))
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;

        let df = block_on(self.ctx.table(table_name))
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;

        Ok(DataFusionRDataFrame::new(df))
    }

    fn sql(&mut self, sql: &str) -> savvy::Result<DataFusionRDataFrame> {
        match pollster::block_on(self.ctx.sql(sql)) {
            Ok(df) => Ok(DataFusionRDataFrame::new(df)),
            Err(e) => Err(e.to_string().into()),
        }
    }

    fn register_parquet(
        &mut self,
        name: &str,
        path: &str,
        file_extension: Option<&str>,
        // table_partition_cols: Vec<(String, String)>,
        parquet_pruning: Option<bool>,
        skip_metadata: Option<bool>,
        // schema: Option<PyArrowType<Schema>>,
        // file_sort_order: Option<Vec<Vec<PyExpr>>>,
    ) -> savvy::Result<()> {
        let file_extension = file_extension.unwrap_or(".parquet");

        let options = ParquetReadOptions {
            file_extension,
            parquet_pruning,
            skip_metadata,
            ..Default::default()
        };

        // TODO
        // options.schema =

        // TODO
        // options.file_sort_order =

        pollster::block_on(self.ctx.register_parquet(name, path, options))
            .map_err(|e| savvy::Error::from(e.to_string()))?;

        Ok(())
    }
}

#[savvy]
impl DataFusionRDataFrame {
    fn print(&self) -> savvy::Result<()> {
        let df = self.df.as_ref().clone();
        let batches = block_on(df.collect()).expect("Must not fail"); // TODO: handle async properly
        let batches_as_string = pretty::pretty_format_batches(&batches);

        match batches_as_string {
            Ok(batch) => r_println!("DataFrame()\n{batch}"),
            Err(err) => r_eprintln!("Error: {:?}", err.to_string()),
        };

        Ok(())
    }

    fn limit(&self, n: usize, offset: usize) -> savvy::Result<Self> {
        let new_df = self
            .df
            .as_ref()
            .clone()
            .limit(offset, Some(n))
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;
        Ok(Self::new(new_df))
    }

    fn select_columns(&self, columns: StringSexp) -> savvy::Result<Self> {
        let columns = columns.to_vec();
        let new_df = self
            .df
            .as_ref()
            .clone()
            .select_columns(&columns)
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;
        Ok(Self::new(new_df))
    }

    // TODO: handle multiple exprs
    fn select(&self, exprs: DataFusionRExprs) -> savvy::Result<Self> {
        let new_df = self
            .df
            .as_ref()
            .clone()
            .select(exprs.0)
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;
        Ok(Self::new(new_df))
    }

    fn dim(&self) -> savvy::Result<Sexp> {
        let mut out = OwnedIntegerSexp::new(2)?;

        // nrow
        out[0] = pollster::block_on((*self.df).clone().count())
            .map_err(|e| <savvy::Error>::from(e.to_string()))? as _;

        // ncol
        out[1] = self.df.schema().fields().len() as _;

        out.into()
    }

    fn names(&self) -> savvy::Result<Sexp> {
        let iter = self.df.schema().fields().iter().map(|x| x.name());
        let out = OwnedStringSexp::try_from_iter(iter)?;
        out.into()
    }
}
