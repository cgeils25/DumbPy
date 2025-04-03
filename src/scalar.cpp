#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

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

        std::string toString() 
        {
            return std::to_string(value);
        }

        void print()
        {
            std::cout << toString() << std::endl;
        }
};


