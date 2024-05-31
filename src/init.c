
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

SEXP savvy_init_runtime__impl(DllInfo* _dll_info) {
    SEXP res = savvy_init_runtime__ffi(_dll_info);
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

SEXP savvy_DataFusionRDataFrame_limit__impl(SEXP self__, SEXP n, SEXP offset) {
    SEXP res = savvy_DataFusionRDataFrame_limit__ffi(self__, n, offset);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_select_columns__impl(SEXP self__, SEXP columns) {
    SEXP res = savvy_DataFusionRDataFrame_select_columns__ffi(self__, columns);
    return handle_result(res);
}

SEXP savvy_DataFusionRDataFrame_select__impl(SEXP self__, SEXP exprs) {
    SEXP res = savvy_DataFusionRDataFrame_select__ffi(self__, exprs);
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

SEXP savvy_DataFusionRExpr_print__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRExpr_print__ffi(self__);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_col__impl(SEXP x) {
    SEXP res = savvy_DataFusionRExpr_col__ffi(x);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lit__impl(SEXP x) {
    SEXP res = savvy_DataFusionRExpr_lit__ffi(x);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_add__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_add__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_sub__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_sub__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_mul__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_mul__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_div__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_div__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_reminder__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_reminder__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lt__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_lt__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_lt_eq__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_lt_eq__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_gt__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_gt__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_gt_eq__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_gt_eq__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_eq__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_eq__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_eq__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_not_eq__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_and__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_and__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_or__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_or__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitand__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_bitand__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitor__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_bitor__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_bitxor__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_bitxor__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_field__impl(SEXP self__, SEXP name) {
    SEXP res = savvy_DataFusionRExpr_field__ffi(self__, name);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_index__impl(SEXP self__, SEXP key) {
    SEXP res = savvy_DataFusionRExpr_index__ffi(self__, key);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_range__impl(SEXP self__, SEXP start, SEXP stop) {
    SEXP res = savvy_DataFusionRExpr_range__ffi(self__, start, stop);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_like__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_like__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_like__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_not_like__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_ilike__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_ilike__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_ilike__impl(SEXP self__, SEXP rhs) {
    SEXP res = savvy_DataFusionRExpr_not_ilike__ffi(self__, rhs);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_between__impl(SEXP self__, SEXP low, SEXP high) {
    SEXP res = savvy_DataFusionRExpr_between__ffi(self__, low, high);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_not_between__impl(SEXP self__, SEXP low, SEXP high) {
    SEXP res = savvy_DataFusionRExpr_not_between__ffi(self__, low, high);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_alias__impl(SEXP self__, SEXP name) {
    SEXP res = savvy_DataFusionRExpr_alias__ffi(self__, name);
    return handle_result(res);
}

SEXP savvy_DataFusionRExpr_in_list__impl(SEXP self__, SEXP list, SEXP negated) {
    SEXP res = savvy_DataFusionRExpr_in_list__ffi(self__, list, negated);
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

SEXP savvy_DataFusionRExprFunctions_array_append__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_append__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_concat__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_array_concat__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_dims__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_dims__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_distinct__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_distinct__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_element__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_element__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_empty__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_empty__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_except__impl(SEXP first_array, SEXP second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_except__ffi(first_array, second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has__impl(SEXP first_array, SEXP second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has__ffi(first_array, second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has_all__impl(SEXP first_array, SEXP second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has_all__ffi(first_array, second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_has_any__impl(SEXP first_array, SEXP second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_has_any__ffi(first_array, second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_intersect__impl(SEXP first_array, SEXP second_array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_intersect__ffi(first_array, second_array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_ndims__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_ndims__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_pop_back__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_pop_back__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_pop_front__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_pop_front__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_position__impl(SEXP array, SEXP element, SEXP index) {
    SEXP res = savvy_DataFusionRExprFunctions_array_position__ffi(array, element, index);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_positions__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_positions__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_prepend__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_prepend__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove_all__impl(SEXP array, SEXP element) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove_all__ffi(array, element);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_remove_n__impl(SEXP array, SEXP element, SEXP max) {
    SEXP res = savvy_DataFusionRExprFunctions_array_remove_n__ffi(array, element, max);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_repeat__impl(SEXP array, SEXP count) {
    SEXP res = savvy_DataFusionRExprFunctions_array_repeat__ffi(array, count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace__impl(SEXP array, SEXP from, SEXP to) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace__ffi(array, from, to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace_all__impl(SEXP array, SEXP from, SEXP to) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace_all__ffi(array, from, to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_replace_n__impl(SEXP array, SEXP from, SEXP to, SEXP max) {
    SEXP res = savvy_DataFusionRExprFunctions_array_replace_n__ffi(array, from, to, max);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_resize__impl(SEXP array, SEXP size, SEXP value) {
    SEXP res = savvy_DataFusionRExprFunctions_array_resize__ffi(array, size, value);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_reverse__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_array_reverse__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_slice__impl(SEXP array, SEXP begin, SEXP end, SEXP stride) {
    SEXP res = savvy_DataFusionRExprFunctions_array_slice__ffi(array, begin, end, stride);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_sort__impl(SEXP array, SEXP desc, SEXP null_first) {
    SEXP res = savvy_DataFusionRExprFunctions_array_sort__ffi(array, desc, null_first);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_to_string__impl(SEXP array, SEXP delimiter) {
    SEXP res = savvy_DataFusionRExprFunctions_array_to_string__ffi(array, delimiter);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_array_union__impl(SEXP array1, SEXP array2) {
    SEXP res = savvy_DataFusionRExprFunctions_array_union__ffi(array1, array2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cardinality__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_cardinality__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_flatten__impl(SEXP array) {
    SEXP res = savvy_DataFusionRExprFunctions_flatten__ffi(array);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_gen_series__impl(SEXP start, SEXP stop, SEXP step) {
    SEXP res = savvy_DataFusionRExprFunctions_gen_series__ffi(start, stop, step);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_make_array__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_make_array__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_range__impl(SEXP start, SEXP stop, SEXP step) {
    SEXP res = savvy_DataFusionRExprFunctions_range__ffi(start, stop, step);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_string_to_array__impl(SEXP array, SEXP delimiter, SEXP null_string) {
    SEXP res = savvy_DataFusionRExprFunctions_string_to_array__ffi(array, delimiter, null_string);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_arrow_cast__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_arrow_cast__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_arrow_typeof__impl(SEXP arg1) {
    SEXP res = savvy_DataFusionRExprFunctions_arrow_typeof__ffi(arg1);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_coalesce__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_coalesce__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_get_field__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_get_field__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_named_struct__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_named_struct__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nullif__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_nullif__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nvl__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_nvl__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nvl2__impl(SEXP arg1, SEXP arg2, SEXP arg3) {
    SEXP res = savvy_DataFusionRExprFunctions_nvl2__ffi(arg1, arg2, arg3);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_digest__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_digest__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_md5__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_md5__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha224__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha224__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha256__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha256__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha384__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha384__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sha512__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_sha512__ffi(arg);
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

SEXP savvy_DataFusionRExprFunctions_date_bin__impl(SEXP stride, SEXP source, SEXP origin) {
    SEXP res = savvy_DataFusionRExprFunctions_date_bin__ffi(stride, source, origin);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_date_part__impl(SEXP part, SEXP date) {
    SEXP res = savvy_DataFusionRExprFunctions_date_part__ffi(part, date);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_date_trunc__impl(SEXP part, SEXP date) {
    SEXP res = savvy_DataFusionRExprFunctions_date_trunc__ffi(part, date);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_from_unixtime__impl(SEXP unixtime) {
    SEXP res = savvy_DataFusionRExprFunctions_from_unixtime__ffi(unixtime);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_make_date__impl(SEXP year, SEXP month, SEXP day) {
    SEXP res = savvy_DataFusionRExprFunctions_make_date__ffi(year, month, day);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_now__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_now__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_char__impl(SEXP datetime, SEXP format) {
    SEXP res = savvy_DataFusionRExprFunctions_to_char__ffi(datetime, format);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_date__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_date__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_micros__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_micros__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_millis__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_millis__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_nanos__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_nanos__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_timestamp_seconds__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_timestamp_seconds__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_unixtime__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_to_unixtime__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_decode__impl(SEXP input, SEXP encoding) {
    SEXP res = savvy_DataFusionRExprFunctions_decode__ffi(input, encoding);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_encode__impl(SEXP input, SEXP encoding) {
    SEXP res = savvy_DataFusionRExprFunctions_encode__ffi(input, encoding);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_abs__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_abs__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_acos__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_acos__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_acosh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_acosh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_asin__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_asin__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_asinh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_asinh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atan__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_atan__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atan2__impl(SEXP x, SEXP y) {
    SEXP res = savvy_DataFusionRExprFunctions_atan2__ffi(x, y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_atanh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_atanh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cbrt__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_cbrt__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ceil__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_ceil__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cos__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_cos__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cosh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_cosh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_cot__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_cot__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_degrees__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_degrees__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_exp__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_exp__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_factorial__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_factorial__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_floor__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_floor__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_gcd__impl(SEXP x, SEXP y) {
    SEXP res = savvy_DataFusionRExprFunctions_gcd__ffi(x, y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_isnan__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_isnan__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_iszero__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_iszero__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lcm__impl(SEXP x, SEXP y) {
    SEXP res = savvy_DataFusionRExprFunctions_lcm__ffi(x, y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ln__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_ln__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log__impl(SEXP base, SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_log__ffi(base, num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log2__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_log2__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_log10__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_log10__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_nanvl__impl(SEXP x, SEXP y) {
    SEXP res = savvy_DataFusionRExprFunctions_nanvl__ffi(x, y);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_pi__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_pi__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_power__impl(SEXP base, SEXP exponent) {
    SEXP res = savvy_DataFusionRExprFunctions_power__ffi(base, exponent);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_radians__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_radians__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_random__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_random__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_round__impl(SEXP num, SEXP decimal_place) {
    SEXP res = savvy_DataFusionRExprFunctions_round__ffi(num, decimal_place);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_signum__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_signum__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sin__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_sin__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sinh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_sinh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_sqrt__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_sqrt__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_tan__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_tan__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_tanh__impl(SEXP num) {
    SEXP res = savvy_DataFusionRExprFunctions_tanh__ffi(num);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_trunc__impl(SEXP num, SEXP decimal_place) {
    SEXP res = savvy_DataFusionRExprFunctions_trunc__ffi(num, decimal_place);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_like__impl(SEXP string, SEXP pattern) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_like__ffi(string, pattern);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_match__impl(SEXP string, SEXP pattern) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_match__ffi(string, pattern);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_regexp_replace__impl(SEXP string, SEXP pattern, SEXP replacement, SEXP flags) {
    SEXP res = savvy_DataFusionRExprFunctions_regexp_replace__ffi(string, pattern, replacement, flags);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ascii__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_ascii__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_bit_length__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_bit_length__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_btrim__impl(SEXP string, SEXP trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_btrim__ffi(string, trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_chr__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_chr__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_concat__impl(SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_concat__ffi(args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_concat_ws__impl(SEXP delimiter, SEXP args) {
    SEXP res = savvy_DataFusionRExprFunctions_concat_ws__ffi(delimiter, args);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ends_with__impl(SEXP string, SEXP suffix) {
    SEXP res = savvy_DataFusionRExprFunctions_ends_with__ffi(string, suffix);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_initcap__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_initcap__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_levenshtein__impl(SEXP arg1, SEXP arg2) {
    SEXP res = savvy_DataFusionRExprFunctions_levenshtein__ffi(arg1, arg2);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lower__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_lower__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_ltrim__impl(SEXP string, SEXP trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_ltrim__ffi(string, trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_octet_length__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_octet_length__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_overlay__impl(SEXP string, SEXP replacement, SEXP pos, SEXP count) {
    SEXP res = savvy_DataFusionRExprFunctions_overlay__ffi(string, replacement, pos, count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_repeat__impl(SEXP string, SEXP n) {
    SEXP res = savvy_DataFusionRExprFunctions_repeat__ffi(string, n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_replace__impl(SEXP string, SEXP from, SEXP to) {
    SEXP res = savvy_DataFusionRExprFunctions_replace__ffi(string, from, to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_rtrim__impl(SEXP string, SEXP trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_rtrim__ffi(string, trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_split_part__impl(SEXP string, SEXP delimiter, SEXP index) {
    SEXP res = savvy_DataFusionRExprFunctions_split_part__ffi(string, delimiter, index);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_starts_with__impl(SEXP string, SEXP prefix) {
    SEXP res = savvy_DataFusionRExprFunctions_starts_with__ffi(string, prefix);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_to_hex__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_to_hex__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_trim__impl(SEXP string, SEXP trim_str) {
    SEXP res = savvy_DataFusionRExprFunctions_trim__ffi(string, trim_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_upper__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_upper__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_uuid__impl(void) {
    SEXP res = savvy_DataFusionRExprFunctions_uuid__ffi();
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_char_length__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_char_length__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_character_length__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_character_length__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_find_in_set__impl(SEXP string, SEXP strlist) {
    SEXP res = savvy_DataFusionRExprFunctions_find_in_set__ffi(string, strlist);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_instr__impl(SEXP string, SEXP substring) {
    SEXP res = savvy_DataFusionRExprFunctions_instr__ffi(string, substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_left__impl(SEXP string, SEXP n) {
    SEXP res = savvy_DataFusionRExprFunctions_left__ffi(string, n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_length__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_length__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_lpad__impl(SEXP string, SEXP padding_str) {
    SEXP res = savvy_DataFusionRExprFunctions_lpad__ffi(string, padding_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_position__impl(SEXP string, SEXP substring) {
    SEXP res = savvy_DataFusionRExprFunctions_position__ffi(string, substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_reverse__impl(SEXP arg) {
    SEXP res = savvy_DataFusionRExprFunctions_reverse__ffi(arg);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_right__impl(SEXP string, SEXP n) {
    SEXP res = savvy_DataFusionRExprFunctions_right__ffi(string, n);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_rpad__impl(SEXP string, SEXP padding_str) {
    SEXP res = savvy_DataFusionRExprFunctions_rpad__ffi(string, padding_str);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_strpos__impl(SEXP string, SEXP substring) {
    SEXP res = savvy_DataFusionRExprFunctions_strpos__ffi(string, substring);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substr__impl(SEXP string, SEXP position) {
    SEXP res = savvy_DataFusionRExprFunctions_substr__ffi(string, position);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substr_index__impl(SEXP string, SEXP delimiter, SEXP count) {
    SEXP res = savvy_DataFusionRExprFunctions_substr_index__ffi(string, delimiter, count);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_substring__impl(SEXP string, SEXP position, SEXP length) {
    SEXP res = savvy_DataFusionRExprFunctions_substring__ffi(string, position, length);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprFunctions_translate__impl(SEXP string, SEXP from, SEXP to) {
    SEXP res = savvy_DataFusionRExprFunctions_translate__ffi(string, from, to);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprs_new__impl(SEXP capacity) {
    SEXP res = savvy_DataFusionRExprs_new__ffi(capacity);
    return handle_result(res);
}

SEXP savvy_DataFusionRExprs_add_expr__impl(SEXP self__, SEXP expr) {
    SEXP res = savvy_DataFusionRExprs_add_expr__ffi(self__, expr);
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

SEXP savvy_DataFusionRSessionContext_create_data_frame__impl(SEXP self__, SEXP raw_stream, SEXP table_name) {
    SEXP res = savvy_DataFusionRSessionContext_create_data_frame__ffi(self__, raw_stream, table_name);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_sql__impl(SEXP self__, SEXP sql) {
    SEXP res = savvy_DataFusionRSessionContext_sql__ffi(self__, sql);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_register_parquet__impl(SEXP self__, SEXP name, SEXP path, SEXP file_extension, SEXP parquet_pruning, SEXP skip_metadata) {
    SEXP res = savvy_DataFusionRSessionContext_register_parquet__ffi(self__, name, path, file_extension, parquet_pruning, skip_metadata);
    return handle_result(res);
}

SEXP savvy_DataFusionRSessionContext_register_csv__impl(SEXP self__, SEXP name, SEXP path, SEXP has_header, SEXP delimiter, SEXP quote, SEXP escape, SEXP schema_infer_max_records, SEXP file_extension) {
    SEXP res = savvy_DataFusionRSessionContext_register_csv__ffi(self__, name, path, has_header, delimiter, quote, escape, schema_infer_max_records, file_extension);
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
    {"savvy_DataFusionRDataFrame_dim__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_dim__impl, 1},
    {"savvy_DataFusionRDataFrame_names__impl", (DL_FUNC) &savvy_DataFusionRDataFrame_names__impl, 1},
    {"savvy_DataFusionRExpr_print__impl", (DL_FUNC) &savvy_DataFusionRExpr_print__impl, 1},
    {"savvy_DataFusionRExpr_col__impl", (DL_FUNC) &savvy_DataFusionRExpr_col__impl, 1},
    {"savvy_DataFusionRExpr_lit__impl", (DL_FUNC) &savvy_DataFusionRExpr_lit__impl, 1},
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
    {"savvy_DataFusionRExpr_and__impl", (DL_FUNC) &savvy_DataFusionRExpr_and__impl, 2},
    {"savvy_DataFusionRExpr_or__impl", (DL_FUNC) &savvy_DataFusionRExpr_or__impl, 2},
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
