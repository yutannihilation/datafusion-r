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

test_that("function expressions", {
  e <- function(...) {
    capture.output(print(datafusion_exprs(...)))
  }

  # core
  expect_equal(e(arrow_cast(col("foo"), lit("Utf8"))),                  'arrow_cast(foo, Utf8("Utf8"))')
  expect_equal(e(arrow_typeof(col("foo"))),                             "arrow_typeof(foo)")
  expect_equal(e(coalesce(col("foo"), col("bar"), lit("default"))),     'coalesce(foo, bar, Utf8("default"))')
  expect_equal(e(get_field(col("foo"), col("bar"))),                    "get_field(foo, bar)")
  expect_equal(e(named_struct(lit("A"), col("a"), lit("B"), col("b"))), 'named_struct(Utf8("A"), a, Utf8("B"), b)')
  expect_equal(e(nullif(col("foo"), lit("NULL"))),                      'nullif(foo, Utf8("NULL"))')
  expect_equal(e(nvl(col("foo"), lit("default"))),                      'nvl(foo, Utf8("default"))')
  expect_equal(e(nvl2(col("foo"), col("bar"), lit("default"))),         'nvl2(foo, bar, Utf8("default"))')

  # math
  expect_equal(e(abs(col("foo"))),                   "abs(foo)")
  expect_equal(e(acos(col("foo"))),                  "acos(foo)")
  expect_equal(e(acosh(col("foo"))),                 "acosh(foo)")
  expect_equal(e(asin(col("foo"))),                  "asin(foo)")
  expect_equal(e(asinh(col("foo"))),                 "asinh(foo)")
  expect_equal(e(atan(col("foo"))),                  "atan(foo)")
  expect_equal(e(atan2(col("foo"), col("bar"))),     "atan2(foo, bar)")
  expect_equal(e(atanh(col("foo"))),                 "atanh(foo)")
  expect_equal(e(cbrt(col("foo"))),                  "cbrt(foo)")
  expect_equal(e(ceil(col("foo"))),                  "ceil(foo)")
  expect_equal(e(cos(col("foo"))),                   "cos(foo)")
  expect_equal(e(cosh(col("foo"))),                  "cosh(foo)")
  expect_equal(e(cot(col("foo"))),                   "cot(foo)")
  expect_equal(e(degrees(col("foo"))),               "degrees(foo)")
  expect_equal(e(exp(col("foo"))),                   "exp(foo)")
  expect_equal(e(factorial(col("foo"))),             "factorial(foo)")
  expect_equal(e(floor(col("foo"))),                 "floor(foo)")
  expect_equal(e(gcd(col("foo"), col("bar"))),       "gcd(foo, bar)")
  expect_equal(e(isnan(col("foo"))),                 "isnan(foo)")
  expect_equal(e(iszero(col("foo"))),                "iszero(foo)")
  expect_equal(e(lcm(col("foo"), col("bar"))),       "lcm(foo, bar)")
  expect_equal(e(ln(col("foo"))),                    "ln(foo)")
  expect_equal(e(log(lit(16L), col("foo"))),         "log(Int32(16), foo)")
  expect_equal(e(log2(col("foo"))),                  "log2(foo)")
  expect_equal(e(log10(col("foo"))),                 "log10(foo)")
  expect_equal(e(nanvl(col("foo"), col("bar"))),     "nanvl(foo, bar)")
  expect_equal(e(pi()),                              "pi()")
  expect_equal(e(power(col("foo"), lit(2.5))),       "power(foo, Float64(2.5))")
  expect_equal(e(radians(col("foo"))),               "radians(foo)")
  expect_equal(e(random()),                          "random()")
  expect_equal(e(round(col("foo"))),                 "round(foo)")
  expect_equal(e(round(col("foo"), lit(2L))),        "round(foo, Int32(2))")
  expect_equal(e(signum(col("foo"))),                "signum(foo)")
  expect_equal(e(sin(col("foo"))),                   "sin(foo)")
  expect_equal(e(sinh(col("foo"))),                  "sinh(foo)")
  expect_equal(e(sqrt(col("foo"))),                  "sqrt(foo)")
  expect_equal(e(tan(col("foo"))),                   "tan(foo)")
  expect_equal(e(tanh(col("foo"))),                  "tanh(foo)")
  expect_equal(e(trunc(col("foo"))),                 "trunc(foo)")
  expect_equal(e(trunc(col("foo"), lit(2L))),        "trunc(foo, Int32(2))")
})
