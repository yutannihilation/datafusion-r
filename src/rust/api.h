

// methods and associated functions for RDataFrame
SEXP savvy_RDataFrame_print__ffi(SEXP self__);
SEXP savvy_RDataFrame_limit__ffi(SEXP self__, SEXP n, SEXP offset);
SEXP savvy_RDataFrame_select_columns__ffi(SEXP self__, SEXP columns);

// methods and associated functions for RSessionContext
SEXP savvy_RSessionContext_new__ffi(void);
SEXP savvy_RSessionContext_create_data_frame__ffi(SEXP self__, SEXP raw_stream, SEXP table_name);

// methods and associated functions for RawArrayStream
SEXP savvy_RawArrayStream_new_without_init__ffi(void);