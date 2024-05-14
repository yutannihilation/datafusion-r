#' Convert To 'Arrow C Stream Interface'.
#'
#' @param x An R object to convert to an Arrow C stream interface.
#' @seealso <https://arrow.apache.org/docs/format/CStreamInterface.html>
#'
#' @export
as_array_stream <- function(x, ...) {
  UseMethod("as_array_stream")
}

#' @export
as_array_stream.default <- function(x, ...) {
  x_reader <- arrow::as_record_batch_reader(x, ...)
  as_array_stream.RecordBatchReader(x_reader)
}

#' @export
as_array_stream.RecordBatchReader <- function(x, ...) {
  out <- RawArrayStream$new_without_init()
  x$export_to_c(out$.ptr)
  out
}
