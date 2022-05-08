#pragma once

#include "ray.h"
#include "sphere.h"
#include <vector>

struct Scene {
    std::vector<Sphere*> spheres;

    Scene() { }

    void add(Sphere s)
    {
        spheres.push_back(new Sphere(s));
    }

    bool hit(Ray& ray, HitRecord& rec);
};