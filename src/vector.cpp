#include <pybind11/pybind11.h>
#include <iostream>
#include <vector>
#include <string>

namespace py = pybind11;

class Vector 
{
    /*
    A 1D Vector class filled with floats.
    */
    int numElements;
    std::vector<float> data;

    public:
        Vector(int numElements) : numElements(numElements) 
        {
            this->data = std::vector<float>(numElements);
        }

        Vector(py::list values) 
        {
            this->numElements = py::len(values);
            this->data = std::vector<float>(numElements);

            setValuesVector(values);
        }

        void setValuesVector(py::list values) 
        {
            for (int i = 0; i < numElements; i++) 
            {
                this->data[i] = values[i].cast<float>();
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
            return this->numElements;
        }

        std::string toString() 
        {
            std::string result = "[";

            for (int i = 0; i < (data.size() - 1); i++) 
            {
                result += std::to_string(data[i]) + ", ";
            }

            result += std::to_string(data[data.size() - 1]) + "]";

            return result;
        }

        void printNoNewline() 
        {
            std::cout << toString();
        }

        void print()
        {
            printNoNewline();
            std::cout << std::endl;
        }

        // return a reference so that the value can be accessed and assigned
        float& operator[](int index) 
        {
            if (index < 0 || index >= data.size()) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            return data[index];
        }

        bool operator==(Vector& other) 
        {
            if (this->numElements != other.getSize()) 
            {
                return false;
            }

            for (int i = 0; i < this->numElements; i++) 
            {
                if (this->data[i] != other[i]) 
                {
                    return false;
                }
            }

            return true;
        }

        bool operator!=(Vector& other) 
        {
            return !(*this == other);
        }
};
