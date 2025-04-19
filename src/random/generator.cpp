#include <random>
#include "../dumbpyTypes.h"

class RandomGenerator
{
    int seed;
    std::mt19937 generator;

    public:
        RandomGenerator(int seed) 
        {
            this->seed = seed;
            this->generator = std::mt19937(this->seed);
        }

        RandomGenerator() 
        {
            this->seed = std::random_device{}();
            this->generator = std::mt19937(this->seed);
        }

        int getSeed() 
        {
            return this->seed;
        }

        // uniform distribution
        Matrix uniform(int numRows, int numCols)
        {
            // uniform distribution defined on [0, 1)

            if (numRows <= 0 || numCols <= 0) 
            {
                throw std::invalid_argument("Number of rows and columns must be positive integers.");
            }
            
            std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
            Matrix result = Matrix(numRows, numCols);

            for (int i = 0; i < numRows; i++) 
            {
                for (int j = 0; j < numCols; j++) 
                {
                    result[i][j] = distribution(this->generator);
                }
            }

            return result;
        }

        Matrix uniform(int numRows, int numCols, float low, float high)
        {
            // uniform distribution defined on [low, high)

            if (numRows <= 0 || numCols <= 0) 
            {
                throw std::invalid_argument("Number of rows and columns must be positive integers.");
            }

            if (low >= high) 
            {
                throw std::invalid_argument("Lower bound must be less than high.");
            }
            
            std::uniform_real_distribution<float> distribution(low, high);
            Matrix result = Matrix(numRows, numCols);

            for (int i = 0; i < numRows; i++) 
            {
                for (int j = 0; j < numCols; j++) 
                {
                    result[i][j] = distribution(this->generator);
                }
            }

            return result;
        }

        Vector uniform(int numElements)
        {
            // uniform distribution defined on [0, 1)

            if (numElements <= 0) 
            {
                throw std::invalid_argument("Number of elements must be a positive integer.");
            }
            
            std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
            Vector result = Vector(numElements);

            for (int i = 0; i < numElements; i++) 
            {
                result[i] = distribution(this->generator);
            }

            return result;
        }

        Vector uniform(int numElements, float low, float high)
        {
            // uniform distribution defined on [low, high)

            if (numElements <= 0) 
            {
                throw std::invalid_argument("Number of elements must be a positive integer.");
            }

            if (low >= high) 
            {
                throw std::invalid_argument("Lower bound must be less than high.");
            }
            
            std::uniform_real_distribution<float> distribution(low, high);
            Vector result = Vector(numElements);

            for (int i = 0; i < numElements; i++) 
            {
                result[i] = distribution(this->generator);
            }

            return result;
        }

        // normal distribution
        Matrix normal(int numRows, int numCols)
        {
            // normal distribution with mean 0 and standard deviation 1

            if (numRows <= 0 || numCols <= 0) 
            {
                throw std::invalid_argument("Number of rows and columns must be positive integers.");
            }
            
            std::normal_distribution<float> distribution(0.0f, 1.0f);
            Matrix result = Matrix(numRows, numCols);

            for (int i = 0; i < numRows; i++) 
            {
                for (int j = 0; j < numCols; j++) 
                {
                    result[i][j] = distribution(this->generator);
                }
            }

            return result;
        }

        Matrix normal(int numRows, int numCols, float mean, float std)
        {
            // normal distribution with specified mean and standard deviation

            if (numRows <= 0 || numCols <= 0) 
            {
                throw std::invalid_argument("Number of rows and columns must be positive integers.");
            }

            if (std <= 0) 
            {
                throw std::invalid_argument("Standard deviation must be a positive number.");
            }
            
            std::normal_distribution<float> distribution(mean, std);
            Matrix result = Matrix(numRows, numCols);

            for (int i = 0; i < numRows; i++) 
            {
                for (int j = 0; j < numCols; j++) 
                {
                    result[i][j] = distribution(this->generator);
                }
            }

            return result;
        }

        Vector normal(int numElements)
        {
            // normal distribution with mean 0 and standard deviation 1

            if (numElements <= 0) 
            {
                throw std::invalid_argument("Number of elements must be a positive integer.");
            }
            
            std::normal_distribution<float> distribution(0.0f, 1.0f);
            Vector result = Vector(numElements);

            for (int i = 0; i < numElements; i++) 
            {
                result[i] = distribution(this->generator);
            }

            return result;
        }

        Vector normal(int numElements, float mean, float std)
        {
            // normal distribution with specified mean and standard deviation

            if (numElements <= 0) 
            {
                throw std::invalid_argument("Number of elements must be a positive integer.");
            }

            if (std <= 0) 
            {
                throw std::invalid_argument("Standard deviation must be a positive number.");
            }
            
            std::normal_distribution<float> distribution(mean, std);
            Vector result = Vector(numElements);

            for (int i = 0; i < numElements; i++) 
            {
                result[i] = distribution(this->generator);
            }

            return result;
        }
};
