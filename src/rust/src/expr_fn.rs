// https://docs.rs/datafusion-functions/latest/datafusion_functions/expr_fn/index.html

use datafusion::functions::{core, crypto, datetime, math, regex};
use savvy::savvy;

use crate::expr::{DataFusionRExpr, DataFusionRExprs};

// This is an dummy struct to bundle function expressions.
#[savvy]
struct DataFusionRExprFunctions;

#[savvy]
impl DataFusionRExprFunctions {
    // core functions ---------------------------------------------------

    fn arrow_cast(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::arrow_cast(arg1.0, arg2.0)))
    }

    fn arrow_typeof(arg1: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::arrow_typeof(arg1.0)))
    }

    // Change to accept dots on R's side
    fn coalesce(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::coalesce(args.0)))
    }

    fn get_field(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::get_field(arg1.0, arg2.0)))
    }

    // Change to accept dots on R's side
    fn named_struct(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::named_struct(args.0)))
    }

    fn nullif(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::nullif(arg1.0, arg2.0)))
    }

    fn nvl(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::nvl(arg1.0, arg2.0)))
    }

    fn nvl2(
        arg1: DataFusionRExpr,
        arg2: DataFusionRExpr,
        arg3: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(core::expr_fn::nvl2(arg1.0, arg2.0, arg3.0)))
    }

    // crypto functions -------------------------------------------------

    fn digest(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::digest(arg1.0, arg2.0)))
    }

    fn md5(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::md5(arg.0)))
    }

    fn sha224(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::sha224(arg.0)))
    }

    fn sha256(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::sha256(arg.0)))
    }

    fn sha384(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::sha384(arg.0)))
    }

    fn sha512(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(crypto::expr_fn::sha512(arg.0)))
    }

    // date functions ---------------------------------------------------

    fn current_date() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::current_date()))
    }

    fn current_time() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::current_time()))
    }

    fn date_bin(
        stride: DataFusionRExpr,
        source: DataFusionRExpr,
        origin: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::date_bin(
            stride.0, source.0, origin.0,
        )))
    }

    fn date_part(part: DataFusionRExpr, date: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::date_part(
            part.0, date.0,
        )))
    }

    fn date_trunc(part: DataFusionRExpr, date: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::date_trunc(
            part.0, date.0,
        )))
    }

    fn from_unixtime(unixtime: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::from_unixtime(
            unixtime.0,
        )))
    }

    fn make_date(
        year: DataFusionRExpr,
        month: DataFusionRExpr,
        day: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::make_date(
            year.0, month.0, day.0,
        )))
    }

    fn now() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::now()))
    }

    fn to_char(
        datetime: DataFusionRExpr,
        format: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_char(
            datetime.0, format.0,
        )))
    }

    fn to_date(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_date(args.0)))
    }

    fn to_timestamp(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_timestamp(args.0)))
    }

    fn to_timestamp_micros(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_timestamp_micros(
            args.0,
        )))
    }

    fn to_timestamp_millis(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_timestamp_millis(
            args.0,
        )))
    }

    fn to_timestamp_nanos(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_timestamp_nanos(
            args.0,
        )))
    }

    fn to_timestamp_seconds(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_timestamp_seconds(
            args.0,
        )))
    }

    fn to_unixtime(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(datetime::expr_fn::to_unixtime(args.0)))
    }

    // math functions ---------------------------------------------------

    fn abs(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::abs(num.0)))
    }

    fn acos(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::acos(num.0)))
    }

    fn acosh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::acosh(num.0)))
    }

    fn asin(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::asin(num.0)))
    }

    fn asinh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::asinh(num.0)))
    }

    fn atan(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::atan(num.0)))
    }

    fn atan2(x: DataFusionRExpr, y: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::atan2(x.0, y.0)))
    }

    fn atanh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::atanh(num.0)))
    }

    fn cbrt(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::cbrt(num.0)))
    }

    fn ceil(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::ceil(num.0)))
    }

    fn cos(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::cos(num.0)))
    }

    fn cosh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::cosh(num.0)))
    }

    fn cot(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::cot(num.0)))
    }

    fn degrees(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::degrees(num.0)))
    }

    fn exp(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::exp(num.0)))
    }

    fn factorial(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::factorial(num.0)))
    }

    fn floor(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::floor(num.0)))
    }

    fn gcd(x: DataFusionRExpr, y: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::gcd(x.0, y.0)))
    }

    fn isnan(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::isnan(num.0)))
    }

    fn iszero(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::iszero(num.0)))
    }

    fn lcm(x: DataFusionRExpr, y: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::lcm(x.0, y.0)))
    }

    fn ln(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::ln(num.0)))
    }

    fn log(base: DataFusionRExpr, num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::log(base.0, num.0)))
    }

    fn log2(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::log2(num.0)))
    }

    fn log10(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::log10(num.0)))
    }

    fn nanvl(x: DataFusionRExpr, y: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::nanvl(x.0, y.0)))
    }

    fn pi() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::pi()))
    }

    fn power(base: DataFusionRExpr, exponent: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::power(base.0, exponent.0)))
    }

    fn radians(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::radians(num.0)))
    }

    fn random() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::random()))
    }

    fn round(
        num: DataFusionRExpr,
        decimal_place: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(d) = decimal_place {
            vec![num.0, d.0]
        } else {
            vec![num.0]
        };
        Ok(DataFusionRExpr(math::expr_fn::round(args)))
    }

    fn signum(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::signum(num.0)))
    }

    fn sin(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::sin(num.0)))
    }

    fn sinh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::sinh(num.0)))
    }

    fn sqrt(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::sqrt(num.0)))
    }

    fn tan(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::tan(num.0)))
    }

    fn tanh(num: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(math::expr_fn::tanh(num.0)))
    }

    fn trunc(
        num: DataFusionRExpr,
        decimal_place: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(d) = decimal_place {
            vec![num.0, d.0]
        } else {
            vec![num.0]
        };
        Ok(DataFusionRExpr(math::expr_fn::trunc(args)))
    }

    // regex functions ----------------------------------------------

    fn regexp_like(
        string: DataFusionRExpr,
        pattern: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(regex::expr_fn::regexp_like(
            string.0, pattern.0,
        )))
    }

    fn regexp_match(
        string: DataFusionRExpr,
        pattern: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(regex::expr_fn::regexp_match(
            string.0, pattern.0,
        )))
    }

    fn regexp_replace(
        string: DataFusionRExpr,
        pattern: DataFusionRExpr,
        replacement: DataFusionRExpr,
        flags: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let flags = match flags {
            Some(flags) => flags.0,
            None => datafusion::logical_expr::lit("g"),
        };

        Ok(DataFusionRExpr(regex::expr_fn::regexp_replace(
            string.0,
            pattern.0,
            replacement.0,
            flags,
        )))
    }
}
