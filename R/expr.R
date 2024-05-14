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

datafusion_exprs <- function(...) {
  expr_list <- rlang::exprs(...)
  e <- rlang::env_clone(RExpr, parent.frame(2L))
  out <- RExprs$new(length(expr_list))
  for (expr in expr_list) {
    out$add_expr(rlang::eval_bare(expr, e))
  }
  out
}
