#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

namespace py = pybind11;

void sayHello(std::string name) {
    std::cout << "Hello " << name << "!" << std::endl;
}

PYBIND11_MODULE(dumbpy, m) {
    m.doc() = "A simple hello world module";
    m.def("say_hello", &sayHello);
}