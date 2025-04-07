#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

#include "dumbpyTypes.h"
#include "math/dumbpyMath.h"
#include "transformations/dumbpyTransformations.h"

bool allClose(Vector& v1, Vector& v2, float tolerance) 
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (fabs(v1[i] - v2[i]) > tolerance) 
        {
            return false;
        }
    }

    return true;
}

bool allClose(Matrix& m1, Matrix& m2, float tolerance) 
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrices must be of the same size. Instead got sizes " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " and " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        if (!allClose(m1[i], m2[i], tolerance)) 
        {
            return false;
        }
    }

    return true;
}