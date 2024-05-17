use datafusion::logical_expr::{col, lit, Expr};
use savvy::{r_println, savvy, Sexp, TypedSexp};

#[savvy]
struct DataFusionRExpr(pub(crate) Expr);

#[savvy]
impl DataFusionRExpr {
    fn print(&self) -> savvy::Result<()> {
        r_println!("{}", self.0);
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

    fn add(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 + rhs.0))
    }

    fn sub(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 - rhs.0))
    }

    fn mul(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 * rhs.0))
    }

    fn div(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 / rhs.0))
    }

    fn reminder(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 % rhs.0))
    }

    fn lt(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.lt(rhs.0)))
    }

    fn lt_eq(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.lt_eq(rhs.0)))
    }

    fn gt(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.gt(rhs.0)))
    }

    fn gt_eq(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.gt_eq(rhs.0)))
    }

    fn eq(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.eq(rhs.0)))
    }

    fn not_eq(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.not_eq(rhs.0)))
    }

    fn and(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.and(rhs.0)))
    }

    fn or(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.or(rhs.0)))
    }

    fn bitand(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 & rhs.0))
    }

    fn bitor(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 | rhs.0))
    }

    fn bitxor(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0 ^ rhs.0))
    }

    fn field(self, name: &str) -> savvy::Result<Self> {
        Ok(Self(self.0.field(name)))
    }

    fn index(self, key: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.index(key.0)))
    }

    fn range(self, start: DataFusionRExpr, stop: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.range(start.0, stop.0)))
    }

    fn like(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.like(rhs.0)))
    }

    fn not_like(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.not_like(rhs.0)))
    }

    fn ilike(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.ilike(rhs.0)))
    }

    fn not_ilike(self, rhs: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.not_ilike(rhs.0)))
    }

    fn between(self, low: DataFusionRExpr, high: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.between(low.0, high.0)))
    }

    fn not_between(self, low: DataFusionRExpr, high: DataFusionRExpr) -> savvy::Result<Self> {
        Ok(Self(self.0.not_between(low.0, high.0)))
    }

    fn alias(self, name: &str) -> savvy::Result<Self> {
        Ok(Self(self.0.alias(name)))
    }

    fn in_list(self, list: DataFusionRExprs, negated: bool) -> savvy::Result<Self> {
        Ok(Self(self.0.in_list(list.0, negated)))
    }

    // Unary

    fn neg(self) -> savvy::Result<Self> {
        Ok(Self(-self.0))
    }

    fn not(self) -> savvy::Result<Self> {
        Ok(Self(!self.0))
    }

    fn is_null(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_null()))
    }

    fn is_not_null(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_not_null()))
    }

    fn is_true(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_true()))
    }

    fn is_not_true(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_not_true()))
    }

    fn is_false(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_false()))
    }

    fn is_not_false(self) -> savvy::Result<Self> {
        Ok(Self(self.0.is_not_false()))
    }
}

#[savvy]
pub(crate) struct DataFusionRExprs(pub(crate) Vec<Expr>);

#[savvy]
impl DataFusionRExprs {
    fn new(capacity: usize) -> savvy::Result<Self> {
        Ok(Self(Vec::with_capacity(capacity)))
    }

    fn add_expr(&mut self, expr: DataFusionRExpr) -> savvy::Result<()> {
        self.0.push(expr.0);
        Ok(())
    }

    fn print(&self) -> savvy::Result<()> {
        for x in self.0.iter() {
            r_println!("{x}");
        }

        Ok(())
    }
}
