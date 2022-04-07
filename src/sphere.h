#pragma once

#include "ray.h"

struct Sphere {
    Vec3 pos;
    Vec3 color;
    float radius;

    Sphere(Vec3 pos, float radius, Vec3 color)
        : pos(pos)
        , color(color)
        , radius(radius)
    {}

    bool hit(Ray &ray, HitRecord &rec);
};