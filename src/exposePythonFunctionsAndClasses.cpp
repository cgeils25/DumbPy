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
        .def("print", &Scalar::print);

    py::class_<Vector>(m, "Vector")
        .def(py::init<int>(), py::arg("num_elements"))
        .def("set_values", &Vector::setValues, py::arg("data"))
        .def("get_size", &Vector::getSize)
        .def("print", &Vector::print)
        .def("__getitem__", &Vector::operator[])
        .def("__len__", &Vector::getSize);

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<int, int>(), py::arg("num_rows"), py::arg("num_cols"))
        .def("set_values", &Matrix::setValues, py::arg("data"))
        .def("get_size", &Matrix::getSize)
        .def("print", &Matrix::print)
        .def("__getitem__", &Matrix::operator[])
        .def("__len__", &Matrix::getNumRows);

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

}

