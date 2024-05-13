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
    execution::context::SessionContext,
};
use pollster::block_on;
use savvy::{r_eprintln, r_println, savvy, ExternalPointerSexp, Sexp};

#[savvy]
struct RDataFrame {
    df: Arc<DataFrame>,
}

impl RDataFrame {
    fn new(df: DataFrame) -> Self {
        Self { df: Arc::new(df) }
    }
}

#[savvy]
struct RSessionContext {
    pub ctx: SessionContext,
}

#[savvy]
impl RSessionContext {
    fn new() -> savvy::Result<Self> {
        Ok(Self {
            ctx: SessionContext::new(),
        })
    }

    fn create_data_frame(&mut self, input: Sexp, table_name: &str) -> savvy::Result<RDataFrame> {
        let input_ptr = ExternalPointerSexp::try_from(input)?;
        let raw_stream = unsafe { input_ptr.cast_mut_unchecked::<FFI_ArrowArrayStream>() };
        let stream_reader = unsafe { ArrowArrayStreamReader::from_raw(raw_stream) }
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

        Ok(RDataFrame::new(df))
    }
}

#[savvy]
impl RDataFrame {
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
}
