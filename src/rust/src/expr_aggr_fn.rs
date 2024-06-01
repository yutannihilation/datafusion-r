use datafusion::logical_expr::{self, lit};
use savvy::{savvy, Sexp, TypedSexp};

use crate::{
    expr::{DataFusionRExpr, DataFusionRExprs},
    expr_fn::DataFusionRExprFunctions,
};

#[savvy]
impl DataFusionRExprFunctions {
    fn and(left: DataFusionRExpr, right: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::and(left.0, right.0)))
    }

    fn approx_distinct(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::approx_distinct(
            arg.0,
        )))
    }

    fn approx_percentile_cont(
        expr: DataFusionRExpr,
        percentile: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(
            logical_expr::expr_fn::approx_percentile_cont(expr.0, percentile.0),
        ))
    }

    fn approx_percentile_cont_with_weight(
        expr: DataFusionRExpr,
        weight_expr: DataFusionRExpr,
        percentile: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(
            logical_expr::expr_fn::approx_percentile_cont_with_weight(
                expr.0,
                weight_expr.0,
                percentile.0,
            ),
        ))
    }

    fn array_agg(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::array_agg(arg.0)))
    }

    fn approx_median(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::approx_median(arg.0)))
    }

    fn avg(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::avg(arg.0)))
    }

    // TODO: support Operator?
    //
    // fn binary_expr(
    //     left: DataFusionRExpr,
    //     op: DataFusionRExpr,
    //     right: DataFusionRExpr,
    // ) -> savvy::Result<DataFusionRExpr> {
    //     Ok(DataFusionRExpr(logical_expr::expr_fn::binary_expr(
    //         left.0, op.0, right.0,
    //     )))
    // }

    fn bitwise_and(
        left: DataFusionRExpr,
        right: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::bitwise_and(
            left.0, right.0,
        )))
    }

    fn bitwise_or(left: DataFusionRExpr, right: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::bitwise_or(
            left.0, right.0,
        )))
    }

    fn bitwise_shift_left(
        left: DataFusionRExpr,
        right: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::bitwise_shift_left(
            left.0, right.0,
        )))
    }

    fn bitwise_shift_right(
        left: DataFusionRExpr,
        right: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::bitwise_shift_right(
            left.0, right.0,
        )))
    }

    fn bitwise_xor(
        left: DataFusionRExpr,
        right: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::bitwise_xor(
            left.0, right.0,
        )))
    }

    // TODO: support CaseBuilder?
    // fn case(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
    //     Ok(DataFusionRExpr(logical_expr::expr_fn::case(arg.0)))
    // }
    //
    // - when

    // TODO: support datatype?
    //
    // fn cast(
    //     expr: DataFusionRExpr,
    //     data_type: DataFusionRExpr,
    // ) -> savvy::Result<DataFusionRExpr> {
    //     Ok(DataFusionRExpr(logical_expr::expr_fn::cast(
    //         expr.0, data_type.0,
    //     )))
    // }
    //
    // - try_cast

    fn col(arg: &str) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::col(arg)))
    }

    fn count(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::count(arg.0)))
    }

    fn count_distinct(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::count_distinct(
            arg.0,
        )))
    }

    // TODO
    //
    // - create_udaf
    // - create_udf
    // - create_udwf

    fn cube(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::cube(args.0)))
    }

    // TODO
    //
    // - exists
    // - not_exists
    // - grouping_set

    fn ident(arg: &str) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::ident(arg)))
    }

    // TODO
    //
    // - in_list
    // - in_subquery
    // - not_in_subquery

    fn is_false(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_false(arg.0)))
    }

    fn is_not_false(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_not_false(arg.0)))
    }

    fn is_not_true(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_not_true(arg.0)))
    }

    fn is_not_unknown(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_not_unknown(
            arg.0,
        )))
    }

    fn is_null(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_null(arg.0)))
    }

    fn is_true(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_true(arg.0)))
    }

    fn is_unknown(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::is_unknown(arg.0)))
    }

    fn max(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::max(arg.0)))
    }

    fn median(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::median(arg.0)))
    }

    fn min(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::min(arg.0)))
    }

    fn not(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::not(arg.0)))
    }

    fn or(left: DataFusionRExpr, right: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::or(left.0, right.0)))
    }

    // TODO:
    //
    // - out_ref_col

    fn placeholder(arg: &str) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::placeholder(arg)))
    }

    fn rollup(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::rollup(args.0)))
    }

    // TODO:
    //
    // - scalar_subquery

    fn stddev(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::stddev(arg.0)))
    }

    fn sum(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::sum(arg.0)))
    }

    fn lit(x: Sexp) -> savvy::Result<DataFusionRExpr> {
        let lit = match &x.into_typed() {
            TypedSexp::Integer(i) => lit(i.as_slice()[0]),
            TypedSexp::Real(r) => lit(r.as_slice()[0]),
            TypedSexp::Logical(l) => lit(l.iter().next().unwrap()),
            TypedSexp::String(s) => lit(s.iter().next().unwrap()),
            _ => return Err("Unsupported type".into()),
        };
        Ok(DataFusionRExpr(lit))
    }

    fn wildcard() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::wildcard()))
    }
}
