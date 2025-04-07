#include <pybind11/pybind11.h>
#include <iostream>
#include <string>
#include "math.h"

#include "dumbpyTypes.h"
#include "math/dumbpyMath.h"
#include "transformations/dumbpyTransformations.h"

namespace py = pybind11;

void sayHello(std::string name) 
{
    std::cout << "Hello " << name << "!" << std::endl;
}

PYBIND11_MODULE(_dumbpy_core, m) 
{
    m.doc() = "A simple Python frontend for a numpy-like C++ library";
    m.def("_say_hello", &sayHello, py::arg("name") = "World");

    py::class_<Vector>(m, "_vector") 
        .def(py::init<py::list>(), py::arg("values"))
        .def("set_values", &Vector::setValuesVector, py::arg("values"))
        .def("size", &Vector::getSize)
        .def("print", &Vector::print)
        .def("__getitem__", &Vector::operator[])
        .def("__len__", &Vector::getSize)
        .def("__repr__", &Vector::toString)
        .def("__setitem__", [](Vector& self, int index, float value) { self[index] = value; }, py::arg("index"), py::arg("value"))
        .def("__eq__", [](Vector& self, Vector& other) { return self == other; }, py::arg("other"));


    py::class_<Matrix>(m, "_matrix")
        .def(py::init<py::list>(), py::arg("values"))
        .def("set_values", &Matrix::setValuesMatrix, py::arg("values"))
        .def("size", &Matrix::getSize)
        .def("print", &Matrix::print)
        .def("__getitem__", &Matrix::operator[])
        .def("__len__", &Matrix::getNumRows)
        .def("__repr__", &Matrix::toString)
        // fix this somehow. could just make a literal setitem and then expose it as the [] operator
        // .def("__setitem__", [](Matrix& self, py::tuple i_j, float value) { self[i_j[0]][i_j[1]] = value; }, py::arg("i"), py::arg("j"), py::arg("value"))
        .def("__eq__", [](Matrix& self, Matrix& other) { return self == other; }, py::arg("other"));

    //math operations
    auto math = m.def_submodule("_math", "Math operations for Vector and Matrix types");

    //vector operations
    math.def("add", static_cast<Vector (*)(Vector&, float)>(&add), py::arg("v1"), py::arg("scalar"), py::doc("Add a vector and a scalar, then return the result as a new vector."));
    math.def("add", static_cast<Vector (*)(Vector&, Vector&)>(&add), py::arg("v1"), py::arg("v2"), py::doc("Add two vectors element-wise, then return the result as a new vector."));
    math.def("subtract", static_cast<Vector (*)(Vector&, float)>(&subtract), py::arg("v1"), py::arg("scalar"), py::doc("Subtract a scalar from a vector, then return the result as a new vector."));
    math.def("subtract", static_cast<Vector (*)(Vector&, Vector&)>(&subtract), py::arg("v1"), py::arg("v2"), py::doc("Subtract two vectors element-wise, then return the result as a new vector."));
    math.def("multiply", static_cast<Vector (*)(Vector&, float)>(&multiply), py::arg("v1"), py::arg("scalar"), py::doc("Multiply a vector by a scalar, then return the result as a new vector."));
    math.def("multiply", static_cast<Vector (*)(Vector&, Vector&)>(&multiply), py::arg("v1"), py::arg("v2"), py::doc("Multiply two vectors element-wise, then return the result as a new vector."));
    math.def("divide", static_cast<Vector (*)(Vector&, float)>(&divide), py::arg("v1"), py::arg("scalar"), py::doc("Divide a vector by a scalar, then return the result as a new vector."));
    math.def("divide", static_cast<Vector (*)(Vector&, Vector&)>(&divide), py::arg("v1"), py::arg("v2"), py::doc("Divide two vectors element-wise, then return the result as a new vector."));
    math.def("dot_product", &dotProduct, py::arg("v1"), py::arg("v2"), py::doc("Calculate the dot product of two vectors, then return the result as a new vector."));
    math.def("power", static_cast<Vector (*)(Vector&, float)>(&power), py::arg("v1"), py::arg("exponent"), py::doc("Raise a vector to the power of a scalar, then return the result as a new vector."));
    math.def("power", static_cast<Vector (*)(Vector&, Vector&)>(&power), py::arg("v1"), py::arg("v2"), py::doc("Raise a vector to the power of another vector element-wise, then return the result as a new vector."));
    math.def("sqrt", static_cast<Vector (*)(Vector&)>(&sqrt), py::arg("v1"), py::doc("Calculate the square root of a vector element-wise, then return the result as a new vector."));
    math.def("exp", static_cast<Vector (*)(Vector&)>(&exp), py::arg("v1"), py::doc("Calculate e to the power of a vector element-wise, then return the result as a new vector."));
    math.def("ln", static_cast<Vector (*)(Vector&)>(&ln), py::arg("v1"), py::doc("Calculate the natural logarithm of a vector element-wise, then return the result as a new vector."));
    math.def("log", static_cast<Vector (*)(Vector&, float)>(&log), py::arg("v1"), py::arg("base"), py::doc("Calculate the logarithm of a vector with a specified base, then return the result as a new vector."));
    math.def("log", static_cast<Vector (*)(Vector&, Vector&)>(&log), py::arg("v1"), py::arg("v2"), py::doc("Calculate the logarithm of a vector with another vector as the base element-wise, then return the result as a new vector."));

    //matrix operations
    math.def("add", static_cast<Matrix (*)(Matrix&, float)>(&add), py::arg("m1"), py::arg("scalar"), py::doc("Add a matrix and a scalar, then return the result as a new matrix."));
    math.def("add", static_cast<Matrix (*)(Matrix&, Matrix&)>(&add), py::arg("m1"), py::arg("m2"), py::doc("Add two matrices element-wise, then return the result as a new matrix."));
    math.def("subtract", static_cast<Matrix (*)(Matrix&, float)>(&subtract), py::arg("m1"), py::arg("scalar"), py::doc("Subtract a scalar from a matrix, then return the result as a new matrix."));
    math.def("subtract", static_cast<Matrix (*)(Matrix&, Matrix&)>(&subtract), py::arg("m1"), py::arg("m2"), py::doc("Subtract two matrices element-wise, then return the result as a new matrix."));
    math.def("multiply", static_cast<Matrix (*)(Matrix&, float)>(&multiply), py::arg("m1"), py::arg("scalar"), py::doc("Multiply a matrix by a scalar, then return the result as a new matrix."));
    math.def("multiply", static_cast<Matrix (*)(Matrix&, Matrix&)>(&multiply), py::arg("m1"), py::arg("m2"), py::doc("Multiply two matrices element-wise, then return the result as a new matrix."));
    math.def("divide", static_cast<Matrix (*)(Matrix&, float)>(&divide), py::arg("m1"), py::arg("scalar"), py::doc("Divide a matrix by a scalar, then return the result as a new matrix."));
    math.def("divide", static_cast<Matrix (*)(Matrix&, Matrix&)>(&divide), py::arg("m1"), py::arg("m2"), py::doc("Divide two matrices element-wise, then return the result as a new matrix."));
    math.def("mat_mul", static_cast<Matrix (*)(Matrix&, Matrix&)>(&matMul), py::arg("m1"), py::arg("m2"), py::doc("Multiply two matrices, then return the result as a new matrix."));
    math.def("mat_mul", static_cast<Vector (*)(Matrix&, Vector&)>(&matMul), py::arg("m"), py::arg("v"), py::doc("Multiply a matrix (m x n) and a vector (n x 1), then return the result as a new vector (m x 1)"));
    math.def("power", static_cast<Matrix (*)(Matrix&, float)>(&power), py::arg("m1"), py::arg("exponent"), py::doc("Raise a matrix to the power of a scalar, then return the result as a new matrix."));
    math.def("power", static_cast<Matrix (*)(Matrix&, Matrix&)>(&power), py::arg("m1"), py::arg("m2"), py::doc("Raise a matrix to the power of another matrix element-wise, then return the result as a new matrix."));
    math.def("sqrt", static_cast<Matrix (*)(Matrix&)>(&sqrt), py::arg("m1"), py::doc("Calculate the square root of a matrix element-wise, then return the result as a new matrix."));
    math.def("exp", static_cast<Matrix (*)(Matrix&)>(&exp), py::arg("m1"), py::doc("Calculate e to the power of a matrix element-wise, then return the result as a new matrix."));
    math.def("ln", static_cast<Matrix (*)(Matrix&)>(&ln), py::arg("m1"), py::doc("Calculate the natural logarithm of a matrix element-wise, then return the result as a new matrix."));
    math.def("log", static_cast<Matrix (*)(Matrix&, float)>(&log), py::arg("m1"), py::arg("base"), py::doc("Calculate the logarithm of a matrix with a specified base, then return the result as a new matrix."));
    math.def("log", static_cast<Matrix (*)(Matrix&, Matrix&)>(&log), py::arg("m1"), py::arg("m2"), py::doc("Calculate the logarithm of a matrix with another matrix as the base element-wise, then return the result as a new matrix."));

    // transformations
    auto transformations = m.def_submodule("_transformations", "Transformations for DumbPy types");

    transformations.def("transpose", &transpose, py::arg("m"), py::doc("Transpose a matrix, then return the result as a new matrix."));

    
}

