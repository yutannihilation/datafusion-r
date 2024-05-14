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
    logical_expr::{col, lit, Expr},
};
use pollster::block_on;
use savvy::{r_eprintln, r_println, savvy, Sexp, StringSexp, TypedSexp};

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
struct RawArrayStream(FFI_ArrowArrayStream);

#[savvy]
impl RawArrayStream {
    fn new_without_init() -> savvy::Result<Self> {
        Ok(Self(FFI_ArrowArrayStream::empty()))
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

    fn create_data_frame(
        &mut self,
        mut raw_stream: RawArrayStream,
        table_name: &str,
    ) -> savvy::Result<RDataFrame> {
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
    fn select(&self, exprs: RExprs) -> savvy::Result<Self> {
        let new_df = self
            .df
            .as_ref()
            .clone()
            .select(exprs.0)
            .map_err(|e| <savvy::Error>::from(e.to_string()))?;
        Ok(Self::new(new_df))
    }
}

#[savvy]
struct RExpr(Expr);

#[savvy]
impl RExpr {
    fn print(&self) -> savvy::Result<()> {
        r_println!("{}", self.0.to_string());
        Ok(())
    }

    fn col(x: &str) -> savvy::Result<Self> {
        Ok(Self(col(x)))
    }

    fn lit(x: Sexp) -> savvy::Result<Self> {
        let lit = match &x.into_typed() {
            TypedSexp::Integer(i) => lit(i.as_slice()[0]),
            TypedSexp::Real(r) => lit(r.as_slice()[0]),
            TypedSexp::Logical(l) => lit(l.iter().next().unwrap()),
            TypedSexp::String(s) => lit(s.iter().next().unwrap()),
            _ => return Err("Unsupported type".into()),
        };
        Ok(Self(lit))
    }

    fn add(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 + rhs.0))
    }

    fn sub(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 - rhs.0))
    }

    fn mul(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 * rhs.0))
    }

    fn div(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 / rhs.0))
    }

    fn modulo(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 % rhs.0))
    }

    fn lt(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.lt(rhs.0)))
    }

    fn lt_eq(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.lt_eq(rhs.0)))
    }

    fn gt(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.gt(rhs.0)))
    }

    fn gt_eq(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.gt_eq(rhs.0)))
    }

    fn eq(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.eq(rhs.0)))
    }

    fn not_eq(self, rhs: RExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.not_eq(rhs.0)))
    }

    fn alias(self, name: &str) -> savvy::Result<Self> {
        Ok(Self(self.0.alias(name)))
    }
}

#[savvy]
struct RExprs(Vec<Expr>);

#[savvy]
impl RExprs {
    fn new(capacity: usize) -> savvy::Result<Self> {
        Ok(Self(Vec::with_capacity(capacity)))
    }

    fn add_expr(&mut self, expr: RExpr) -> savvy::Result<()> {
        self.0.push(expr.0);
        Ok(())
    }
}
