#include "../scalar.h"
#include <math.h>

Scalar scalarAdd(Scalar s1, Scalar s2)
{
    return Scalar(s1.getValue() + s2.getValue());
}

Scalar scalarSubtract(Scalar s1, Scalar s2)
{
    return Scalar(s1.getValue() - s2.getValue());
}

Scalar scalarMultiply(Scalar s1, Scalar s2)
{
    return Scalar(s1.getValue() * s2.getValue());
}

Scalar scalarDivide(Scalar s1, Scalar s2)
{
    if (s2.getValue() == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Scalar(s1.getValue() / s2.getValue());
}

Scalar scalarPower(Scalar s1, Scalar s2)
{
    return Scalar(pow(s1.getValue(), s2.getValue()));
}

Scalar scalarSqrt(Scalar s1)
{
    if (s1.getValue() < 0) {
        throw std::invalid_argument("Cannot take square root of negative number");
    }
    return Scalar(sqrt(s1.getValue()));
} 

Scalar scalarExp(Scalar s1)
{
    return Scalar(exp(s1.getValue()));
}

Scalar scalarLn(Scalar s1)
{
    if (s1.getValue() <= 0) {
        throw std::invalid_argument("Cannot take logarithm of number <= 0");
    }
    return Scalar(log(s1.getValue()));
}

Scalar scalarLog(Scalar s1, Scalar base)
{
    if (s1.getValue() <= 0) {
        throw std::invalid_argument("Cannot take logarithm of number <= 0");
    }
    return Scalar(log(s1.getValue()) / log(base.getValue()));
} 

