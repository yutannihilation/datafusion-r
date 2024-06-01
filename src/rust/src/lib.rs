#![allow(clippy::too_many_arguments)]

mod data_frame;
mod expr;
mod expr_aggr_fn;
mod expr_array_fn;
mod expr_fn;
mod runtime;

use std::sync::Arc;

use arrow::{
    error::ArrowError,
    ffi_stream::{ArrowArrayStreamReader, FFI_ArrowArrayStream},
    record_batch::RecordBatchReader,
};
use data_frame::DataFusionRDataFrame;
use datafusion::{
    arrow::array::RecordBatch,
    datasource::MemTable,
    execution::{
        context::SessionContext,
        options::{CsvReadOptions, ParquetReadOptions},
    },
};
use runtime::RUNTIME;
use savvy::savvy;

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

        match RUNTIME.get() {
            Some(rt) => match rt.block_on(self.ctx.table(table_name)) {
                Ok(df) => Ok(DataFusionRDataFrame::new(df)),
                Err(e) => Err(e.to_string().into()),
            },
            None => Err("Failed to get Tokio runtime".into()),
        }
    }

    fn sql(&mut self, sql: &str) -> savvy::Result<DataFusionRDataFrame> {
        match RUNTIME.get() {
            Some(rt) => match rt.block_on(self.ctx.sql(sql)) {
                Ok(df) => Ok(DataFusionRDataFrame::new(df)),
                Err(e) => Err(e.to_string().into()),
            },
            None => Err("Failed to get Tokio runtime".into()),
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
        let default = ParquetReadOptions::default();

        let options = ParquetReadOptions {
            file_extension: file_extension.unwrap_or(default.file_extension),
            parquet_pruning,
            skip_metadata,
            ..default
        };

        // TODO
        // options.schema =

        // TODO
        // options.file_sort_order =

        match RUNTIME.get() {
            Some(rt) => match rt.block_on(self.ctx.register_parquet(name, path, options)) {
                Ok(_) => Ok(()),
                Err(e) => Err(e.to_string().into()),
            },
            None => Err("Failed to get Tokio runtime".into()),
        }
    }

    fn register_csv(
        &mut self,
        name: &str,
        path: &str,
        has_header: Option<bool>,
        delimiter: Option<&str>,
        quote: Option<&str>,
        escape: Option<&str>,
        // schema:
        schema_infer_max_records: Option<usize>,
        file_extension: Option<&str>,
        // table_partition_cols: Vec<(String, String)>,
        // file_compression_type: Option<FileCompressionType>
        // file_sort_order: Option<Vec<Vec<PyExpr>>>,
    ) -> savvy::Result<()> {
        let default = CsvReadOptions::default();

        #[inline]
        fn str_to_u8(x: &str) -> savvy::Result<u8> {
            let x = x.as_bytes();
            if x.len() == 1 {
                Ok(x[0])
            } else {
                Err("Must be a character".into())
            }
        }

        let delimiter = if let Some(x) = delimiter {
            str_to_u8(x)?
        } else {
            default.delimiter
        };

        let quote = if let Some(x) = quote {
            str_to_u8(x)?
        } else {
            default.quote
        };

        let escape = if let Some(x) = escape {
            Some(str_to_u8(x)?)
        } else {
            None
        };

        let options = CsvReadOptions {
            has_header: has_header.unwrap_or(default.has_header),
            delimiter,
            quote,
            escape,
            schema_infer_max_records: schema_infer_max_records
                .unwrap_or(default.schema_infer_max_records),
            file_extension: file_extension.unwrap_or(default.file_extension),
            ..default
        };

        match RUNTIME.get() {
            Some(rt) => match rt.block_on(self.ctx.register_csv(name, path, options)) {
                Ok(_) => Ok(()),
                Err(e) => Err(e.to_string().into()),
            },
            None => Err("Failed to get Tokio runtime".into()),
        }
    }
}
