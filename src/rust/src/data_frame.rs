use std::sync::Arc;

use arrow::{array::RecordBatchIterator, ffi_stream::FFI_ArrowArrayStream};
use datafusion::{arrow::util::pretty, dataframe::DataFrame};

use savvy::{r_eprintln, r_println, savvy, OwnedIntegerSexp, OwnedStringSexp, Sexp, StringSexp};

use crate::{expr::DataFusionRExprs, runtime::RUNTIME, RawArrayStream};

#[savvy]
struct DataFusionRDataFrame {
    df: Arc<DataFrame>,
}

impl DataFusionRDataFrame {
    pub(crate) fn new(df: DataFrame) -> Self {
        Self { df: Arc::new(df) }
    }
}

#[savvy]
impl DataFusionRDataFrame {
    fn print(&self) -> savvy::Result<()> {
        let df = self.df.as_ref().clone();
        let record_batches = match RUNTIME.get() {
            Some(rt) => match rt.block_on(df.collect()) {
                Ok(batches) => batches,
                Err(e) => return Err(e.to_string().into()),
            },
            None => return Err("Failed to get Tokio runtime".into()),
        };
        let batches_as_string = pretty::pretty_format_batches(&record_batches);

        match batches_as_string {
            Ok(batch) => r_println!("DataFrame()\n{batch}"),
            Err(err) => r_eprintln!("Error: {:?}", err.to_string()),
        };

        Ok(())
    }

    fn logical_plan(&self) -> savvy::Result<()> {
        r_println!("{}", self.df.as_ref().logical_plan().display());
        Ok(())
    }

    // fn explain(&self) -> savvy::Result<()> {
    //     r_println!("{}", self.df.as_ref().explain(true, true).unwrap());
    //     Ok(())
    // }

    fn collect(&self) -> savvy::Result<RawArrayStream> {
        let record_batches = match RUNTIME.get() {
            Some(rt) => match rt.block_on(self.df.as_ref().clone().collect()) {
                Ok(batches) => batches,
                Err(e) => return Err(e.to_string().into()),
            },
            None => return Err("Failed to get Tokio runtime".into()),
        };

        let schema = self.df.as_ref().schema().as_arrow();
        let iter =
            RecordBatchIterator::new(record_batches.into_iter().map(Ok), Arc::new(schema.clone()));

        let array_stream = FFI_ArrowArrayStream::new(Box::new(iter));
        Ok(RawArrayStream(array_stream))
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
        match RUNTIME.get() {
            Some(rt) => match rt.block_on((*self.df).clone().count()) {
                Ok(i) => {
                    out[0] = i as _;
                }
                Err(e) => return Err(e.to_string().into()),
            },
            None => return Err("Failed to get Tokio runtime".into()),
        };

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
