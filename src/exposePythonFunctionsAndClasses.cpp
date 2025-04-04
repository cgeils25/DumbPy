#include <pybind11/pybind11.h>
#include <iostream>
#include <string>
#include "math.h"

#include "dumbpyTypes.h"
#include "math/dumbpyMath.h"

namespace py = pybind11;

void sayHello(std::string name) {
    std::cout << "Hello " << name << "!" << std::endl;
}

PYBIND11_MODULE(dumbpy, m) {
    m.doc() = "A simple hello world module";
    m.def("say_hello", &sayHello, py::arg("name") = "World");

    py::class_<Scalar>(m, "Scalar")
        .def(py::init<float>(), py::arg("value"))
        .def("get_value", &Scalar::getValue)
        .def("print", &Scalar::print)
        .def("__repr__", &Scalar::toString);

    py::class_<Vector>(m, "Vector") // could make this _vector to wrap with python later
        .def(py::init<int>(), py::arg("num_elements"))
        .def("set_values", &Vector::setValuesVector, py::arg("values"))
        .def("get_size", &Vector::getSize)
        .def("print", &Vector::print)
        .def("__getitem__", &Vector::operator[])
        .def("__len__", &Vector::getSize)
        .def("__repr__", &Vector::toString);

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<int, int>(), py::arg("num_rows"), py::arg("num_cols"))
        .def("set_values", &Matrix::setValuesMatrix, py::arg("values"))
        .def("get_size", &Matrix::getSize)
        .def("print", &Matrix::print)
        .def("__getitem__", &Matrix::operator[])
        .def("__len__", &Matrix::getNumRows)
        .def("__repr__", &Matrix::toString);

    auto math = m.def_submodule("math", "Math operations for Scalar, Vector, and Matrix types");

    //scalar operations
    math.def("scalar_add", &scalarAdd, py::arg("scalar_1"), py::arg("scalar_2"));
    math.def("scalar_subtract", &scalarSubtract, py::arg("scalar_1"), py::arg("scalar_2"));
    math.def("scalar_multiply", &scalarMultiply, py::arg("scalar_1"), py::arg("scalar_2"));
    math.def("scalar_divide", &scalarDivide, py::arg("scalar_1"), py::arg("scalar_2"));
    math.def("scalar_power", &scalarPower, py::arg("scalar_1"), py::arg("scalar_2"));
    math.def("scalar_sqrt", &scalarSqrt, py::arg("scalar"));
    math.def("scalar_exp", &scalarExp, py::arg("scalar"));
    math.def("scalar_ln", &scalarLn, py::arg("scalar"));
    math.def("scalar_log", &scalarLog, py::arg("argument_scalar"), py::arg("base_scalar"));

    //vector operations
    math.def("dot_product", &dotProduct, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_add", &vectorAdd, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_subtract", &vectorSubtract, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_multiply", &vectorMultiply, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_divide", &vectorDivide, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_power", &vectorPower, py::arg("vector_1"), py::arg("vector_2"));
    math.def("vector_sqrt", &vectorSqrt, py::arg("vector"));
    math.def("vector_exp", &vectorExp, py::arg("vector"));
    math.def("vector_ln", &vectorLn, py::arg("vector"));
    math.def("vector_log", &vectorLog, py::arg("argument_vector"), py::arg("base_vector"));

    //matrix operations
    math.def("matmul", &MatMul, py::arg("matrix_1"), py::arg("matrix_2"));
}

