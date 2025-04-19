#include "dumbpyTypes.h"

Matrix identity(int size)
{
    // Create an identity matrix of shape (size, size)
    Matrix result = Matrix(size, size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                result[i][j] = 1.0f;
            } 
            else 
            {
                result[i][j] = 0.0f;
            }
        }
    }
    return result;
}
