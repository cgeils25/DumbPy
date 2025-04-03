#include <pybind11/pybind11.h>
#include <iostream>
#include <vector>

namespace py = pybind11;

class Vector {
    std::vector<float> data;

    public:
        Vector(py::list data) {
            int numElements = py::len(data);

            this->data = std::vector<float>(numElements);

            for (int i = 0; i < numElements; i++) {
                this->data[i] = data[i].cast<float>();
            }

        }

        int getSize() {
            return data.size();
        }

        // void print() {
        //     std::cout << "[";
        //     for (int i = 0; i < (data.size() - 1); i++) {
        //         std::cout << data[i] << ", ";
        //     }
        //     std::cout << data[data.size() - 1] << "]" << std::endl;
        // }

        void printNoNewline() {
            std::cout << "[";

            for (int i = 0; i < (data.size() - 1); i++) {
                std::cout << data[i] << ", ";
            }
            std::cout << data[data.size() - 1] << "]";
        }

        void print()
        {
            this->printNoNewline();
            std::cout << std::endl;
        }

        float operator[](int index) {
            return data[index];
        }
};
