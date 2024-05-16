#' @export
print.RSessionContextRExpr <- function(x, ...) x$print()

#' @export
print.RSessionContextRExprs <- function(x, ...) x$print()

#' @export
`+.RSessionContextRExpr` <- function(x, y) {
  if (missing(y)) {
    x
  } else {
    x$add(y)
  }
}
#' @export
`-.RSessionContextRExpr` <- function(x, y) {
  if (missing(y)) {
    x$neg()
  } else {
    x$sub(y)
  }
}
#' @export
`*.RSessionContextRExpr` <- function(x, y) x$mul(y)
#' @export
`/.RSessionContextRExpr` <- function(x, y) x$div(y)
#' @export
`%.RSessionContextRExpr` <- function(x, y) x$modulo(y)
#' @export
`&.RSessionContextRExpr` <- function(x, y) x$bitand(y)
#' @export
`|.RSessionContextRExpr` <- function(x, y) x$bitor(y)
#' @export
`^.RSessionContextRExpr` <- function(x, y) x$bitxor(y)
#' @export
`[.RSessionContextRExpr` <- function(x, y, ...) {
  y_expr <- rlang::enexpr(y)
  if (y_expr[[1L]] == as.name(":")) {
    start <- RSessionContextRExpr$lit(y_expr[[2L]])
    stop  <- RSessionContextRExpr$lit(y_expr[[3L]])
    x$range(start, stop)
  } else {
    x$index(y)
  }
}
#' @export
`[[.RSessionContextRExpr` <- function(x, y, ...) {
  x$field(y)
}

RSessionContextRExpr$`&&` <- function(x, y) x$and(y)
RSessionContextRExpr$`||` <- function(x, y) x$or(y)
RSessionContextRExpr$`<`  <- function(x, y) x$lt(y)
RSessionContextRExpr$`<=` <- function(x, y) x$lt_eq(y)
RSessionContextRExpr$`>`  <- function(x, y) x$gt(y)
RSessionContextRExpr$`>=` <- function(x, y) x$gt_eq(y)
RSessionContextRExpr$`==` <- function(x, y) x$eq(y)
RSessionContextRExpr$`!=` <- function(x, y) x$not_eq(y)
RSessionContextRExpr$`!`  <- function(x)    x$not()

RSessionContextRExpr$`%in%` <- function(x, y) {
  y_expr <- rlang::enexpr(y)

  # convert an expression like `c(lit("a"), ...)` to RSessionContextRExprs
  if (y_expr[[1L]] == as.name("c")) {
    y_expr[[1]] <- as.name("datafusion_exprs")
    y <- rlang::eval_bare(y_expr)
  }

  x$in_list(y, FALSE)
}

datafusion_exprs <- function(...) {
  expr_list <- rlang::exprs(...)
  e <- rlang::env_clone(RSessionContextRExpr, parent.frame(2L))
  out <- RSessionContextRExprs$new(length(expr_list))
  for (expr in expr_list) {
    out$add_expr(rlang::eval_bare(expr, e))
  }
  out
}
