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
