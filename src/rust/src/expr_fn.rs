// https://docs.rs/datafusion-functions/latest/datafusion_functions/expr_fn/index.html

use datafusion::functions::{core, crypto, datetime, encoding, math, regex, string, unicode};
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

    // encoding functions -----------------------------------------------

    fn decode(input: DataFusionRExpr, encoding: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(encoding::expr_fn::decode(
            input.0, encoding.0,
        )))
    }

    fn encode(input: DataFusionRExpr, encoding: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(encoding::expr_fn::encode(
            input.0, encoding.0,
        )))
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

    // string functions -------------------------------------------

    fn ascii(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::ascii(arg.0)))
    }

    fn bit_length(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::bit_length(arg.0)))
    }

    fn btrim(
        string: DataFusionRExpr,
        trim_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(s) = trim_str {
            vec![string.0, s.0]
        } else {
            vec![string.0]
        };
        Ok(DataFusionRExpr(string::expr_fn::btrim(args)))
    }

    fn chr(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::chr(arg.0)))
    }

    fn concat(args: DataFusionRExprs) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::concat(args.0)))
    }

    fn concat_ws(
        delimiter: DataFusionRExpr,
        args: DataFusionRExprs,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::concat_ws(
            delimiter.0,
            args.0,
        )))
    }

    fn ends_with(
        string: DataFusionRExpr,
        suffix: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::ends_with(
            string.0, suffix.0,
        )))
    }

    fn initcap(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::initcap(arg.0)))
    }

    fn levenshtein(arg1: DataFusionRExpr, arg2: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::levenshtein(
            arg1.0, arg2.0,
        )))
    }

    fn lower(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::lower(arg.0)))
    }

    fn ltrim(
        string: DataFusionRExpr,
        trim_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(s) = trim_str {
            vec![string.0, s.0]
        } else {
            vec![string.0]
        };
        Ok(DataFusionRExpr(string::expr_fn::ltrim(args)))
    }

    fn octet_length(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::octet_length(vec![arg.0])))
    }

    fn overlay(
        string: DataFusionRExpr,
        replacement: DataFusionRExpr,
        pos: DataFusionRExpr,
        count: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(c) = count {
            vec![string.0, replacement.0, pos.0, c.0]
        } else {
            vec![string.0, replacement.0, pos.0]
        };
        Ok(DataFusionRExpr(string::expr_fn::overlay(args)))
    }

    // TODO: repeat is a syntax in R
    fn str_repeat(string: DataFusionRExpr, n: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::repeat(string.0, n.0)))
    }

    fn replace(
        string: DataFusionRExpr,
        from: DataFusionRExpr,
        to: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::replace(
            string.0, from.0, to.0,
        )))
    }

    fn rtrim(
        string: DataFusionRExpr,
        trim_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(s) = trim_str {
            vec![string.0, s.0]
        } else {
            vec![string.0]
        };
        Ok(DataFusionRExpr(string::expr_fn::rtrim(args)))
    }

    fn split_part(
        string: DataFusionRExpr,
        delimiter: DataFusionRExpr,
        index: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::split_part(
            string.0,
            delimiter.0,
            index.0,
        )))
    }

    fn starts_with(
        string: DataFusionRExpr,
        prefix: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::starts_with(
            string.0, prefix.0,
        )))
    }

    fn to_hex(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::to_hex(arg.0)))
    }

    fn trim(
        string: DataFusionRExpr,
        trim_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        // trim() is an alias of btrim()
        Self::btrim(string, trim_str)
    }

    fn upper(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::upper(arg.0)))
    }

    fn uuid() -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(string::expr_fn::uuid()))
    }

    // unicode functions --------------------------------------------------------

    fn char_length(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Self::character_length(arg)
    }

    fn character_length(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::character_length(arg.0)))
    }

    fn find_in_set(
        string: DataFusionRExpr,
        strlist: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::find_in_set(
            string.0, strlist.0,
        )))
    }

    fn instr(
        string: DataFusionRExpr,
        substring: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Self::strpos(string, substring)
    }

    fn left(string: DataFusionRExpr, n: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::left(string.0, n.0)))
    }

    fn length(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Self::character_length(arg)
    }

    fn lpad(
        string: DataFusionRExpr,
        padding_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(p) = padding_str {
            vec![string.0, p.0]
        } else {
            vec![string.0]
        };

        Ok(DataFusionRExpr(unicode::expr_fn::lpad(args)))
    }

    fn position(
        string: DataFusionRExpr,
        substring: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Self::strpos(string, substring)
    }

    fn reverse(arg: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::reverse(arg.0)))
    }

    fn right(string: DataFusionRExpr, n: DataFusionRExpr) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::right(string.0, n.0)))
    }

    fn rpad(
        string: DataFusionRExpr,
        padding_str: Option<DataFusionRExpr>,
    ) -> savvy::Result<DataFusionRExpr> {
        let args = if let Some(p) = padding_str {
            vec![string.0, p.0]
        } else {
            vec![string.0]
        };

        Ok(DataFusionRExpr(unicode::expr_fn::rpad(args)))
    }

    fn strpos(
        string: DataFusionRExpr,
        substring: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::strpos(
            string.0,
            substring.0,
        )))
    }

    fn substr(
        string: DataFusionRExpr,
        position: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::substr(
            string.0, position.0,
        )))
    }

    fn substr_index(
        string: DataFusionRExpr,
        delimiter: DataFusionRExpr,
        count: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::substr_index(
            string.0,
            delimiter.0,
            count.0,
        )))
    }

    fn substring(
        string: DataFusionRExpr,
        position: DataFusionRExpr,
        length: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::substring(
            string.0, position.0, length.0,
        )))
    }

    fn translate(
        string: DataFusionRExpr,
        from: DataFusionRExpr,
        to: DataFusionRExpr,
    ) -> savvy::Result<DataFusionRExpr> {
        Ok(DataFusionRExpr(unicode::expr_fn::translate(
            string.0, from.0, to.0,
        )))
    }
}
