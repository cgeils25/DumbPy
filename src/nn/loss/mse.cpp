#include "../../dumbpyTypes.h"
#include "../../math/dumbpyMath.h"

float meanSquaredError(float yTrue, float yPred)
{
    return pow(yTrue - yPred, 2);
}

float meanSquaredErrorDerivative(float yTrue, float yPred)
{
    return 2 * (yPred - yTrue);
}

float meanSquaredError(Vector& yTrue, Vector& yPred)
{
    if (yTrue.getSize() != yPred.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(yTrue.getSize()) + " and " + std::to_string(yPred.getSize()));
    }

    float mse = 0.0f;

    for (int i = 0; i < yTrue.getSize(); i++) 
    {
        mse += meanSquaredError(yTrue[i], yPred[i]);
    }

    return mse / yTrue.getSize();
}

Vector meanSquaredErrorGradient(Vector& yTrue, Vector& yPred)
{
    if (yTrue.getSize() != yPred.getSize()) 
    {
        throw std::invalid_argument("Vectors must be of the same size. Instead got sizes " + std::to_string(yTrue.getSize()) + " and " + std::to_string(yPred.getSize()));
    }

    Vector gradient = Vector(yTrue.getSize());

    for (int i = 0; i < yTrue.getSize(); i++) 
    {
        gradient[i] = meanSquaredErrorDerivative(yTrue[i], yPred[i]);
    }

    return gradient;
}
