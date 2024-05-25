
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


SEXP savvy_DataFusionRDataFrame_print__impl(SEXP self__) {
    SEXP res = savvy_DataFusionRDataFrame_print__ffi(self__);
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

}
