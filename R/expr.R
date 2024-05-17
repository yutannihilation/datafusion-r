#' @export
print.DataFusionRExpr <- function(x, ...) x$print()

#' @export
print.DataFusionRExprs <- function(x, ...) x$print()

#' @export
`+.DataFusionRExpr` <- function(x, y) {
  if (missing(y)) {
    x
  } else {
    x$add(y)
  }
}
#' @export
`-.DataFusionRExpr` <- function(x, y) {
  if (missing(y)) {
    x$neg()
  } else {
    x$sub(y)
  }
}
#' @export
`*.DataFusionRExpr` <- function(x, y) x$mul(y)
#' @export
`/.DataFusionRExpr` <- function(x, y) x$div(y)
#' @export
`%%.DataFusionRExpr` <- function(x, y) x$modulo(y)
#' @export
`&.DataFusionRExpr` <- function(x, y) x$bitand(y)
#' @export
`|.DataFusionRExpr` <- function(x, y) x$bitor(y)
#' @export
`^.DataFusionRExpr` <- function(x, y) x$bitxor(y)
#' @export
`[.DataFusionRExpr` <- function(x, y, ...) {
  y_expr <- rlang::enexpr(y)
  if (y_expr[[1L]] == as.name(":")) {
    start <- DataFusionRExpr$lit(as.integer(y_expr[[2L]]))
    stop  <- DataFusionRExpr$lit(as.integer(y_expr[[3L]]))
    x$range(start, stop)
  } else {
    x$index(y)
  }
}
#' @export
`[[.DataFusionRExpr` <- function(x, y, ...) {
  x$field(y)
}

DataFusionRExpr$`&&` <- function(x, y) x$and(y)
DataFusionRExpr$`||` <- function(x, y) x$or(y)
DataFusionRExpr$`<`  <- function(x, y) x$lt(y)
DataFusionRExpr$`<=` <- function(x, y) x$lt_eq(y)
DataFusionRExpr$`>`  <- function(x, y) x$gt(y)
DataFusionRExpr$`>=` <- function(x, y) x$gt_eq(y)
DataFusionRExpr$`==` <- function(x, y) x$eq(y)
DataFusionRExpr$`!=` <- function(x, y) x$not_eq(y)
DataFusionRExpr$`!`  <- function(x)    x$not()

# TODO: can I always overwrite `c`?
DataFusionRExpr$`%in%` <- function(x, y) {
  y_expr <- rlang::enexpr(y)

  # convert an expression like `c(lit("a"), ...)` to DataFusionRExprs
  if (y_expr[[1L]] == as.name("c")) {
    y_expr[[1]] <- as.name("datafusion_exprs")
    y <- rlang::eval_bare(y_expr)
  }

  x$in_list(y, FALSE)
}

datafusion_exprs <- function(...) {
  expr_list <- rlang::exprs(...)
  e <- rlang::env_clone(DataFusionRExpr, parent.frame(2L))
  out <- DataFusionRExprs$new(length(expr_list))
  for (expr in expr_list) {
    out$add_expr(rlang::eval_bare(expr, e))
  }
  out
}
