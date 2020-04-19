// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in my
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on Ray Tracing in One Weekend book.
// References: https://raytracing.github.io

#include "common.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

#include <iostream>

vec3 ray_color(const ray& r, const hittable& world)
{
    hit_record rec;
    if (world.hit(r, 0, infinity, rec))
    {
        return 0.5 * (rec.normal + vec3(1, 1, 1));
    }

    const vec3 unit_direction = unit_vector(r.direction());
    const auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3{1.0, 1.0, 1.0} + t * vec3{0.5, 0.7, 1.0};
}

int main()
{
    const int image_width = 200;
    const int image_height = 100;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    const vec3 lower_left_corner{-2.0, -1.0, -1.0};
    const vec3 horizontal{4.0, 0.0, 0.0};
    const vec3 vertical{0.0, 2.0, 0.0};
    const vec3 origin{0.0, 0.0, 0.0};

    hittable_list world;
    world.add(std::make_shared<sphere>(vec3(0, 0, -1), 0.5));
    world.add(std::make_shared<sphere>(vec3(0, -100.5, -1), 100));

    for (int j = image_height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i)
        {
            const auto u = static_cast<double>(i) / image_width;
            const auto v = static_cast<double>(j) / image_height;
            ray r{origin, lower_left_corner + u * horizontal + v * vertical};

            vec3 color = ray_color(r, world);
            color.write_color(std::cout);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}