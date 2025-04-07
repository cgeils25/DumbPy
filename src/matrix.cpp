#include <pybind11/pybind11.h>
#include <iostream>
#include "vector.h"
#include <string>

namespace py = pybind11;

class Matrix 
{
    /*
    A 2D Matrix class filled with floats. Each row is a vector.
    */
    int numRows;
    int numCols;
    std::vector<Vector> data;

    public:
        Matrix(int numRows, int numCols) 
        {
            this->data = std::vector<Vector>(numRows, Vector(numCols));
            this->numRows = numRows;
            this->numCols = numCols;
        }

        Matrix(py::list values) 
        {
            this->numRows = py::len(values);
            this->numCols = py::len(values[0]);
            this->data = std::vector<Vector>(numRows, Vector(numCols));

            setValuesMatrix(values);
        }

        void setValuesMatrix(py::list values)
        {
            for (int i = 0; i < numRows; i++) 
            {
                // check if the row is a list    
                if (!py::isinstance<py::list>(values[i])) 
                {
                    throw std::invalid_argument("Row " + std::to_string(i) + " is not a list");
                }

                // check if the row has the same number of columns as the first row
                if (py::len(values[i]) != numCols) 
                {
                    throw std::invalid_argument("Number of columns in row " + std::to_string(i) + " does not match expected. Expected " + std::to_string(numCols) + " but got " + std::to_string(py::len(values[i])));
                }

                Vector row = Vector(numCols);

                row.setValuesVector(values[i]);

                this->data[i] = row;
            }
        }
        
        int getNumRows() 
        {
            return this->numRows;
        }

        int getNumCols() 
        {
            return this->numCols;
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

        // if you don't return a reference here then assignment doesn't work and thus none of the operations work
        Vector& operator[](int index) 
        {
            if (index < 0 || index >= data.size()) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            return data[index];
        }

        float& operator[](py::tuple i_j) 
        {
            if (i_j.size() != 2) 
            {
                throw std::invalid_argument("Index must be a tuple of size 2");
            }

            int i = i_j[0].cast<int>();
            int j = i_j[1].cast<int>();

            if (i < 0 || i >= numRows || j < 0 || j >= numCols) 
            {
                // python automatically converts this to an IndexError
                throw std::out_of_range("Index out of range");
            }

            return data[i][j];
        }

        bool operator==(Matrix& other) 
        {
            if (this->numRows != other.getNumRows() || this->numCols != other.getNumCols()) 
            {
                return false;
            }

            for (int i = 0; i < this->numRows; i++) 
            {
                if (this->data[i] != other[i]) 
                {
                    return false;
                }
            }

            return true;
        }

        bool operator!=(Matrix& other) 
        {
            return !(*this == other);
        }
};
