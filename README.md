# Integral Executor
## Coloring
If you want to compile program without colors - remove from __main.cpp[1]__
`#define INTEGRAL_EXECUTOR_COLORED`
if you want to use without color - use `--no-color` option
## Methods of integrate:
- Rectangle's method `-m r`
	- left rectangles `-t l`
	- middle rectangles `-t m`
	- right rectabgle `-t r`
- Simpson's method `-m s`
- Trapezes method `-m t`
##  Other parameters
__List of functions__
To get functions list `-f` or `--funcs`
__Setting function number in parameter__
To set function by number `-F` or `--func`, posible only nonegative integer values
__Setting accuracy__
`--accuracy`/`-a` is parameter of accuracy of integrate:.
If top value is _100_ and accuracy is _3_, then step of integrating is _0.1_
Default value is _6_
## All allowed options like in `-h`:
```
Required options:
  -m [ --method ] arg   using method:
                        r - for rectangle
                        t - for trapeze
                        s - for Simpson's method
Allowed options:
  -h [ --help ]         produce help message
  -f [ --funcs ]        produce functions list
  -F [ --func ] arg     number of function
  -a [ --accuracy ] arg accuracy of calculating integral, default: 6
  --no-color            disabling color for current execution
For rectangle method:
  -t [ --type ] arg     type of rectangle method:
                        l - for left
                        t - for middle
                        r - for right
  ```
### Examples
- To exexcute 1st function (With number _0_), usng right rectangles method
	-  `integrates -m r -t r -F 0`
- To execute 3rd function (With number _2_), using Simpson's method and without color and display help message
	- `integrates -m s -F 2 --no-color -h`
