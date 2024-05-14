#' @export
print.RDataFrame <- function(x, ...) x$print()

#' @export
datafusion_session_context <- function() {
  RSessionContext$new()
}
