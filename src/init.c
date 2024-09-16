
#include <stdint.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>

#include "rust/api.h"

static uintptr_t TAGGED_POINTER_MASK = (uintptr_t)1;

SEXP handle_result(SEXP res_) {
    uintptr_t res = (uintptr_t)res_;

    // An error is indicated by tag.
    if ((res & TAGGED_POINTER_MASK) == 1) {
        // Remove tag
        SEXP res_aligned = (SEXP)(res & ~TAGGED_POINTER_MASK);

        // Currently, there are two types of error cases:
        //
        //   1. Error from Rust code
        //   2. Error from R's C API, which is caught by R_UnwindProtect()
        //
        if (TYPEOF(res_aligned) == CHARSXP) {
            // In case 1, the result is an error message that can be passed to
            // Rf_errorcall() directly.
            Rf_errorcall(R_NilValue, "%s", CHAR(res_aligned));
        } else {
            // In case 2, the result is the token to restart the
            // cleanup process on R's side.
            R_ContinueUnwind(res_aligned);
        }
    }

    return (SEXP)res;
}

SEXP savvy_init_runtime__impl(DllInfo* c_arg___dll_info) {
    SEXP res = savvy_init_runtime__ffi(c_arg___dll_info);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_print__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_print__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_logical_plan__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_logical_plan__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_collect__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_collect__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_limit__impl(SEXP self__, SEXP c_arg__n, SEXP c_arg__offset) {
    SEXP res = savvy_DataFusionRDataFrame_limit__ffi(self__, c_arg__n, c_arg__offset);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_select_columns__impl(SEXP self__, SEXP c_arg__columns) {
    SEXP res = savvy_DataFusionRDataFrame_select_columns__ffi(self__, c_arg__columns);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_select__impl(SEXP self__, SEXP c_arg__exprs) {
    SEXP res = savvy_DataFusionRDataFrame_select__ffi(self__, c_arg__exprs);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_aggregate__impl(SEXP self__, SEXP c_arg__group_expr, SEXP c_arg__aggr_expr) {
    SEXP res = savvy_DataFusionRDataFrame_aggregate__ffi(self__, c_arg__group_expr, c_arg__aggr_expr);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_dim__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_dim__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_names__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_names__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_ident__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExpr_ident__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lit__impl(SEXP c_arg__x) {
    SEXP res = savvy_DataFusionRExpr_lit__ffi(c_arg__x);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_col__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExpr_col__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_wildcard__impl(void) {
    SEXP res = savvy_DataFusionRExpr_wildcard__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_print__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_print__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_and__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_and__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitwise_and__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_bitwise_and__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitwise_or__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_bitwise_or__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitwise_shift_left__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_bitwise_shift_left__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitwise_shift_right__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_bitwise_shift_right__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_or__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_or__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_placeholder__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExpr_placeholder__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_add__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_add__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_sub__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_sub__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_mul__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_mul__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_div__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_div__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_reminder__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_reminder__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lt__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_lt__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lt_eq__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_lt_eq__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_gt__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_gt__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_gt_eq__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_gt_eq__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_eq__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_eq__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_eq__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_not_eq__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitand__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_bitand__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitor__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_bitor__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitxor__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_bitxor__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_field__impl(SEXP self__, SEXP c_arg__name) {
    SEXP res = savvy_DataFusionRExpr_field__ffi(self__, c_arg__name);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_index__impl(SEXP self__, SEXP c_arg__key) {
    SEXP res = savvy_DataFusionRExpr_index__ffi(self__, c_arg__key);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_range__impl(SEXP self__, SEXP c_arg__start, SEXP c_arg__stop) {
    SEXP res = savvy_DataFusionRExpr_range__ffi(self__, c_arg__start, c_arg__stop);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_like__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_like__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_like__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_not_like__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_ilike__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_ilike__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_ilike__impl(SEXP self__, SEXP c_arg__rhs) {
    SEXP res = savvy_DataFusionRExpr_not_ilike__ffi(self__, c_arg__rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_between__impl(SEXP self__, SEXP c_arg__low, SEXP c_arg__high) {
    SEXP res = savvy_DataFusionRExpr_between__ffi(self__, c_arg__low, c_arg__high);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_between__impl(SEXP self__, SEXP c_arg__low, SEXP c_arg__high) {
    SEXP res = savvy_DataFusionRExpr_not_between__ffi(self__, c_arg__low, c_arg__high);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_alias__impl(SEXP self__, SEXP c_arg__name) {
    SEXP res = savvy_DataFusionRExpr_alias__ffi(self__, c_arg__name);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_in_list__impl(SEXP self__, SEXP c_arg__list, SEXP c_arg__negated) {
    SEXP res = savvy_DataFusionRExpr_in_list__ffi(self__, c_arg__list, c_arg__negated);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_neg__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_neg__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_not__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_null__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_null__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_not_null__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_not_null__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_true__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_true__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_not_true__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_not_true__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_false__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_false__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_not_false__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_not_false__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitwise_xor__impl(SEXP self__, SEXP c_arg__right) {
    SEXP res = savvy_DataFusionRExpr_bitwise_xor__ffi(self__, c_arg__right);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_unknown__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_unknown__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_is_not_unknown__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_is_not_unknown__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_approx_distinct__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_approx_distinct__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_approx_percentile_cont__impl(SEXP c_arg__expr, SEXP c_arg__percentile) {
    SEXP res = savvy_DataFusionRExprFunctions_approx_percentile_cont__ffi(c_arg__expr, c_arg__percentile);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_approx_percentile_cont_with_weight__impl(SEXP c_arg__expr, SEXP c_arg__weight_expr, SEXP c_arg__percentile) {
    SEXP res = savvy_DataFusionRExprFunctions_approx_percentile_cont_with_weight__ffi(c_arg__expr, c_arg__weight_expr, c_arg__percentile);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_agg__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_array_agg__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_approx_median__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_approx_median__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_avg__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_avg__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_count__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_count__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_count_distinct__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_count_distinct__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cube__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_cube__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_max__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_max__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_median__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_median__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_min__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_min__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_rollup__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_rollup__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_stddev__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_stddev__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sum__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sum__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_append__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_append__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_concat__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_array_concat__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_dims__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_dims__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_distinct__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_distinct__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_element__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_element__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_empty__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_empty__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_except__impl(SEXP c_arg__first_array, SEXP c_arg__second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_except__ffi(c_arg__first_array, c_arg__second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has__impl(SEXP c_arg__first_array, SEXP c_arg__second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has__ffi(c_arg__first_array, c_arg__second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has_all__impl(SEXP c_arg__first_array, SEXP c_arg__second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has_all__ffi(c_arg__first_array, c_arg__second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has_any__impl(SEXP c_arg__first_array, SEXP c_arg__second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has_any__ffi(c_arg__first_array, c_arg__second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_intersect__impl(SEXP c_arg__first_array, SEXP c_arg__second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_intersect__ffi(c_arg__first_array, c_arg__second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_ndims__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_ndims__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_pop_back__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_pop_back__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_pop_front__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_pop_front__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_position__impl(SEXP c_arg__array, SEXP c_arg__element, SEXP c_arg__index) {
    SEXP res = savvy_DataFusionRExprFunctions_array_position__ffi(c_arg__array, c_arg__element, c_arg__index);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_positions__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_positions__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_prepend__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_prepend__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove_all__impl(SEXP c_arg__array, SEXP c_arg__element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove_all__ffi(c_arg__array, c_arg__element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove_n__impl(SEXP c_arg__array, SEXP c_arg__element, SEXP c_arg__max) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove_n__ffi(c_arg__array, c_arg__element, c_arg__max);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_repeat__impl(SEXP c_arg__array, SEXP c_arg__count) {
    SEXP res = savvy_DataFusionRExprFunctions_array_repeat__ffi(c_arg__array, c_arg__count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace__impl(SEXP c_arg__array, SEXP c_arg__from, SEXP c_arg__to) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace__ffi(c_arg__array, c_arg__from, c_arg__to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace_all__impl(SEXP c_arg__array, SEXP c_arg__from, SEXP c_arg__to) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace_all__ffi(c_arg__array, c_arg__from, c_arg__to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace_n__impl(SEXP c_arg__array, SEXP c_arg__from, SEXP c_arg__to, SEXP c_arg__max) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace_n__ffi(c_arg__array, c_arg__from, c_arg__to, c_arg__max);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_resize__impl(SEXP c_arg__array, SEXP c_arg__size, SEXP c_arg__value) {
    SEXP res = savvy_DataFusionRExprFunctions_array_resize__ffi(c_arg__array, c_arg__size, c_arg__value);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_reverse__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_reverse__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_slice__impl(SEXP c_arg__array, SEXP c_arg__begin, SEXP c_arg__end, SEXP c_arg__stride) {
    SEXP res = savvy_DataFusionRExprFunctions_array_slice__ffi(c_arg__array, c_arg__begin, c_arg__end, c_arg__stride);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_sort__impl(SEXP c_arg__array, SEXP c_arg__desc, SEXP c_arg__null_first) {
    SEXP res = savvy_DataFusionRExprFunctions_array_sort__ffi(c_arg__array, c_arg__desc, c_arg__null_first);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_to_string__impl(SEXP c_arg__array, SEXP c_arg__delimiter) {
    SEXP res = savvy_DataFusionRExprFunctions_array_to_string__ffi(c_arg__array, c_arg__delimiter);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_union__impl(SEXP c_arg__array1, SEXP c_arg__array2) {
    SEXP res = savvy_DataFusionRExprFunctions_array_union__ffi(c_arg__array1, c_arg__array2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cardinality__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_cardinality__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_flatten__impl(SEXP c_arg__array) {
    SEXP res = savvy_DataFusionRExprFunctions_flatten__ffi(c_arg__array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_gen_series__impl(SEXP c_arg__start, SEXP c_arg__stop, SEXP c_arg__step) {
    SEXP res = savvy_DataFusionRExprFunctions_gen_series__ffi(c_arg__start, c_arg__stop, c_arg__step);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_make_array__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_make_array__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_range__impl(SEXP c_arg__start, SEXP c_arg__stop, SEXP c_arg__step) {
    SEXP res = savvy_DataFusionRExprFunctions_range__ffi(c_arg__start, c_arg__stop, c_arg__step);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_string_to_array__impl(SEXP c_arg__array, SEXP c_arg__delimiter, SEXP c_arg__null_string) {
    SEXP res = savvy_DataFusionRExprFunctions_string_to_array__ffi(c_arg__array, c_arg__delimiter, c_arg__null_string);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_arrow_cast__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_arrow_cast__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_arrow_typeof__impl(SEXP c_arg__arg1) {
    SEXP res = savvy_DataFusionRExprFunctions_arrow_typeof__ffi(c_arg__arg1);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_coalesce__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_coalesce__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_get_field__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_get_field__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_named_struct__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_named_struct__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nullif__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_nullif__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nvl__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_nvl__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nvl2__impl(SEXP c_arg__arg1, SEXP c_arg__arg2, SEXP c_arg__arg3) {
    SEXP res = savvy_DataFusionRExprFunctions_nvl2__ffi(c_arg__arg1, c_arg__arg2, c_arg__arg3);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_digest__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_digest__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_md5__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_md5__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha224__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha224__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha256__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha256__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha384__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha384__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha512__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha512__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_current_date__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_current_date__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_current_time__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_current_time__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_date_bin__impl(SEXP c_arg__stride, SEXP c_arg__source, SEXP c_arg__origin) {
    SEXP res = savvy_DataFusionRExprFunctions_date_bin__ffi(c_arg__stride, c_arg__source, c_arg__origin);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_date_part__impl(SEXP c_arg__part, SEXP c_arg__date) {
    SEXP res = savvy_DataFusionRExprFunctions_date_part__ffi(c_arg__part, c_arg__date);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_date_trunc__impl(SEXP c_arg__part, SEXP c_arg__date) {
    SEXP res = savvy_DataFusionRExprFunctions_date_trunc__ffi(c_arg__part, c_arg__date);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_from_unixtime__impl(SEXP c_arg__unixtime) {
    SEXP res = savvy_DataFusionRExprFunctions_from_unixtime__ffi(c_arg__unixtime);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_make_date__impl(SEXP c_arg__year, SEXP c_arg__month, SEXP c_arg__day) {
    SEXP res = savvy_DataFusionRExprFunctions_make_date__ffi(c_arg__year, c_arg__month, c_arg__day);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_now__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_now__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_char__impl(SEXP c_arg__datetime, SEXP c_arg__format) {
    SEXP res = savvy_DataFusionRExprFunctions_to_char__ffi(c_arg__datetime, c_arg__format);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_date__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_date__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_micros__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_micros__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_millis__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_millis__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_nanos__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_nanos__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_seconds__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_seconds__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_unixtime__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_unixtime__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_decode__impl(SEXP c_arg__input, SEXP c_arg__encoding) {
    SEXP res = savvy_DataFusionRExprFunctions_decode__ffi(c_arg__input, c_arg__encoding);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_encode__impl(SEXP c_arg__input, SEXP c_arg__encoding) {
    SEXP res = savvy_DataFusionRExprFunctions_encode__ffi(c_arg__input, c_arg__encoding);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_abs__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_abs__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_acos__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_acos__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_acosh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_acosh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_asin__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_asin__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_asinh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_asinh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atan__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_atan__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atan2__impl(SEXP c_arg__x, SEXP c_arg__y) {
    SEXP res = savvy_DataFusionRExprFunctions_atan2__ffi(c_arg__x, c_arg__y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atanh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_atanh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cbrt__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_cbrt__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ceil__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_ceil__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cos__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_cos__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cosh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_cosh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cot__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_cot__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_degrees__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_degrees__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_exp__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_exp__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_factorial__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_factorial__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_floor__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_floor__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_gcd__impl(SEXP c_arg__x, SEXP c_arg__y) {
    SEXP res = savvy_DataFusionRExprFunctions_gcd__ffi(c_arg__x, c_arg__y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_isnan__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_isnan__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_iszero__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_iszero__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lcm__impl(SEXP c_arg__x, SEXP c_arg__y) {
    SEXP res = savvy_DataFusionRExprFunctions_lcm__ffi(c_arg__x, c_arg__y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ln__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_ln__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log__impl(SEXP c_arg__base, SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_log__ffi(c_arg__base, c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log2__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_log2__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log10__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_log10__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nanvl__impl(SEXP c_arg__x, SEXP c_arg__y) {
    SEXP res = savvy_DataFusionRExprFunctions_nanvl__ffi(c_arg__x, c_arg__y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_pi__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_pi__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_power__impl(SEXP c_arg__base, SEXP c_arg__exponent) {
    SEXP res = savvy_DataFusionRExprFunctions_power__ffi(c_arg__base, c_arg__exponent);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_radians__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_radians__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_random__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_random__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_round__impl(SEXP c_arg__num, SEXP c_arg__decimal_place) {
    SEXP res = savvy_DataFusionRExprFunctions_round__ffi(c_arg__num, c_arg__decimal_place);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_signum__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_signum__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sin__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_sin__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sinh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_sinh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sqrt__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_sqrt__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_tan__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_tan__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_tanh__impl(SEXP c_arg__num) {
    SEXP res = savvy_DataFusionRExprFunctions_tanh__ffi(c_arg__num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_trunc__impl(SEXP c_arg__num, SEXP c_arg__decimal_place) {
    SEXP res = savvy_DataFusionRExprFunctions_trunc__ffi(c_arg__num, c_arg__decimal_place);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_like__impl(SEXP c_arg__string, SEXP c_arg__pattern) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_like__ffi(c_arg__string, c_arg__pattern);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_match__impl(SEXP c_arg__string, SEXP c_arg__pattern) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_match__ffi(c_arg__string, c_arg__pattern);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_replace__impl(SEXP c_arg__string, SEXP c_arg__pattern, SEXP c_arg__replacement, SEXP c_arg__flags) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_replace__ffi(c_arg__string, c_arg__pattern, c_arg__replacement, c_arg__flags);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ascii__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_ascii__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_bit_length__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_bit_length__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_btrim__impl(SEXP c_arg__string, SEXP c_arg__trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_btrim__ffi(c_arg__string, c_arg__trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_chr__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_chr__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_concat__impl(SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_concat__ffi(c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_concat_ws__impl(SEXP c_arg__delimiter, SEXP c_arg__args) {
    SEXP res = savvy_DataFusionRExprFunctions_concat_ws__ffi(c_arg__delimiter, c_arg__args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ends_with__impl(SEXP c_arg__string, SEXP c_arg__suffix) {
    SEXP res = savvy_DataFusionRExprFunctions_ends_with__ffi(c_arg__string, c_arg__suffix);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_initcap__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_initcap__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_levenshtein__impl(SEXP c_arg__arg1, SEXP c_arg__arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_levenshtein__ffi(c_arg__arg1, c_arg__arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lower__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_lower__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ltrim__impl(SEXP c_arg__string, SEXP c_arg__trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_ltrim__ffi(c_arg__string, c_arg__trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_octet_length__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_octet_length__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_overlay__impl(SEXP c_arg__string, SEXP c_arg__replacement, SEXP c_arg__pos, SEXP c_arg__count) {
    SEXP res = savvy_DataFusionRExprFunctions_overlay__ffi(c_arg__string, c_arg__replacement, c_arg__pos, c_arg__count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_repeat__impl(SEXP c_arg__string, SEXP c_arg__n) {
    SEXP res = savvy_DataFusionRExprFunctions_repeat__ffi(c_arg__string, c_arg__n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_replace__impl(SEXP c_arg__string, SEXP c_arg__from, SEXP c_arg__to) {
    SEXP res = savvy_DataFusionRExprFunctions_replace__ffi(c_arg__string, c_arg__from, c_arg__to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_rtrim__impl(SEXP c_arg__string, SEXP c_arg__trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_rtrim__ffi(c_arg__string, c_arg__trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_split_part__impl(SEXP c_arg__string, SEXP c_arg__delimiter, SEXP c_arg__index) {
    SEXP res = savvy_DataFusionRExprFunctions_split_part__ffi(c_arg__string, c_arg__delimiter, c_arg__index);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_starts_with__impl(SEXP c_arg__string, SEXP c_arg__prefix) {
    SEXP res = savvy_DataFusionRExprFunctions_starts_with__ffi(c_arg__string, c_arg__prefix);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_hex__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_to_hex__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_trim__impl(SEXP c_arg__string, SEXP c_arg__trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_trim__ffi(c_arg__string, c_arg__trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_upper__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_upper__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_uuid__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_uuid__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_char_length__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_char_length__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_character_length__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_character_length__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_find_in_set__impl(SEXP c_arg__string, SEXP c_arg__strlist) {
    SEXP res = savvy_DataFusionRExprFunctions_find_in_set__ffi(c_arg__string, c_arg__strlist);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_instr__impl(SEXP c_arg__string, SEXP c_arg__substring) {
    SEXP res = savvy_DataFusionRExprFunctions_instr__ffi(c_arg__string, c_arg__substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_left__impl(SEXP c_arg__string, SEXP c_arg__n) {
    SEXP res = savvy_DataFusionRExprFunctions_left__ffi(c_arg__string, c_arg__n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_length__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_length__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lpad__impl(SEXP c_arg__string, SEXP c_arg__padding_str) {
    SEXP res = savvy_DataFusionRExprFunctions_lpad__ffi(c_arg__string, c_arg__padding_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_position__impl(SEXP c_arg__string, SEXP c_arg__substring) {
    SEXP res = savvy_DataFusionRExprFunctions_position__ffi(c_arg__string, c_arg__substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_reverse__impl(SEXP c_arg__arg) {
    SEXP res = savvy_DataFusionRExprFunctions_reverse__ffi(c_arg__arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_right__impl(SEXP c_arg__string, SEXP c_arg__n) {
    SEXP res = savvy_DataFusionRExprFunctions_right__ffi(c_arg__string, c_arg__n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_rpad__impl(SEXP c_arg__string, SEXP c_arg__padding_str) {
    SEXP res = savvy_DataFusionRExprFunctions_rpad__ffi(c_arg__string, c_arg__padding_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_strpos__impl(SEXP c_arg__string, SEXP c_arg__substring) {
    SEXP res = savvy_DataFusionRExprFunctions_strpos__ffi(c_arg__string, c_arg__substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substr__impl(SEXP c_arg__string, SEXP c_arg__position) {
    SEXP res = savvy_DataFusionRExprFunctions_substr__ffi(c_arg__string, c_arg__position);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substr_index__impl(SEXP c_arg__string, SEXP c_arg__delimiter, SEXP c_arg__count) {
    SEXP res = savvy_DataFusionRExprFunctions_substr_index__ffi(c_arg__string, c_arg__delimiter, c_arg__count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substring__impl(SEXP c_arg__string, SEXP c_arg__position, SEXP c_arg__length) {
    SEXP res = savvy_DataFusionRExprFunctions_substring__ffi(c_arg__string, c_arg__position, c_arg__length);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_translate__impl(SEXP c_arg__string, SEXP c_arg__from, SEXP c_arg__to) {
    SEXP res = savvy_DataFusionRExprFunctions_translate__ffi(c_arg__string, c_arg__from, c_arg__to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprs_new__impl(SEXP c_arg__capacity) {
    SEXP res = savvy_DataFusionRExprs_new__ffi(c_arg__capacity);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprs_add_expr__impl(SEXP self__, SEXP c_arg__expr) {
    SEXP res = savvy_DataFusionRExprs_add_expr__ffi(self__, c_arg__expr);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprs_print__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExprs_print__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_new__impl(void) {
    SEXP res = savvy_DataFusionRSessionContext_new__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_create_data_frame__impl(SEXP self__, SEXP c_arg__raw_stream, SEXP c_arg__table_name) {
    SEXP res = savvy_DataFusionRSessionContext_create_data_frame__ffi(self__, c_arg__raw_stream, c_arg__table_name);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_sql__impl(SEXP self__, SEXP c_arg__sql) {
    SEXP res = savvy_DataFusionRSessionContext_sql__ffi(self__, c_arg__sql);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_register_parquet__impl(SEXP self__, SEXP c_arg__name, SEXP c_arg__path, SEXP c_arg__file_extension, SEXP c_arg__parquet_pruning, SEXP c_arg__skip_metadata) {
    SEXP res = savvy_DataFusionRSessionContext_register_parquet__ffi(self__, c_arg__name, c_arg__path, c_arg__file_extension, c_arg__parquet_pruning, c_arg__skip_metadata);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_register_csv__impl(SEXP self__, SEXP c_arg__name, SEXP c_arg__path, SEXP c_arg__has_header, SEXP c_arg__delimiter, SEXP c_arg__quote, SEXP c_arg__escape, SEXP c_arg__schema_infer_max_records, SEXP c_arg__file_extension) {
    SEXP res = savvy_DataFusionRSessionContext_register_csv__ffi(self__, c_arg__name, c_arg__path, c_arg__has_header, c_arg__delimiter, c_arg__quote, c_arg__escape, c_arg__schema_infer_max_records, c_arg__file_extension);
    return handle_result(res);
}

SEXP savvy_RawArrayStream_new_without_init__impl(void) {
    SEXP res = savvy_RawArrayStream_new_without_init__ffi();
    return handle_result(res);
}


static const R_CallMethodDef CallEntries[] = {

    {"savvy_DataFusionRDataFrame_print__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_print__impl, 1},
    {"savvy_DataFusionRDataFrame_logical_plan__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_logical_plan__impl, 1},
    {"savvy_DataFusionRDataFrame_collect__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_collect__impl, 1},
    {"savvy_DataFusionRDataFrame_limit__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_limit__impl, 3},
    {"savvy_DataFusionRDataFrame_select_columns__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_select_columns__impl, 2},
    {"savvy_DataFusionRDataFrame_select__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_select__impl, 2},
    {"savvy_DataFusionRDataFrame_aggregate__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_aggregate__impl, 3},
    {"savvy_DataFusionRDataFrame_dim__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_dim__impl, 1},
    {"savvy_DataFusionRDataFrame_names__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_names__impl, 1},
    {"savvy_DataFusionRExpr_ident__impl", (DL_FUNC) &savvy_DataFusionRExpr_ident__impl, 1},
    {"savvy_DataFusionRExpr_lit__impl", (DL_FUNC) &savvy_DataFusionRExpr_lit__impl, 1},
    {"savvy_DataFusionRExpr_col__impl", (DL_FUNC) &savvy_DataFusionRExpr_col__impl, 1},
    {"savvy_DataFusionRExpr_wildcard__impl", (DL_FUNC) &savvy_DataFusionRExpr_wildcard__impl, 0},
    {"savvy_DataFusionRExpr_print__impl", (DL_FUNC) &savvy_DataFusionRExpr_print__impl, 1},
    {"savvy_DataFusionRExpr_and__impl", (DL_FUNC) &savvy_DataFusionRExpr_and__impl, 2},
    {"savvy_DataFusionRExpr_bitwise_and__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitwise_and__impl, 2},
    {"savvy_DataFusionRExpr_bitwise_or__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitwise_or__impl, 2},
    {"savvy_DataFusionRExpr_bitwise_shift_left__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitwise_shift_left__impl, 2},
    {"savvy_DataFusionRExpr_bitwise_shift_right__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitwise_shift_right__impl, 2},
    {"savvy_DataFusionRExpr_or__impl", (DL_FUNC) &savvy_DataFusionRExpr_or__impl, 2},
    {"savvy_DataFusionRExpr_placeholder__impl", (DL_FUNC) &savvy_DataFusionRExpr_placeholder__impl, 1},
    {"savvy_DataFusionRExpr_add__impl", (DL_FUNC) &savvy_DataFusionRExpr_add__impl, 2},
    {"savvy_DataFusionRExpr_sub__impl", (DL_FUNC) &savvy_DataFusionRExpr_sub__impl, 2},
    {"savvy_DataFusionRExpr_mul__impl", (DL_FUNC) &savvy_DataFusionRExpr_mul__impl, 2},
    {"savvy_DataFusionRExpr_div__impl", (DL_FUNC) &savvy_DataFusionRExpr_div__impl, 2},
    {"savvy_DataFusionRExpr_reminder__impl", (DL_FUNC) &savvy_DataFusionRExpr_reminder__impl, 2},
    {"savvy_DataFusionRExpr_lt__impl", (DL_FUNC) &savvy_DataFusionRExpr_lt__impl, 2},
    {"savvy_DataFusionRExpr_lt_eq__impl", (DL_FUNC) &savvy_DataFusionRExpr_lt_eq__impl, 2},
    {"savvy_DataFusionRExpr_gt__impl", (DL_FUNC) &savvy_DataFusionRExpr_gt__impl, 2},
    {"savvy_DataFusionRExpr_gt_eq__impl", (DL_FUNC) &savvy_DataFusionRExpr_gt_eq__impl, 2},
    {"savvy_DataFusionRExpr_eq__impl", (DL_FUNC) &savvy_DataFusionRExpr_eq__impl, 2},
    {"savvy_DataFusionRExpr_not_eq__impl", (DL_FUNC) &savvy_DataFusionRExpr_not_eq__impl, 2},
    {"savvy_DataFusionRExpr_bitand__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitand__impl, 2},
    {"savvy_DataFusionRExpr_bitor__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitor__impl, 2},
    {"savvy_DataFusionRExpr_bitxor__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitxor__impl, 2},
    {"savvy_DataFusionRExpr_field__impl", (DL_FUNC) &savvy_DataFusionRExpr_field__impl, 2},
    {"savvy_DataFusionRExpr_index__impl", (DL_FUNC) &savvy_DataFusionRExpr_index__impl, 2},
    {"savvy_DataFusionRExpr_range__impl", (DL_FUNC) &savvy_DataFusionRExpr_range__impl, 3},
    {"savvy_DataFusionRExpr_like__impl", (DL_FUNC) &savvy_DataFusionRExpr_like__impl, 2},
    {"savvy_DataFusionRExpr_not_like__impl", (DL_FUNC) &savvy_DataFusionRExpr_not_like__impl, 2},
    {"savvy_DataFusionRExpr_ilike__impl", (DL_FUNC) &savvy_DataFusionRExpr_ilike__impl, 2},
    {"savvy_DataFusionRExpr_not_ilike__impl", (DL_FUNC) &savvy_DataFusionRExpr_not_ilike__impl, 2},
    {"savvy_DataFusionRExpr_between__impl", (DL_FUNC) &savvy_DataFusionRExpr_between__impl, 3},
    {"savvy_DataFusionRExpr_not_between__impl", (DL_FUNC) &savvy_DataFusionRExpr_not_between__impl, 3},
    {"savvy_DataFusionRExpr_alias__impl", (DL_FUNC) &savvy_DataFusionRExpr_alias__impl, 2},
    {"savvy_DataFusionRExpr_in_list__impl", (DL_FUNC) &savvy_DataFusionRExpr_in_list__impl, 3},
    {"savvy_DataFusionRExpr_neg__impl", (DL_FUNC) &savvy_DataFusionRExpr_neg__impl, 1},
    {"savvy_DataFusionRExpr_not__impl", (DL_FUNC) &savvy_DataFusionRExpr_not__impl, 1},
    {"savvy_DataFusionRExpr_is_null__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_null__impl, 1},
    {"savvy_DataFusionRExpr_is_not_null__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_not_null__impl, 1},
    {"savvy_DataFusionRExpr_is_true__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_true__impl, 1},
    {"savvy_DataFusionRExpr_is_not_true__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_not_true__impl, 1},
    {"savvy_DataFusionRExpr_is_false__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_false__impl, 1},
    {"savvy_DataFusionRExpr_is_not_false__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_not_false__impl, 1},
    {"savvy_DataFusionRExpr_bitwise_xor__impl", (DL_FUNC) &savvy_DataFusionRExpr_bitwise_xor__impl, 2},
    {"savvy_DataFusionRExpr_is_unknown__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_unknown__impl, 1},
    {"savvy_DataFusionRExpr_is_not_unknown__impl", (DL_FUNC) &savvy_DataFusionRExpr_is_not_unknown__impl, 1},
    {"savvy_DataFusionRExprFunctions_approx_distinct__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_approx_distinct__impl, 1},
    {"savvy_DataFusionRExprFunctions_approx_percentile_cont__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_approx_percentile_cont__impl, 2},
    {"savvy_DataFusionRExprFunctions_approx_percentile_cont_with_weight__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_approx_percentile_cont_with_weight__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_agg__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_agg__impl, 1},
    {"savvy_DataFusionRExprFunctions_approx_median__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_approx_median__impl, 1},
    {"savvy_DataFusionRExprFunctions_avg__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_avg__impl, 1},
    {"savvy_DataFusionRExprFunctions_count__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_count__impl, 1},
    {"savvy_DataFusionRExprFunctions_count_distinct__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_count_distinct__impl, 1},
    {"savvy_DataFusionRExprFunctions_cube__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cube__impl, 1},
    {"savvy_DataFusionRExprFunctions_max__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_max__impl, 1},
    {"savvy_DataFusionRExprFunctions_median__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_median__impl, 1},
    {"savvy_DataFusionRExprFunctions_min__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_min__impl, 1},
    {"savvy_DataFusionRExprFunctions_rollup__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_rollup__impl, 1},
    {"savvy_DataFusionRExprFunctions_stddev__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_stddev__impl, 1},
    {"savvy_DataFusionRExprFunctions_sum__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sum__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_append__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_append__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_concat__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_concat__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_dims__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_dims__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_distinct__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_distinct__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_element__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_element__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_empty__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_empty__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_except__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_except__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_has__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_has__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_has_all__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_has_all__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_has_any__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_has_any__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_intersect__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_intersect__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_ndims__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_ndims__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_pop_back__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_pop_back__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_pop_front__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_pop_front__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_position__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_position__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_positions__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_positions__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_prepend__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_prepend__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_remove__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_remove__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_remove_all__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_remove_all__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_remove_n__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_remove_n__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_repeat__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_repeat__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_replace__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_replace__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_replace_all__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_replace_all__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_replace_n__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_replace_n__impl, 4},
    {"savvy_DataFusionRExprFunctions_array_resize__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_resize__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_reverse__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_reverse__impl, 1},
    {"savvy_DataFusionRExprFunctions_array_slice__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_slice__impl, 4},
    {"savvy_DataFusionRExprFunctions_array_sort__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_sort__impl, 3},
    {"savvy_DataFusionRExprFunctions_array_to_string__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_to_string__impl, 2},
    {"savvy_DataFusionRExprFunctions_array_union__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_array_union__impl, 2},
    {"savvy_DataFusionRExprFunctions_cardinality__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cardinality__impl, 1},
    {"savvy_DataFusionRExprFunctions_flatten__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_flatten__impl, 1},
    {"savvy_DataFusionRExprFunctions_gen_series__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_gen_series__impl, 3},
    {"savvy_DataFusionRExprFunctions_make_array__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_make_array__impl, 1},
    {"savvy_DataFusionRExprFunctions_range__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_range__impl, 3},
    {"savvy_DataFusionRExprFunctions_string_to_array__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_string_to_array__impl, 3},
    {"savvy_DataFusionRExprFunctions_arrow_cast__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_arrow_cast__impl, 2},
    {"savvy_DataFusionRExprFunctions_arrow_typeof__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_arrow_typeof__impl, 1},
    {"savvy_DataFusionRExprFunctions_coalesce__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_coalesce__impl, 1},
    {"savvy_DataFusionRExprFunctions_get_field__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_get_field__impl, 2},
    {"savvy_DataFusionRExprFunctions_named_struct__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_named_struct__impl, 1},
    {"savvy_DataFusionRExprFunctions_nullif__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_nullif__impl, 2},
    {"savvy_DataFusionRExprFunctions_nvl__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_nvl__impl, 2},
    {"savvy_DataFusionRExprFunctions_nvl2__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_nvl2__impl, 3},
    {"savvy_DataFusionRExprFunctions_digest__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_digest__impl, 2},
    {"savvy_DataFusionRExprFunctions_md5__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_md5__impl, 1},
    {"savvy_DataFusionRExprFunctions_sha224__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sha224__impl, 1},
    {"savvy_DataFusionRExprFunctions_sha256__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sha256__impl, 1},
    {"savvy_DataFusionRExprFunctions_sha384__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sha384__impl, 1},
    {"savvy_DataFusionRExprFunctions_sha512__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sha512__impl, 1},
    {"savvy_DataFusionRExprFunctions_current_date__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_current_date__impl, 0},
    {"savvy_DataFusionRExprFunctions_current_time__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_current_time__impl, 0},
    {"savvy_DataFusionRExprFunctions_date_bin__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_date_bin__impl, 3},
    {"savvy_DataFusionRExprFunctions_date_part__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_date_part__impl, 2},
    {"savvy_DataFusionRExprFunctions_date_trunc__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_date_trunc__impl, 2},
    {"savvy_DataFusionRExprFunctions_from_unixtime__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_from_unixtime__impl, 1},
    {"savvy_DataFusionRExprFunctions_make_date__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_make_date__impl, 3},
    {"savvy_DataFusionRExprFunctions_now__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_now__impl, 0},
    {"savvy_DataFusionRExprFunctions_to_char__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_char__impl, 2},
    {"savvy_DataFusionRExprFunctions_to_date__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_date__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_timestamp__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_timestamp__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_timestamp_micros__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_timestamp_micros__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_timestamp_millis__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_timestamp_millis__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_timestamp_nanos__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_timestamp_nanos__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_timestamp_seconds__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_timestamp_seconds__impl, 1},
    {"savvy_DataFusionRExprFunctions_to_unixtime__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_unixtime__impl, 1},
    {"savvy_DataFusionRExprFunctions_decode__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_decode__impl, 2},
    {"savvy_DataFusionRExprFunctions_encode__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_encode__impl, 2},
    {"savvy_DataFusionRExprFunctions_abs__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_abs__impl, 1},
    {"savvy_DataFusionRExprFunctions_acos__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_acos__impl, 1},
    {"savvy_DataFusionRExprFunctions_acosh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_acosh__impl, 1},
    {"savvy_DataFusionRExprFunctions_asin__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_asin__impl, 1},
    {"savvy_DataFusionRExprFunctions_asinh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_asinh__impl, 1},
    {"savvy_DataFusionRExprFunctions_atan__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_atan__impl, 1},
    {"savvy_DataFusionRExprFunctions_atan2__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_atan2__impl, 2},
    {"savvy_DataFusionRExprFunctions_atanh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_atanh__impl, 1},
    {"savvy_DataFusionRExprFunctions_cbrt__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cbrt__impl, 1},
    {"savvy_DataFusionRExprFunctions_ceil__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_ceil__impl, 1},
    {"savvy_DataFusionRExprFunctions_cos__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cos__impl, 1},
    {"savvy_DataFusionRExprFunctions_cosh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cosh__impl, 1},
    {"savvy_DataFusionRExprFunctions_cot__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_cot__impl, 1},
    {"savvy_DataFusionRExprFunctions_degrees__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_degrees__impl, 1},
    {"savvy_DataFusionRExprFunctions_exp__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_exp__impl, 1},
    {"savvy_DataFusionRExprFunctions_factorial__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_factorial__impl, 1},
    {"savvy_DataFusionRExprFunctions_floor__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_floor__impl, 1},
    {"savvy_DataFusionRExprFunctions_gcd__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_gcd__impl, 2},
    {"savvy_DataFusionRExprFunctions_isnan__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_isnan__impl, 1},
    {"savvy_DataFusionRExprFunctions_iszero__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_iszero__impl, 1},
    {"savvy_DataFusionRExprFunctions_lcm__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_lcm__impl, 2},
    {"savvy_DataFusionRExprFunctions_ln__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_ln__impl, 1},
    {"savvy_DataFusionRExprFunctions_log__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_log__impl, 2},
    {"savvy_DataFusionRExprFunctions_log2__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_log2__impl, 1},
    {"savvy_DataFusionRExprFunctions_log10__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_log10__impl, 1},
    {"savvy_DataFusionRExprFunctions_nanvl__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_nanvl__impl, 2},
    {"savvy_DataFusionRExprFunctions_pi__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_pi__impl, 0},
    {"savvy_DataFusionRExprFunctions_power__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_power__impl, 2},
    {"savvy_DataFusionRExprFunctions_radians__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_radians__impl, 1},
    {"savvy_DataFusionRExprFunctions_random__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_random__impl, 0},
    {"savvy_DataFusionRExprFunctions_round__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_round__impl, 2},
    {"savvy_DataFusionRExprFunctions_signum__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_signum__impl, 1},
    {"savvy_DataFusionRExprFunctions_sin__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sin__impl, 1},
    {"savvy_DataFusionRExprFunctions_sinh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sinh__impl, 1},
    {"savvy_DataFusionRExprFunctions_sqrt__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_sqrt__impl, 1},
    {"savvy_DataFusionRExprFunctions_tan__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_tan__impl, 1},
    {"savvy_DataFusionRExprFunctions_tanh__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_tanh__impl, 1},
    {"savvy_DataFusionRExprFunctions_trunc__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_trunc__impl, 2},
    {"savvy_DataFusionRExprFunctions_regexp_like__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_regexp_like__impl, 2},
    {"savvy_DataFusionRExprFunctions_regexp_match__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_regexp_match__impl, 2},
    {"savvy_DataFusionRExprFunctions_regexp_replace__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_regexp_replace__impl, 4},
    {"savvy_DataFusionRExprFunctions_ascii__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_ascii__impl, 1},
    {"savvy_DataFusionRExprFunctions_bit_length__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_bit_length__impl, 1},
    {"savvy_DataFusionRExprFunctions_btrim__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_btrim__impl, 2},
    {"savvy_DataFusionRExprFunctions_chr__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_chr__impl, 1},
    {"savvy_DataFusionRExprFunctions_concat__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_concat__impl, 1},
    {"savvy_DataFusionRExprFunctions_concat_ws__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_concat_ws__impl, 2},
    {"savvy_DataFusionRExprFunctions_ends_with__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_ends_with__impl, 2},
    {"savvy_DataFusionRExprFunctions_initcap__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_initcap__impl, 1},
    {"savvy_DataFusionRExprFunctions_levenshtein__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_levenshtein__impl, 2},
    {"savvy_DataFusionRExprFunctions_lower__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_lower__impl, 1},
    {"savvy_DataFusionRExprFunctions_ltrim__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_ltrim__impl, 2},
    {"savvy_DataFusionRExprFunctions_octet_length__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_octet_length__impl, 1},
    {"savvy_DataFusionRExprFunctions_overlay__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_overlay__impl, 4},
    {"savvy_DataFusionRExprFunctions_repeat__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_repeat__impl, 2},
    {"savvy_DataFusionRExprFunctions_replace__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_replace__impl, 3},
    {"savvy_DataFusionRExprFunctions_rtrim__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_rtrim__impl, 2},
    {"savvy_DataFusionRExprFunctions_split_part__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_split_part__impl, 3},
    {"savvy_DataFusionRExprFunctions_starts_with__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_starts_with__impl, 2},
    {"savvy_DataFusionRExprFunctions_to_hex__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_to_hex__impl, 1},
    {"savvy_DataFusionRExprFunctions_trim__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_trim__impl, 2},
    {"savvy_DataFusionRExprFunctions_upper__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_upper__impl, 1},
    {"savvy_DataFusionRExprFunctions_uuid__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_uuid__impl, 0},
    {"savvy_DataFusionRExprFunctions_char_length__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_char_length__impl, 1},
    {"savvy_DataFusionRExprFunctions_character_length__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_character_length__impl, 1},
    {"savvy_DataFusionRExprFunctions_find_in_set__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_find_in_set__impl, 2},
    {"savvy_DataFusionRExprFunctions_instr__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_instr__impl, 2},
    {"savvy_DataFusionRExprFunctions_left__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_left__impl, 2},
    {"savvy_DataFusionRExprFunctions_length__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_length__impl, 1},
    {"savvy_DataFusionRExprFunctions_lpad__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_lpad__impl, 2},
    {"savvy_DataFusionRExprFunctions_position__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_position__impl, 2},
    {"savvy_DataFusionRExprFunctions_reverse__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_reverse__impl, 1},
    {"savvy_DataFusionRExprFunctions_right__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_right__impl, 2},
    {"savvy_DataFusionRExprFunctions_rpad__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_rpad__impl, 2},
    {"savvy_DataFusionRExprFunctions_strpos__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_strpos__impl, 2},
    {"savvy_DataFusionRExprFunctions_substr__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_substr__impl, 2},
    {"savvy_DataFusionRExprFunctions_substr_index__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_substr_index__impl, 3},
    {"savvy_DataFusionRExprFunctions_substring__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_substring__impl, 3},
    {"savvy_DataFusionRExprFunctions_translate__impl", (DL_FUNC) &savvy_DataFusionRExprFunctions_translate__impl, 3},
    {"savvy_DataFusionRExprs_new__impl", (DL_FUNC) &savvy_DataFusionRExprs_new__impl, 1},
    {"savvy_DataFusionRExprs_add_expr__impl", (DL_FUNC) &savvy_DataFusionRExprs_add_expr__impl, 2},
    {"savvy_DataFusionRExprs_print__impl", (DL_FUNC) &savvy_DataFusionRExprs_print__impl, 1},
    {"savvy_DataFusionRSessionContext_new__impl", (DL_FUNC) &savvy_DataFusionRSessionContext_new__impl, 0},
    {"savvy_DataFusionRSessionContext_create_data_frame__impl", (DL_FUNC) &savvy_DataFusionRSessionContext_create_data_frame__impl, 3},
    {"savvy_DataFusionRSessionContext_sql__impl", (DL_FUNC) &savvy_DataFusionRSessionContext_sql__impl, 2},
    {"savvy_DataFusionRSessionContext_register_parquet__impl", (DL_FUNC) &savvy_DataFusionRSessionContext_register_parquet__impl, 6},
    {"savvy_DataFusionRSessionContext_register_csv__impl", (DL_FUNC) &savvy_DataFusionRSessionContext_register_csv__impl, 9},
    {"savvy_RawArrayStream_new_without_init__impl", (DL_FUNC) &savvy_RawArrayStream_new_without_init__impl, 0},
    {NULL, NULL, 0}
};

void R_init_datafusionr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);

    // Functions for initialzation, if any.
    savvy_init_runtime__impl(dll);
}
