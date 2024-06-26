#' Convert To 'Arrow C Stream Interface'.
#'
#' @param x An R object to convert to an Arrow C stream interface.
#' @param ... Additional arguments passed to [`arrow::as_record_batch_reader()`].
#' @seealso <https://arrow.apache.org/docs/format/CStreamInterface.html>
#'
#' @export
as_array_stream <- function(x, ...) {
  UseMethod("as_array_stream")
}

#' @export
as_array_stream.default <- function(x, ...) {
  rlang::check_installed("arrow")

  x_reader <- arrow::as_record_batch_reader(x, ...)
  as_array_stream.RecordBatchReader(x_reader)
}

#' @export
as_array_stream.RecordBatchReader <- function(x, ...) {
  out <- RawArrayStream$new_without_init()
  x$export_to_c(out$.ptr)
  out
}

# TODO
DataFusionRDataFrame_collect <- function(self) {
  function() {
    x <- .Call(savvy_DataFusionRDataFrame_collect__impl, self)
    class(x) <- "nanoarrow_array_stream"
    nanoarrow:::as.data.frame.nanoarrow_array_stream(x)
  }
}

#' @export
datafusion_collect <- function(x) {
  x$collect()
}
