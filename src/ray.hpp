#ifndef RAY_TRACING_RAY_HPP
#define RAY_TRACING_RAY_HPP

#include "vec3.hpp"

class ray
{
 public:
    ray() = default;

    ray(const vec3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {
        // Do nothing
    }

    vec3 origin() const
    {
        return orig;
    }

    vec3 direction() const
    {
        return dir;
    }

    vec3 at(double t) const
    {
        return orig + t * dir;
    }

    vec3 orig;
    vec3 dir;
};

#endif