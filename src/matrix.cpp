#include <pybind11/pybind11.h>
#include <iostream>
#include "vector.h"
#include <string>

namespace py = pybind11;

class Matrix 
{
    int numRows;
    int numCols;
    std::vector<Vector> data;

    public:
        Matrix(int numRows, int numCols) 
        {
            this->data = std::vector<Vector>(numRows, Vector(numCols));
        }

        void setValues(py::list data)
        {
            for (int i = 0; i < numRows; i++) 
            {

                if (py::len(data[i]) != numCols) 
                {
                    throw std::invalid_argument("Number of columns in row " + std::to_string(i) + " does not match expected. Expected " + std::to_string(numCols) + " but got " + std::to_string(py::len(data[i])));
                }

                Vector row = Vector(numCols);

                row.setValues(data[i]);

                this->data[i] = row;
            }
        }
        
        int getNumRows() 
        {
            return data.size();
        }

        int getNumCols() 
        {
            return data[0].getSize();
        }
        
        std::pair<int, int> getSize() 
        {
            // the actual shape
            return {getNumRows(), getNumCols()};
        }

        std::string toString() 
        {
            std::string result = "[";

            for (int i = 0; i < (data.size() - 1); i++) 
            {
                result += data[i].toString() + ", " +"\n";
            }

            result += data[data.size() - 1].toString() + "]";

            return result;
        }

        void print() 
        {
            std::cout << toString() << std::endl;
        }

        Vector operator[](int index) 
        {
            if (index < 0 || index >= data.size()) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            return data[index];
        }
};
