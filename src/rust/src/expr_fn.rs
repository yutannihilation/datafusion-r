// https://docs.rs/datafusion-functions/latest/datafusion_functions/expr_fn/index.html

use datafusion::functions::{core, crypto, math};
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
}
