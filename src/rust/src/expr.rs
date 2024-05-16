use datafusion::logical_expr::{col, lit, Expr};
use savvy::{r_println, savvy, Sexp, TypedSexp};

#[savvy]
struct RExpr(pub(crate) Expr);

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
pub(crate) struct RExprs(pub(crate) Vec<Expr>);

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
