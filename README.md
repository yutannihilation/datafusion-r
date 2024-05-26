# 🚧 WIP 🚧


<!-- badges: start -->

[![R-CMD-check](https://github.com/yutannihilation/datafusionr/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/yutannihilation/datafusionr/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

## What’s this?

The main purpose of this repo is to see if [the savvy
framework](https://github.com/yutannihilation/savvy) has enough features
for mildly complex usages. Especially,

- to check if savvy can convert an external pointer or ALTREP that an
  other package defines.
  e.g. <https://arrow.apache.org/datafusion-python/>
- to figure out what async support is supposed to be
  e.g. \<https://github.com/yutannihilation/savvy-async-poc?

## Usages

### DataFrame

``` r
library(datafusionr)

x <- arrow::as_record_batch(head(mtcars))

ctx <- datafusion_session_context()
d <- ctx$create_data_frame(as_array_stream(x), table_name = "mtcars")
d
#> DataFrame()
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
#> | mpg  | cyl | disp  | hp    | drat | wt    | qsec  | vs  | am  | gear | carb |
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
#> | 21.0 | 6.0 | 160.0 | 110.0 | 3.9  | 2.62  | 16.46 | 0.0 | 1.0 | 4.0  | 4.0  |
#> | 21.0 | 6.0 | 160.0 | 110.0 | 3.9  | 2.875 | 17.02 | 0.0 | 1.0 | 4.0  | 4.0  |
#> | 22.8 | 4.0 | 108.0 | 93.0  | 3.85 | 2.32  | 18.61 | 1.0 | 1.0 | 4.0  | 1.0  |
#> | 21.4 | 6.0 | 258.0 | 110.0 | 3.08 | 3.215 | 19.44 | 1.0 | 0.0 | 3.0  | 1.0  |
#> | 18.7 | 8.0 | 360.0 | 175.0 | 3.15 | 3.44  | 17.02 | 0.0 | 0.0 | 3.0  | 2.0  |
#> | 18.1 | 6.0 | 225.0 | 105.0 | 2.76 | 3.46  | 20.22 | 1.0 | 0.0 | 3.0  | 1.0  |
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
```

`datafusion_collect()` can convert the object into a bare `data.frame`.

``` r
d |> 
  datafusion_collect()
#>    mpg cyl disp  hp drat    wt  qsec vs am gear carb
#> 1 21.0   6  160 110 3.90 2.620 16.46  0  1    4    4
#> 2 21.0   6  160 110 3.90 2.875 17.02  0  1    4    4
#> 3 22.8   4  108  93 3.85 2.320 18.61  1  1    4    1
#> 4 21.4   6  258 110 3.08 3.215 19.44  1  0    3    1
#> 5 18.7   8  360 175 3.15 3.440 17.02  0  0    3    2
#> 6 18.1   6  225 105 2.76 3.460 20.22  1  0    3    1
```

#### `limit()`

``` r
d |> 
  datafusion_limit(2)
#> DataFrame()
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
#> | mpg  | cyl | disp  | hp    | drat | wt    | qsec  | vs  | am  | gear | carb |
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
#> | 21.0 | 6.0 | 160.0 | 110.0 | 3.9  | 2.62  | 16.46 | 0.0 | 1.0 | 4.0  | 4.0  |
#> | 21.0 | 6.0 | 160.0 | 110.0 | 3.9  | 2.875 | 17.02 | 0.0 | 1.0 | 4.0  | 4.0  |
#> +------+-----+-------+-------+------+-------+-------+-----+-----+------+------+
```

#### `select_columns()`

``` r
d |>
  datafusion_select_columns("cyl", "mpg")
#> DataFrame()
#> +-----+------+
#> | cyl | mpg  |
#> +-----+------+
#> | 6.0 | 21.0 |
#> | 6.0 | 21.0 |
#> | 4.0 | 22.8 |
#> | 6.0 | 21.4 |
#> | 8.0 | 18.7 |
#> | 6.0 | 18.1 |
#> +-----+------+
```

#### `select()`

``` r
d |> 
  datafusion_select(
    col("mpg")$alias("MPG"),  # rename
    sqrt(col("mpg") / lit(2)) # arbitrary expression
  )
#> DataFrame()
#> +------+-------------------------------+
#> | MPG  | sqrt(mtcars.mpg / Float64(2)) |
#> +------+-------------------------------+
#> | 21.0 | 3.24037034920393              |
#> | 21.0 | 3.24037034920393              |
#> | 22.8 | 3.3763886032268267            |
#> | 21.4 | 3.271085446759225             |
#> | 18.7 | 3.057776970284131             |
#> | 18.1 | 3.0083217912982647            |
#> +------+-------------------------------+
```

### Parquet file

``` r
ctx_parquet <- datafusion_session_context()

parquet_file <- system.file("extdata/mtcars.parquet", package = "datafusionr")
ctx_parquet$register_parquet("mtcars", parquet_file)

d <- ctx_parquet$sql("select cyl, mpg from mtcars limit 5")
d
#> DataFrame()
#> +-----+------+
#> | cyl | mpg  |
#> +-----+------+
#> | 6.0 | 21.0 |
#> | 6.0 | 21.0 |
#> | 4.0 | 22.8 |
#> | 6.0 | 21.4 |
#> | 8.0 | 18.7 |
#> +-----+------+
```

### CSV file

``` r
ctx_csv <- datafusion_session_context()

csv_file <- system.file("extdata/mtcars.csv", package = "datafusionr")
ctx_csv$register_csv("mtcars", csv_file)

d <- ctx_csv$sql("select cyl, mpg from mtcars limit 5")
d
#> DataFrame()
#> +-----+------+
#> | cyl | mpg  |
#> +-----+------+
#> | 6   | 21.0 |
#> | 6   | 21.0 |
#> | 4   | 22.8 |
#> | 6   | 21.4 |
#> | 8   | 18.7 |
#> +-----+------+
```
