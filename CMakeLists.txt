cmake_minimum_required(VERSION 4.0.0)
project(dumbpy)
add_subdirectory(pybind11)
pybind11_add_module(dumbpy src/exposePythonFunctionsAndClasses.cpp)
