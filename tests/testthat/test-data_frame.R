test_that("dataframe", {
  x <- arrow::as_record_batch(mtcars)
  ctx <- datafusion_session_context()
  d <- ctx$create_data_frame(as_array_stream(x), table_name = "mtcars")

  expect_equal(dim(d),  dim(mtcars))
  expect_equal(nrow(d), nrow(mtcars))
  expect_equal(ncol(d), ncol(mtcars))
  expect_equal(names(d), names(mtcars))
})
