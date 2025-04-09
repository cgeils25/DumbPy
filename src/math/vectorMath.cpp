/**
 * Operations where vectors are the first or only argument
 */

#include "../vector.h"

float dotProduct(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    float result = 0;

    for (int i = 0; i < v1.getSize(); i++) 
    {
        result += v1[i] * v2[i];
    }

    return result;
}

Vector add(Vector& v1, float scalar)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] + scalar;
        result[i] = val;
    }

    return result;
}

Vector add(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] + v2[i];
        result[i] = val;
    }

    return result;
}

Vector subtract(Vector& v1, float scalar)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] - scalar;
        result[i] = val;
    }

    return result;
}

Vector subtract(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] - v2[i];
        result[i] = val;
    }

    return result;
}

Vector multiply(Vector& v1, float scalar)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] * scalar;
        result[i] = val;
    }

    return result;
}

Vector multiply(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] * v2[i];
        result[i] = val;
    }

    return result;
}

Vector divide(Vector& v1, float scalar)
{
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] / scalar;
        result[i] = val;
    }

    return result;
}

Vector divide(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v2[i] == 0) {
            throw std::invalid_argument("Division by zero");
            
            // not sure how to make this work:
            // throw PyExc_ZeroDivisionError("Division by zero");
        }
        float val = v1[i] / v2[i];
        result[i] = val;
    }

    return result;
}

Vector power(Vector& v, float exponent)
{
    // add error handling
    Vector result = Vector(v.getSize());

    for (int i = 0; i < v.getSize(); i++) 
    {
        float val = pow(v[i], exponent);
        result[i] = val;
    }

    return result;
}

Vector power(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = pow(v1[i], v2[i]);
        result[i] = val;
    }

    return result;
}

Vector sqrt(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] < 0) 
        {
            throw std::invalid_argument("Cannot take square root of negative number");
        }
        float val = sqrt(v1[i]);
        result[i] = val;
    }

    return result;
}

Vector exp(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = exp(v1[i]);
        result[i] = val;
    }

    return result;
}

Vector ln(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] <= 0) 
        {
            throw std::invalid_argument("Cannot take logarithm of number <= 0");
        }
        float val = log(v1[i]);
        result[i] = val;
    }

    return result;
}

Vector log(Vector& v1, float base)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] <= 0) 
        {
            throw std::invalid_argument("Cannot take logarithm of number <= 0");
        }
        float val = log(v1[i]) / log(base);
        result[i] = val;
    }

    return result;
}

Vector log(Vector& v1, Vector& base)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] <= 0) 
        {
            throw std::invalid_argument("Cannot take logarithm of number <= 0");
        }
        float val = log(v1[i]) / log(base[i]);
        result[i] = val;
    }

    return result;
}

float sum(Vector& v1)
{
    float total = 0;

    for (int i = 0; i < v1.getSize(); i++) 
    {
        total += v1[i];
    }

    return total;
}

float mean(Vector& v1)
{
    return sum(v1) / v1.getSize();
}

float variance(Vector& v1)
{
    float m = mean(v1);
    float total = 0;

    for (int i = 0; i < v1.getSize(); i++) 
    {
        total += pow(v1[i] - m, 2);
    }

    return total / v1.getSize();
}

float stddev(Vector& v1)
{
    return sqrt(variance(v1));
}

float product(Vector& v1)
{
    float total = v1[0];

    for (int i = 1; i < v1.getSize(); i++) 
    {
        total *= v1[i];
    }

    return total;
}

float min(Vector& v1)
{
    float minVal = v1[0];

    for (int i = 1; i < v1.getSize(); i++) 
    {
        if (v1[i] < minVal) 
        {
            minVal = v1[i];
        }
    }

    return minVal;
}

float max(Vector& v1)
{
    float maxVal = v1[0];

    for (int i = 1; i < v1.getSize(); i++) 
    {
        if (v1[i] > maxVal) 
        {
            maxVal = v1[i];
        }
    }

    return maxVal;
}
