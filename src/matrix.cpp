#include <pybind11/pybind11.h>
#include <iostream>
#include "vector.cpp"

namespace py = pybind11;

class Matrix {
    std::vector<Vector> data;

    public:
        Matrix(py::list data) {
            int numRows = py::len(data);
            int numCols = py::len(data[0]);

            this->data = std::vector<Vector>();

            for (int i = 0; i < numRows; i++) {
                // this is dumb in terms of memory efficiency
                this->data.push_back(Vector(data[i]));
            }
        }

        std::pair<int, int> getSize() {
            return {(data.size()), data[0].getSize()};
        }

        void print() {
            std::cout << "[";

            for (int i = 0; i < (data.size() - 1); i++) 
            {
                data[i].printNoNewline();
                std::cout << ", " << std::endl;
            }

            data[data.size() - 1].printNoNewline();
            
            std::cout << "]" << std::endl;
        }

        Vector operator[](int index) {
            return data[index];
        }
};
