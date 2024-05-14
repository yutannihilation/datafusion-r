

// methods and associated functions for RDataFrame
SEXP savvy_RDataFrame_print__ffi(SEXP self__);
SEXP savvy_RDataFrame_limit__ffi(SEXP self__, SEXP n, SEXP offset);
SEXP savvy_RDataFrame_select_columns__ffi(SEXP self__, SEXP columns);
SEXP savvy_RDataFrame_select__ffi(SEXP self__, SEXP exprs);

// methods and associated functions for RExpr
SEXP savvy_RExpr_print__ffi(SEXP self__);
SEXP savvy_RExpr_col__ffi(SEXP x);
SEXP savvy_RExpr_add__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_sub__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_mul__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_div__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_alias__ffi(SEXP self__, SEXP name);

// methods and associated functions for RExprs
SEXP savvy_RExprs_new__ffi(SEXP capacity);
SEXP savvy_RExprs_add_expr__ffi(SEXP self__, SEXP expr);

// methods and associated functions for RSessionContext
SEXP savvy_RSessionContext_new__ffi(void);
SEXP savvy_RSessionContext_create_data_frame__ffi(SEXP self__, SEXP raw_stream, SEXP table_name);

// methods and associated functions for RawArrayStream
SEXP savvy_RawArrayStream_new_without_init__ffi(void);