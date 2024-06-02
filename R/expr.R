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
`%%.DataFusionRExpr` <- function(x, y) x$reminder(y)
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

.datafusion_env_for_eval <- rlang::env(
  col  = DataFusionRExpr$col,
  ident  = DataFusionRExpr$ident,
  lit  = DataFusionRExpr$lit,
  wildcard  = DataFusionRExpr$wildcard,

  `&&` = function(x, y) x$and(y),
  `||` = function(x, y) x$or(y),
  `<`  = function(x, y) x$lt(y),
  `<=` = function(x, y) x$lt_eq(y),
  `>`  = function(x, y) x$gt(y),
  `>=` = function(x, y) x$gt_eq(y),
  `==` = function(x, y) x$eq(y),
  `!=` = function(x, y) x$not_eq(y),
  `!`  = function(x)    x$not(),

  # TODO: can I always overwrite `c`?
  `%in%` = function(x, y) {
    y_expr <- rlang::enexpr(y)

    # convert an expression like `c(lit("a"), ...)` to DataFusionRExprs
    if (y_expr[[1L]] == as.name("c")) {
      y_expr[[1]] <- as.name("datafusion_exprs")
      y <- rlang::eval_bare(y_expr)
    }

    x$in_list(y, FALSE)
  },

  !!!as.list(DataFusionRExprFunctions)
)

.wrap_dots <- function(f) {
  f <- force(f)
  function(...) f(datafusion_exprs(...))
}
.wrap_dots2 <- function(f) {
  f <- force(f)
  function(x, ...) {
    f(x, datafusion_exprs(...))
  }
}

.datafusion_env_for_eval$coalesce     <- .wrap_dots(.datafusion_env_for_eval$coalesce)
.datafusion_env_for_eval$named_struct <- .wrap_dots(.datafusion_env_for_eval$named_struct)

.datafusion_env_for_eval$to_date              <- .wrap_dots(.datafusion_env_for_eval$to_date)
.datafusion_env_for_eval$to_timestamp         <- .wrap_dots(.datafusion_env_for_eval$to_timestamp)
.datafusion_env_for_eval$to_timestamp_micros  <- .wrap_dots(.datafusion_env_for_eval$to_timestamp_micros)
.datafusion_env_for_eval$to_timestamp_millis  <- .wrap_dots(.datafusion_env_for_eval$to_timestamp_millis)
.datafusion_env_for_eval$to_timestamp_nanos   <- .wrap_dots(.datafusion_env_for_eval$to_timestamp_nanos)
.datafusion_env_for_eval$to_timestamp_seconds <- .wrap_dots(.datafusion_env_for_eval$to_timestamp_seconds)
.datafusion_env_for_eval$to_unixtime          <- .wrap_dots(.datafusion_env_for_eval$to_unixtime)

.datafusion_env_for_eval$concat <- .wrap_dots(.datafusion_env_for_eval$concat)

.datafusion_env_for_eval$concat_ws <- .wrap_dots2(.datafusion_env_for_eval$concat_ws)

.datafusion_env_for_eval$array_concat <- .wrap_dots(.datafusion_env_for_eval$array_concat)
.datafusion_env_for_eval$make_array <- .wrap_dots(.datafusion_env_for_eval$make_array)

#' @export
datafusion_exprs <- function(...) {
  expr_list <- rlang::enexprs(...)
  e <- rlang::env_clone(.datafusion_env_for_eval, parent.frame(2L))
  out <- DataFusionRExprs$new(length(expr_list))
  for (expr in expr_list) {
    out$add_expr(rlang::eval_bare(expr, e))
  }
  out
}
