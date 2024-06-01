#' @export
print.DataFusionRDataFrame <- function(x, ...) x$print()

#' @export
dim.DataFusionRDataFrame <- function(x, ...) x$dim()

#' @export
names.DataFusionRDataFrame <- function(x, ...) x$names()

#' @export
datafusion_select_columns <- function(x, ...) {
  x$select_columns(c(...))
}

#' @export
datafusion_limit <- function(x, n, offset = 0L) {
  n <- as.integer(n)
  offset <- as.integer(offset)

  x$limit(n, offset)
}

#' @export
datafusion_select <- function(x, ...) {
  expr_list <- datafusion_exprs(...)
  x$select(expr_list)
}

#' @export
datafusion_aggregate <- function(x, group_expr, aggr_expr) {
  x$aggregate(group_expr, aggr_expr)
}
