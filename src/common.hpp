#ifndef RAY_TRACING_COMMON_HPP
#define RAY_TRACING_COMMON_HPP

#include <functional>
#include <limits>
#include <random>

// Common headers
#include "ray.hpp"
#include "vec3.hpp"

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions
inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180;
}

inline double ffmin(double a, double b)
{
    return a <= b ? a : b;
}

inline double ffmax(double a, double b)
{
    return a >= b ? a : b;
}

inline double random_double()
{
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    static std::function<double()> rand_generator =
        std::bind(distribution, generator);

    return rand_generator();
}

#endif