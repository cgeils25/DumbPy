# DumbPy - Like NumPy, but Slower

This is a personal project I built to help me understand C++ and how to create python wrappers for C++ code with pybind11. 

It's a from-scratch implementation of a stripped-down version of NumPy written with a C++ backend and wrapped with a Python frontend.

This project has no external dependencies other than the python interpreter itself, GCC, and pybind11.

For now, my implementation supports scalars, vectors, and 2D matrices, along with some basic transformations and linear algebra operations.

## Docker

I included the dockerfile I used to build the container I developed this in, although in hindsight it's probably unnecessary.

As long as you've got 

```
python >= 3.11
GCC >= 15.0.0
cmake >= 4.0.0
make >= 3.81
```

You're all set!

## Build

To build DumbPy binaries:

```bash
source build.sh
```

## Test

To test DumbPy:

```bash
python test.py
```