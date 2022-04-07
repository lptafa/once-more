#include "sphere.h"

bool Sphere::hit(Ray &ray, HitRecord &rec)
{
    Vec3 oc = ray.pos - pos;

    // Derivation here:
    // https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    float a = dot(ray.dir, ray.dir);
    float b = 2 * dot(oc, ray.dir);
    float c = dot(oc, oc) - radius * radius;

    float discriminant = b * b - 4 * a * c;
    if (discriminant <= 0)
        return false;

    float temp = (-b - sqrt(discriminant)) / (2 * a);

    // Want to make sure that the intersection at least 0.001 away from the camera
    if (temp < 1e-3)
        temp = (-b + sqrt(discriminant)) / (2 * a);
    if (temp < 1e-3)
        return false;

    // Distance along the ray
    rec.t = temp;
    // Position of the intersection in 3D space
    rec.pos = ray.at(rec.t);
    // Normal at surface of intersection
    rec.normal = normalized(rec.pos - pos);
    rec.obj = this;
    // Compute UV coordinates for texture mapping
    rec.uv = Vec3(
        0.5 + atan2(rec.normal.z, rec.normal.x) / (2 * M_PI),
        0.5 + asin(rec.normal.y) / M_PI,
        0
    );

    return true;
}
