#include "scene.h"

bool Scene::hit(Ray &ray, HitRecord &rec)
{
    HitRecord temp;
    bool hitAnything = false;
    float closest = INFINITY;

    for (Sphere *sphere : spheres) {
        if (sphere->hit(ray, temp)) {
            hitAnything = true;
            if (temp.t < closest) {
                closest = temp.t;
                rec = temp;
            }
        }
    }

    return hitAnything;
}
