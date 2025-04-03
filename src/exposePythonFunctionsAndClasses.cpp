#include <pybind11/pybind11.h>
#include <iostream>
#include <string>
#include "math.h"

// dumbpy types
#include "scalar.cpp"
// #include "vector.cpp"
#include "matrix.cpp"


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
        .def("print", &Scalar::printValue);

    py::class_<Vector>(m, "Vector")
        .def(py::init<py::list>(), py::arg("data"))
        .def("get_size", &Vector::getSize)
        .def("print", &Vector::print)
        .def("__getitem__", &Vector::operator[]);


    py::class_<Matrix>(m, "Matrix")
        .def(py::init<py::list>(), py::arg("data"))
        .def("get_size", &Matrix::getSize)
        .def("print", &Matrix::print)
        .def("__getitem__", &Matrix::operator[]);
}