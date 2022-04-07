#pragma once

#include <vector>
#include "sphere.h"
#include "ray.h"

struct Scene {
    std::vector<Sphere *> spheres;

    Scene() {}

    void add(Sphere s) {
        spheres.push_back(new Sphere(s));
    }

    bool hit(Ray &ray, HitRecord &rec);
};