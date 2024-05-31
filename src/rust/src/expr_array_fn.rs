use datafusion::functions_array;
use savvy::savvy;

use crate::{
    expr::{DataFusionRExpr, DataFusionRExprs},
    expr_fn::DataFusionRExprFunctions,
};

#[savvy]
impl DataFusionRExprFunctions {
    fn array_append(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_append(
            array.0, element.0,
        )))
    }

    fn array_concat(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_concat(
            args.0,
        )))
    }

    fn array_dims(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_dims(
            array.0,
        )))
    }

    fn array_distinct(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_distinct(
            array.0,
        )))
    }

    fn array_element(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_element(
            array.0, element.0,
        )))
    }

    fn array_empty(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_empty(
            array.0,
        )))
    }

    fn array_except(
        first_array: DataFusionRExpr,
        second_array: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_except(
            first_array.0,
            second_array.0,
        )))
    }

    fn array_has(
        first_array: DataFusionRExpr,
        second_array: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_has(
            first_array.0,
            second_array.0,
        )))
    }

    fn array_has_all(
        first_array: DataFusionRExpr,
        second_array: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_has_all(
            first_array.0,
            second_array.0,
        )))
    }

    fn array_has_any(
        first_array: DataFusionRExpr,
        second_array: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_has_any(
            first_array.0,
            second_array.0,
        )))
    }

    fn array_intersect(
        first_array: DataFusionRExpr,
        second_array: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_intersect(
            first_array.0,
            second_array.0,
        )))
    }

    fn array_ndims(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_ndims(
            array.0,
        )))
    }

    fn array_pop_back(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_pop_back(
            array.0,
        )))
    }

    fn array_pop_front(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_pop_front(
            array.0,
        )))
    }

    fn array_position(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
        index: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_position(
            array.0, element.0, index.0,
        )))
    }

    fn array_positions(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_positions(
            array.0, element.0,
        )))
    }

    fn array_prepend(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_prepend(
            array.0, element.0,
        )))
    }

    fn array_remove(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_remove(
            array.0, element.0,
        )))
    }

    fn array_remove_all(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_remove_all(
            array.0, element.0,
        )))
    }

    fn array_remove_n(
        array: DataFusionRExpr,
        element: DataFusionRExpr,
        max: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_remove_n(
            array.0, element.0, max.0,
        )))
    }

    fn array_repeat(
        array: DataFusionRExpr,
        count: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_repeat(
            array.0, count.0,
        )))
    }

    fn array_replace(
        array: DataFusionRExpr,
        from: DataFusionRExpr,
        to: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_replace(
            array.0, from.0, to.0,
        )))
    }

    fn array_replace_all(
        array: DataFusionRExpr,
        from: DataFusionRExpr,
        to: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(
            functions_array::expr_fn::array_replace_all(array.0, from.0, to.0),
        ))
    }

    fn array_replace_n(
        array: DataFusionRExpr,
        from: DataFusionRExpr,
        to: DataFusionRExpr,
        max: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_replace_n(
            array.0, from.0, to.0, max.0,
        )))
    }

    fn array_resize(
        array: DataFusionRExpr,
        size: DataFusionRExpr,
        value: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_resize(
            array.0, size.0, value.0,
        )))
    }

    fn array_reverse(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_reverse(
            array.0,
        )))
    }

    fn array_slice(
        array: DataFusionRExpr,
        begin: DataFusionRExpr,
        end: DataFusionRExpr,
        stride: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_slice(
            array.0, begin.0, end.0, stride.0,
        )))
    }

    fn array_sort(
        array: DataFusionRExpr,
        desc: DataFusionRExpr,
        null_first: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_sort(
            array.0,
            desc.0,
            null_first.0,
        )))
    }

    fn array_to_string(
        array: DataFusionRExpr,
        delimiter: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_to_string(
            array.0,
            delimiter.0,
        )))
    }

    fn array_union(
        array1: DataFusionRExpr,
        array2: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::array_union(
            array1.0, array2.0,
        )))
    }

    fn cardinality(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::cardinality(
            array.0,
        )))
    }

    fn flatten(array: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::flatten(array.0)))
    }

    fn gen_series(
        start: DataFusionRExpr,
        stop: DataFusionRExpr,
        step: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::gen_series(
            start.0, stop.0, step.0,
        )))
    }

    fn make_array(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::make_array(
            args.0,
        )))
    }

    fn range(
        start: DataFusionRExpr,
        stop: DataFusionRExpr,
        step: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::range(
            start.0, stop.0, step.0,
        )))
    }

    fn string_to_array(
        array: DataFusionRExpr,
        delimiter: DataFusionRExpr,
        null_string: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(functions_array::expr_fn::string_to_array(
            array.0,
            delimiter.0,
            null_string.0,
        )))
    }
}
