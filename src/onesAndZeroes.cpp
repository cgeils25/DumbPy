#include "dumbpyTypes.h"

Matrix ones(int numRows, int numCols)
{
    // Create a matrix filled with ones
    Matrix result = Matrix(numRows, numCols);
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < numCols; j++) 
        {
            result[i][j] = 1.0f;
        }
    }
    return result;
}

Vector ones(int numElements)
{
    // Create a vector filled with ones
    Vector result = Vector(numElements);
    for (int i = 0; i < numElements; i++) 
    {
        result[i] = 1.0f;
    }
    return result;
}

Matrix zeros(int numRows, int numCols)
{
    // Create a matrix filled with zeros
    Matrix result = Matrix(numRows, numCols);
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < numCols; j++) 
        {
            result[i][j] = 0.0f;
        }
    }
    return result;
}

Vector zeros(int numElements)
{
    // Create a vector filled with zeros
    Vector result = Vector(numElements);
    for (int i = 0; i < numElements; i++) 
    {
        result[i] = 0.0f;
    }
    return result;
}
