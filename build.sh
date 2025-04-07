#!/bin/bash

echo "Compiling DumbPy C++ functions and classes..."

cmake . &&

make &&

mkdir -p bin &&

mv *.so bin &&

# so python can import dumbpy
export PYTHONPATH="${PYTHONPATH}:bin/" &&

echo """
DumbPy binaries built and moved to bin/. DumbPy can now be imported with 

>>> import dumbpy as dp

>>> dp.say_hello('Your Name')

"Hello, Your Name!"
""" 