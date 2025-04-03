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

Vector vectorAdd(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] + v2[i];
        result.setValue(i, val);
    }

    return result;
}

Vector vectorSubtract(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] - v2[i];
        result.setValue(i, val);
    }

    return result;
}

Vector vectorMultiply(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = v1[i] * v2[i];
        result.setValue(i, val);
    }

    return result;
}

Vector vectorDivide(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v2[i] == 0) {
            throw std::invalid_argument("Division by zero");
        }
        float val = v1[i] / v2[i];
        result.setValue(i, val);
    }

    return result;
}

Vector vectorPower(Vector& v1, Vector& v2)
{
    if (v1.getSize() != v2.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(v1.getSize()) + " and " + std::to_string(v2.getSize()));
    }

    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = pow(v1[i], v2[i]);
        result.setValue(i, val);
    }

    return result;
}

Vector vectorSqrt(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] < 0) 
        {
            throw std::invalid_argument("Cannot take square root of negative number");
        }
        float val = sqrt(v1[i]);
        result.setValue(i, val);
    }

    return result;
}

Vector vectorExp(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        float val = exp(v1[i]);
        result.setValue(i, val);
    }

    return result;
}

Vector vectorLn(Vector& v1)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] <= 0) 
        {
            throw std::invalid_argument("Cannot take logarithm of number <= 0");
        }
        float val = log(v1[i]);
        result.setValue(i, val);
    }

    return result;
}

Vector vectorLog(Vector& v1, Vector& base)
{
    Vector result = Vector(v1.getSize());

    for (int i = 0; i < v1.getSize(); i++) 
    {
        if (v1[i] <= 0) 
        {
            throw std::invalid_argument("Cannot take logarithm of number <= 0");
        }
        float val = log(v1[i]) / log(base[i]);
        result.setValue(i, val);
    }

    return result;
}
