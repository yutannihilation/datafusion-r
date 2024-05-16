

// methods and associated functions for RDataFrame
SEXP savvy_RDataFrame_print__ffi(SEXP self__);
SEXP savvy_RDataFrame_limit__ffi(SEXP self__, SEXP n, SEXP offset);
SEXP savvy_RDataFrame_select_columns__ffi(SEXP self__, SEXP columns);
SEXP savvy_RDataFrame_select__ffi(SEXP self__, SEXP exprs);

// methods and associated functions for RExpr
SEXP savvy_RExpr_print__ffi(SEXP self__);
SEXP savvy_RExpr_col__ffi(SEXP x);
SEXP savvy_RExpr_lit__ffi(SEXP x);
SEXP savvy_RExpr_add__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_sub__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_mul__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_div__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_modulo__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_lt__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_lt_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_gt__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_gt_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_not_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_and__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_or__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_bitand__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_bitor__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_bitxor__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_field__ffi(SEXP self__, SEXP name);
SEXP savvy_RExpr_index__ffi(SEXP self__, SEXP key);
SEXP savvy_RExpr_range__ffi(SEXP self__, SEXP start, SEXP stop);
SEXP savvy_RExpr_like__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_not_like__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_ilike__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_not_ilike__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RExpr_between__ffi(SEXP self__, SEXP low, SEXP high);
SEXP savvy_RExpr_not_between__ffi(SEXP self__, SEXP low, SEXP high);
SEXP savvy_RExpr_alias__ffi(SEXP self__, SEXP name);
SEXP savvy_RExpr_in_list__ffi(SEXP self__, SEXP list, SEXP negated);
SEXP savvy_RExpr_neg__ffi(SEXP self__);
SEXP savvy_RExpr_not__ffi(SEXP self__);
SEXP savvy_RExpr_is_null__ffi(SEXP self__);
SEXP savvy_RExpr_is_not_null__ffi(SEXP self__);
SEXP savvy_RExpr_is_true__ffi(SEXP self__);
SEXP savvy_RExpr_is_not_true__ffi(SEXP self__);
SEXP savvy_RExpr_is_false__ffi(SEXP self__);
SEXP savvy_RExpr_is_not_false__ffi(SEXP self__);

// methods and associated functions for RExprs
SEXP savvy_RExprs_new__ffi(SEXP capacity);
SEXP savvy_RExprs_add_expr__ffi(SEXP self__, SEXP expr);
SEXP savvy_RExprs_print__ffi(SEXP self__);

// methods and associated functions for RSessionContext
SEXP savvy_RSessionContext_new__ffi(void);
SEXP savvy_RSessionContext_create_data_frame__ffi(SEXP self__, SEXP raw_stream, SEXP table_name);

// methods and associated functions for RawArrayStream
SEXP savvy_RawArrayStream_new_without_init__ffi(void);