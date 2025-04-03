#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

class Scalar
{
    float value;

    public:
        Scalar(float value) : value(value) {}

        float getValue() 
        {
            return value;
        }

        void print()
        {
            std::cout << value << std::endl;
        }
};


