test_that("expressions", {
  e <- function(...) {
    capture.output(print(datafusion_exprs(...)))
  }

  expect_equal(e(col("foo")), "foo")
  expect_equal(e(col("foo")$alias("bar")), "foo AS bar")

  expect_equal(e(lit(1)), "Float64(1)")
  expect_equal(e(lit(1L)), "Int32(1)")
  expect_equal(e(lit(TRUE)), "Boolean(true)")
  expect_equal(e(lit("a")), 'Utf8("a")')

  # unary
  expect_equal(e(+col("foo")), "foo")
  expect_equal(e(-col("foo")), "(- foo)")
  expect_equal(e(!col("foo")), "NOT foo")
  expect_equal(e(col("foo")$is_null()), "foo IS NULL")
  expect_equal(e(col("foo")$is_not_null()), "foo IS NOT NULL")
  expect_equal(e(col("foo")$is_true()), "foo IS TRUE")
  expect_equal(e(col("foo")$is_false()), "foo IS FALSE")

  # binary
  expect_equal(e(col("foo") +  col("bar")), "foo + bar" )
  expect_equal(e(col("foo") -  col("bar")), "foo - bar" )
  expect_equal(e(col("foo") *  col("bar")), "foo * bar" )
  expect_equal(e(col("foo") /  col("bar")), "foo / bar" )
  # TODO
  expect_equal(e(col("foo") %% col("bar")), "foo % bar" )
  expect_equal(e(col("foo") == col("bar")), "foo = bar" )
  expect_equal(e(col("foo") != col("bar")), "foo != bar")
  expect_equal(e(col("foo") <  col("bar")), "foo < bar" )
  expect_equal(e(col("foo") <= col("bar")), "foo <= bar")
  expect_equal(e(col("foo") >  col("bar")), "foo > bar" )
  expect_equal(e(col("foo") >= col("bar")), "foo >= bar")
  expect_equal(e(col("foo") &  col("bar")), "foo & bar" )
  expect_equal(e(col("foo") |  col("bar")), "foo | bar" )
  expect_equal(e(col("foo") ^  col("bar")), "foo BIT_XOR bar")
  expect_equal(e(col("foo") && col("bar")), "foo AND bar")
  expect_equal(e(col("foo") || col("bar")), "foo OR bar")

  expect_equal(e(col("foo")[["a"]]), '(foo)[a]')            # field
  expect_equal(e(col("foo")[lit("a")]), '(foo)[Utf8("a")]') # index
  expect_equal(e(col("foo")[1:3]), '(foo)[Int32(1):Int32(3):Int64(1)]') # range

  # % needs to be escaped
  expect_equal(e(col("foo")$like(lit("prefix_%"))),      'foo LIKE Utf8("prefix_%")')
  expect_equal(e(col("foo")$not_like(lit("prefix_%"))),  'foo NOT LIKE Utf8("prefix_%")')
  expect_equal(e(col("foo")$ilike(lit("prefix_%"))),     'foo ILIKE Utf8("prefix_%")')
  expect_equal(e(col("foo")$not_ilike(lit("prefix_%"))), 'foo NOT ILIKE Utf8("prefix_%")')

  expect_equal(e(col("foo")$between(lit(0), lit(100))),     'foo BETWEEN Float64(0) AND Float64(100)')
  expect_equal(e(col("foo")$not_between(lit(0), lit(100))), 'foo NOT BETWEEN Float64(0) AND Float64(100)')

  expect_equal(e(col("foo") %in% c(lit("a"), lit("b"), lit("c"))), 'foo IN ([Utf8("a"), Utf8("b"), Utf8("c")])')
})
