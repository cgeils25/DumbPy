#include <pybind11/pybind11.h>
#include <iostream>
#include <vector>

namespace py = pybind11;

class Vector 
{
    int numElements;
    std::vector<float> data;

    public:
        Vector(int numElements) : numElements(numElements) 
        {
            this->data = std::vector<float>(numElements);
        }

        void setValues(py::list data) 
        {
            for (int i = 0; i < numElements; i++) 
            {
                this->data[i] = data[i].cast<float>();
            }
        }

        void setValue(int index, float value) 
        {
            if (index < 0 || index >= numElements) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            this->data[index] = value;
        }

        int getSize() 
        {
            return data.size();
        }

        void printNoNewline() 
        {
            std::cout << "[";

            for (int i = 0; i < (data.size() - 1); i++) 
            {
                std::cout << data[i] << ", ";
            }

            std::cout << data[data.size() - 1] << "]";
        }

        void print()
        {
            this->printNoNewline();
            std::cout << std::endl;
        }

        float operator[](int index) 
        {
            if (index < 0 || index >= data.size()) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            return data[index];
        }
};
