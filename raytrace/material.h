#pragma once

#include "ray.h"

struct Material {
    float roughness;

    Material(float roughness)
        : roughness(roughness)
    {
    }

    Vec3 sample_direction(Ray &ray, HitRecord &rec) const;
};
