#include "../matrix.h"
#include <math.h>

Matrix MatMul(Matrix m1, Matrix m2)
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

            result[i].setValue(j, total);
        }
    }

    return result;
}