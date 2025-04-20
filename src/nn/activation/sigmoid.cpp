#include "../../dumbpyTypes.h"
#include "../../math/dumbpyMath.h"
#include <math.h>

float sigmoid(float x) 
{
    if (x < -50.0f) 
    {
        return 0.0f;
    } 
    else if (x > 50.0f) 
    {
        return 1.0f;
    }

    return 1.0f / (1.0f + exp(-x));
}

float sigmoidDerivative(float x) 
{
    float sig = sigmoid(x);
    return sig * (1 - sig);
}

Vector sigmoid(Vector& v1) 
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = sigmoid(v1[i]);
        result[i] = val;
    }

    return result;
}

Matrix sigmoid(Matrix& m1) 
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            float val = sigmoid(m1[i][j]);
            result[i][j] = val;
        }
    }

    return result;
}

Vector sigmoidGradient(Vector& v1) 
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = sigmoidDerivative(v1[i]);
        result[i] = val;
    }

    return result;
}

Matrix sigmoidGradient(Matrix& m1) 
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            float val = sigmoidDerivative(m1[i][j]);
            result[i][j] = val;
        }
    }

    return result;
}
