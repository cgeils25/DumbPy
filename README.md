# DumbPy - Like NumPy, but Slower

This is a project I built to help me understand how to write optimized C++ and how to create python wrappers for C++ code with pybind11. 

It's a from-scratch implementation of a numpy-like scientific computing library written with a C++ backend and wrapped with a Python frontend, including a full unit testing suite.

This project has no external dependencies other than the python interpreter itself, GCC, and pybind11.

For now, my implementation supports 1D vectors and 2D matrices, along with some basic transformations and linear algebra operations.

## Docker

I included the dockerfile I used to build the container I developed this in, although in hindsight it's probably unnecessary.

As long as you've got 

```
python >= 3.11
GCC >= 15.0.0
cmake >= 3.25.1
make >= 3.81
```

You're all set!

## Build

To build DumbPy binaries:

```bash
source build.sh
```

## Tests

To run unit tests:

```bash
python test.py
```

## Docs

For more information about submodules, functions, and classes, use (in python):

```python
import dumbpy as dp

help(dp)
```

## Some Examples

### Vectors
```python
import dumbpy as dp

data = [1, 2, 3]

v = dp.Vector(data)

dp.math.add(v, 6)
```

Output:

```bash
[7.000000, 8.000000, 9.000000]
```

### Matrices

```python
import dumbpy as dp

data = [[1, 2, 3], [4, 5, 6]]

m = dp.Matrix(data)

dp.math.power(m, 2)
```

Output:

```bash
[[1.000000, 4.000000, 9.000000], 
[16.000000, 25.000000, 36.000000]]
```

## Benchmark

To compare matrix multiplication implemented with pure python to DumbPy, run:

```bash
python benchmark.py
```

On my system (2020 Macbook Pro, M1 Pro, 16 Gb RAM), the results were:

```bash
Python time: 47.233 seconds
DumbPy time: 10.621 seconds
```
