

#ifndef RAY_TRACING_HITTABLE_HPP
#define RAY_TRACING_HITTABLE_HPP

#include "ray.hpp"

struct hit_record
{
    vec3 p;
    vec3 normal;
    double t{0.0};
    bool front_face{false};

    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        // dot(r.direction(), outward_normal) > 0.0  => ray is inside the sphere
        // dot(r.direction(), outward_normal) <= 0.0 => ray is outside the
        // sphere
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
 public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const = 0;
};

#endif