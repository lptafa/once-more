#pragma once

#include "ray.h"
#include "texture.h"
#include "material.h"

struct Sphere {
    Vec3 pos;
    float radius;
    Texture* tex;
    Material *mat;

    Sphere(Vec3 pos, float radius, Texture* tex, Material *mat)
        : pos(pos)
        , radius(radius)
        , tex(tex)
        , mat(mat)
    {
    }

    bool hit(Ray& ray, HitRecord& rec);
};