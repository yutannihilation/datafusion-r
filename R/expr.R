#' @export
print.RExpr <- function(x, ...) x$print()

#' @export
print.RExprs <- function(x, ...) x$print()

#' @export
`+.RExpr` <- function(x, y) {
  if (missing(y)) {
    x
  } else {
    x$add(y)
  }
}
#' @export
`-.RExpr` <- function(x, y) {
  if (missing(y)) {
    x$neg()
  } else {
    x$sub(y)
  }
}
#' @export
`*.RExpr` <- function(x, y) x$mul(y)
#' @export
`/.RExpr` <- function(x, y) x$div(y)
#' @export
`%.RExpr` <- function(x, y) x$modulo(y)
#' @export
`&.RExpr` <- function(x, y) x$bitand(y)
#' @export
`|.RExpr` <- function(x, y) x$bitor(y)
#' @export
`^.RExpr` <- function(x, y) x$bitxor(y)
#' @export
`[.RExpr` <- function(x, y, ...) {
  y_expr <- rlang::enexpr(y)
  if (y_expr[[1L]] == as.name(":")) {
    start <- RExpr$lit(y_expr[[2L]])
    stop  <- RExpr$lit(y_expr[[3L]])
    x$range(start, stop)
  } else {
    x$index(y)
  }
}
#' @export
`[[.RExpr` <- function(x, y, ...) {
  x$field(y)
}

RExpr$`&&` <- function(x, y) x$and(y)
RExpr$`||` <- function(x, y) x$or(y)
RExpr$`<`  <- function(x, y) x$lt(y)
RExpr$`<=` <- function(x, y) x$lt_eq(y)
RExpr$`>`  <- function(x, y) x$gt(y)
RExpr$`>=` <- function(x, y) x$gt_eq(y)
RExpr$`==` <- function(x, y) x$eq(y)
RExpr$`!=` <- function(x, y) x$not_eq(y)
RExpr$`!`  <- function(x)    x$not()

RExpr$`%in%` <- function(x, y) {
  y_expr <- rlang::enexpr(y)

  # convert an expression like `c(lit("a"), ...)` to RExprs
  if (y_expr[[1L]] == as.name("c")) {
    y_expr[[1]] <- as.name("datafusion_exprs")
    y <- rlang::eval_bare(y_expr)
  }

  x$in_list(y, FALSE)
}

datafusion_exprs <- function(...) {
  expr_list <- rlang::exprs(...)
  e <- rlang::env_clone(RExpr, parent.frame(2L))
  out <- RExprs$new(length(expr_list))
  for (expr in expr_list) {
    out$add_expr(rlang::eval_bare(expr, e))
  }
  out
}
