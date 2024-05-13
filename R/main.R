#' @export
print.RDataFrame <- function(x, ...) x$print()

#' @export
session_context <- function() {
  RSessionContext$new()
}
