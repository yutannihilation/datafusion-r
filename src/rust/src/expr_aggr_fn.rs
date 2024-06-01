use datafusion::logical_expr::{self};
use savvy::savvy;

use crate::{
    expr::{DataFusionRExpr, DataFusionRExprs},
    expr_fn::DataFusionRExprFunctions,
};

#[savvy]
impl DataFusionRExprFunctions {
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
    // - in_list
    // - in_subquery
    // - not_in_subquery

    fn max(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::max(arg.0)))
    }

    fn median(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::median(arg.0)))
    }

    fn min(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(logical_expr::expr_fn::min(arg.0)))
    }

    // TODO:
    //
    // - out_ref_col

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
}
