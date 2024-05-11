use std::sync::Arc;

use datafusion::{arrow::util::pretty, dataframe::DataFrame};
use pollster::block_on;
use savvy::{r_eprintln, r_println, savvy};

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
impl RDataFrame {
    fn print(&mut self) -> savvy::Result<()> {
        let df = self.df.as_ref().clone();
        let batches = block_on(df.collect()).expect("Must not fail"); // TODO: handle error
        let batches_as_string = pretty::pretty_format_batches(&batches);

        match batches_as_string {
            Ok(batch) => r_println!("DataFrame()\n{batch}"),
            Err(err) => r_eprintln!("Error: {:?}", err.to_string()),
        };

        Ok(())
    }
}
