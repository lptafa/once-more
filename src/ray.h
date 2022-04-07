#pragma once

#include "math.h"

struct Sphere;

struct HitRecord {
    float t;
    Vec3 pos;
    Vec3 normal;
    Vec3 uv;
    Sphere* obj;
};

struct Ray {
    Vec3 pos;
    Vec3 dir;

    Ray(Vec3 const& pos, Vec3 const& dir)
        : pos(pos)
        , dir(dir)
    {
    }

    Vec3 at(float t) const
    {
        return pos + t * dir;
    }
};