#' @export
print.RExpr <- function(x, ...) x$print()

#' @export
`+.RExpr` <- function(x, y) x$add(y)
#' @export
`-.RExpr` <- function(x, y) x$sub(y)
#' @export
`*.RExpr` <- function(x, y) x$mul(y)
#' @export
`/.RExpr` <- function(x, y) x$div(y)

datafusion_expr <- function(...) {
  expr_list <- rlang::exprs(...)
  e <- rlang::env_clone(RExpr, parent.frame(2L))
  lapply(expr_list, \(x) rlang::eval_bare(x, e))
}
