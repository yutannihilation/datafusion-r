# 🚧 WIP 🚧


DataFusion Python API: https://arrow.apache.org/datafusion-python/

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

### `limit()`

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

### `select_columns()`

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

### `select()`

``` r
d |> 
  datafusion_select(
    col("mpg")$alias("MPG"),   # rename
    (col("mpg") / lit(2))      # arbitrary expression
  )
#> DataFrame()
#> +------+-------------------------+
#> | MPG  | mtcars.mpg / Float64(2) |
#> +------+-------------------------+
#> | 21.0 | 10.5                    |
#> | 21.0 | 10.5                    |
#> | 22.8 | 11.4                    |
#> | 21.4 | 10.7                    |
#> | 18.7 | 9.35                    |
#> | 18.1 | 9.05                    |
#> +------+-------------------------+
```
