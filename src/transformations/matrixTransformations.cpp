#include "../matrix.h"

Matrix transpose(Matrix& m)
{
    Matrix result = Matrix(m.getNumCols(), m.getNumRows());

    for (int i = 0; i < m.getNumRows(); i++) 
    {
        for (int j = 0; j < m.getNumCols(); j++) 
        {
            result[j].setValue(i, m[i][j]);
        }
    }

    return result;
}

