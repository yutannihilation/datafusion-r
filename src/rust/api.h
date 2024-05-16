

// methods and associated functions for DataFusionRDataFrame
SEXP savvy_DataFusionRDataFrame_print__ffi(SEXP self__);
SEXP savvy_DataFusionRDataFrame_limit__ffi(SEXP self__, SEXP n, SEXP offset);
SEXP savvy_DataFusionRDataFrame_select_columns__ffi(SEXP self__, SEXP columns);
SEXP savvy_DataFusionRDataFrame_select__ffi(SEXP self__, SEXP exprs);

// methods and associated functions for DataFusionRSessionContext
SEXP savvy_DataFusionRSessionContext_new__ffi(void);
SEXP savvy_DataFusionRSessionContext_create_data_frame__ffi(SEXP self__, SEXP raw_stream, SEXP table_name);

// methods and associated functions for RSessionContextRExpr
SEXP savvy_RSessionContextRExpr_print__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_col__ffi(SEXP x);
SEXP savvy_RSessionContextRExpr_lit__ffi(SEXP x);
SEXP savvy_RSessionContextRExpr_add__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_sub__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_mul__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_div__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_modulo__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_lt__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_lt_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_gt__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_gt_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_not_eq__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_and__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_or__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_bitand__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_bitor__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_bitxor__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_field__ffi(SEXP self__, SEXP name);
SEXP savvy_RSessionContextRExpr_index__ffi(SEXP self__, SEXP key);
SEXP savvy_RSessionContextRExpr_range__ffi(SEXP self__, SEXP start, SEXP stop);
SEXP savvy_RSessionContextRExpr_like__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_not_like__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_ilike__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_not_ilike__ffi(SEXP self__, SEXP rhs);
SEXP savvy_RSessionContextRExpr_between__ffi(SEXP self__, SEXP low, SEXP high);
SEXP savvy_RSessionContextRExpr_not_between__ffi(SEXP self__, SEXP low, SEXP high);
SEXP savvy_RSessionContextRExpr_alias__ffi(SEXP self__, SEXP name);
SEXP savvy_RSessionContextRExpr_in_list__ffi(SEXP self__, SEXP list, SEXP negated);
SEXP savvy_RSessionContextRExpr_neg__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_not__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_null__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_not_null__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_true__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_not_true__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_false__ffi(SEXP self__);
SEXP savvy_RSessionContextRExpr_is_not_false__ffi(SEXP self__);

// methods and associated functions for RSessionContextRExprs
SEXP savvy_RSessionContextRExprs_new__ffi(SEXP capacity);
SEXP savvy_RSessionContextRExprs_add_expr__ffi(SEXP self__, SEXP expr);
SEXP savvy_RSessionContextRExprs_print__ffi(SEXP self__);

// methods and associated functions for RawArrayStream
SEXP savvy_RawArrayStream_new_without_init__ffi(void);