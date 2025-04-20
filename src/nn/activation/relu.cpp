#include "../../dumbpyTypes.h"

float relu(float x)
{
    return std::max(0.0f, x);
}

float reluDerivative(float x)
{
    if (x > 0) 
    {
        return 1.0f;
    } 
    else 
    {
        return 0.0f;
    }
}

Vector relu(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = std::max(0.0f, v1[i]);
        result[i] = val;
    }

    return result;
}

Vector reluGradient(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        result[i] = relu(v1[i]);
    }

    return result;
}

Matrix relu(Matrix& m1)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = relu(m1[i][j]);
        }
    }

    return result;
}

Matrix reluGradient(Matrix& m1)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = reluDerivative(m1[i][j]);
        }
    }

    return result;
}
