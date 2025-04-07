/**
 * Operations where matrices are the first or only argument
 */

#include "../matrix.h"
#include <math.h>
#include <iostream>

Vector matMul(Matrix& m, Vector& v)
{
    if (m.getNumCols() != v.getSize()) 
    {
        throw std::invalid_argument("Matrix multiplication not possible. m columns: " + std::to_string(m.getNumCols()) + " != v size: " + std::to_string(v.getSize()));
    }

    Vector result = Vector(m.getNumRows());

    for (int i = 0; i < m.getNumRows(); i++) 
    {
        float total = 0;
        
        for (int j = 0; j < m.getNumCols(); j++) 
        {
            total += m[i][j] * v[j];
        }

        result[i] = total;
    }

    return result;
}

Matrix matMul(Matrix& m1, Matrix& m2)
{
    if (m1.getNumCols() != m2.getNumRows()) 
    {
        throw std::invalid_argument("Matrix multiplication not possible. m1 columns: " + std::to_string(m1.getNumCols()) + " != m2 rows: " + std::to_string(m2.getNumRows()));
    }

    Matrix result = Matrix(m1.getNumRows(), m2.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m2.getNumCols(); j++) 
        {
            float total = 0;
            
            for (int k = 0; k < m1.getNumCols(); k++) 
            {
                total += m1[i][k] * m2[k][j];
            }

            result[i][j] = total;
        }
    }

    return result;
}

Matrix add(Matrix& m1, float scalar)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] + scalar;
        }
    }

    return result;
}

Matrix add(Matrix& m1, Matrix& m2)
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrix addition not possible. m1: " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " != m2: " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {            
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

Matrix subtract(Matrix& m1, float scalar)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] - scalar;
        }
    }

    return result;
}

Matrix subtract(Matrix& m1, Matrix& m2)
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrix subtraction not possible. m1: " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " != m2: " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return result;
}

Matrix multiply(Matrix& m1, float scalar)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] * scalar;
        }
    }

    return result;
}

Matrix multiply(Matrix& m1, Matrix& m2)
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrix element-wise multiplication not possible. m1: " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " != m2: " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] * m2[i][j];
        }
    }

    return result;
}

Matrix divide(Matrix& m1, float scalar)
{
    if (scalar == 0) 
    {
        throw std::invalid_argument("Matrix division by zero");
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = m1[i][j] / scalar;
        }
    }

    return result;
}

Matrix divide(Matrix& m1, Matrix& m2)
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrix element-wise division not possible. m1: " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " != m2: " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            if (m2[i][j] == 0) 
            {
                throw std::invalid_argument("Matrix element-wise division by zero at position (" + std::to_string(i) + ", " + std::to_string(j) + ")");
            }
            result[i][j] = m1[i][j] / m2[i][j];
        }
    }

    return result;
}

//power sqrt exp ln log

Matrix power(Matrix& m1, float exponent)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = pow(m1[i][j], exponent);
        }
    }

    return result;
}

Matrix power(Matrix& m1, Matrix& m2)
{
    if (m1.getNumRows() != m2.getNumRows() || m1.getNumCols() != m2.getNumCols()) 
    {
        throw std::invalid_argument("Matrix element-wise power not possible. m1: " + std::to_string(m1.getNumRows()) + "x" + std::to_string(m1.getNumCols()) + " != m2: " + std::to_string(m2.getNumRows()) + "x" + std::to_string(m2.getNumCols()));
    }

    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = pow(m1[i][j], m2[i][j]);
        }
    }

    return result;
}

Matrix sqrt(Matrix& m1)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            if (m1[i][j] < 0) 
            {
                throw std::invalid_argument("Cannot take square root of negative number");
            }
            result[i][j] = sqrt(m1[i][j]);
        }
    }

    return result;
}

Matrix exp(Matrix& m1)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            result[i][j] = exp(m1[i][j]);
        }
    }

    return result;
}

Matrix ln(Matrix& m1)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            if (m1[i][j] <= 0) 
            {
                throw std::invalid_argument("Cannot take logarithm of number <= 0");
            }
            result[i][j] = log(m1[i][j]);
        }
    }

    return result;
} 

Matrix log(Matrix& m1, float base)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            if (m1[i][j] <= 0) 
            {
                throw std::invalid_argument("Cannot take logarithm of number <= 0");
            }
            result[i][j] = log(m1[i][j]) / log(base);
        }
    }

    return result;
} 

Matrix log(Matrix& m1, Matrix& base)
{
    Matrix result = Matrix(m1.getNumRows(), m1.getNumCols());

    for (int i = 0; i < m1.getNumRows(); i++) 
    {
        for (int j = 0; j < m1.getNumCols(); j++) 
        {
            if (m1[i][j] <= 0) 
            {
                throw std::invalid_argument("Cannot take logarithm of number <= 0");
            }
            if (base[i][j] <= 0) 
            {
                throw std::invalid_argument("Cannot take logarithm of base <= 0");
            }

            result[i][j] = log(m1[i][j]) / log(base[i][j]);
        }
    }

    return result;
} 

// float determinant(Matrix m)
// {
//     if (m.getNumRows() != m.getNumCols()) 
//     {
//         throw std::invalid_argument("Matrix must be square to calculate determinant");
//     }


// }