cmake_minimum_required(VERSION 3.25.1)
project(dumbpy)
add_subdirectory(pybind11)
pybind11_add_module(_dumbpy_core src/exposePythonFunctionsAndClasses.cpp)
