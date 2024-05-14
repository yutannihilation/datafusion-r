
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


SEXP savvy_RDataFrame_print__impl(SEXP self__) {
    SEXP res = savvy_RDataFrame_print__ffi(self__);
    return handle_result(res);
}

SEXP savvy_RDataFrame_limit__impl(SEXP self__, SEXP n, SEXP offset) {
    SEXP res = savvy_RDataFrame_limit__ffi(self__, n, offset);
    return handle_result(res);
}

SEXP savvy_RDataFrame_select_columns__impl(SEXP self__, SEXP columns) {
    SEXP res = savvy_RDataFrame_select_columns__ffi(self__, columns);
    return handle_result(res);
}

SEXP savvy_RSessionContext_new__impl(void) {
    SEXP res = savvy_RSessionContext_new__ffi();
    return handle_result(res);
}

SEXP savvy_RSessionContext_create_data_frame__impl(SEXP self__, SEXP raw_stream, SEXP table_name) {
    SEXP res = savvy_RSessionContext_create_data_frame__ffi(self__, raw_stream, table_name);
    return handle_result(res);
}

SEXP savvy_RawArrayStream_new_without_init__impl(void) {
    SEXP res = savvy_RawArrayStream_new_without_init__ffi();
    return handle_result(res);
}


static const R_CallMethodDef CallEntries[] = {

    {"savvy_RDataFrame_print__impl", (DL_FUNC) &savvy_RDataFrame_print__impl, 1},
    {"savvy_RDataFrame_limit__impl", (DL_FUNC) &savvy_RDataFrame_limit__impl, 3},
    {"savvy_RDataFrame_select_columns__impl", (DL_FUNC) &savvy_RDataFrame_select_columns__impl, 2},
    {"savvy_RSessionContext_new__impl", (DL_FUNC) &savvy_RSessionContext_new__impl, 0},
    {"savvy_RSessionContext_create_data_frame__impl", (DL_FUNC) &savvy_RSessionContext_create_data_frame__impl, 3},
    {"savvy_RawArrayStream_new_without_init__impl", (DL_FUNC) &savvy_RawArrayStream_new_without_init__impl, 0},
    {NULL, NULL, 0}
};

void R_init_datafusionr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);

    // Functions for initialzation, if any.

}
