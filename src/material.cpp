#include "material.h"
#include "rng.h"

Vec3 reflect_perfectly(const Vec3& dir, const Vec3& n)
{
    return dir - 2 * dot(dir, n) * n;
}

Vec3 Material::sample_direction(Ray &ray, HitRecord &rec) const
{
    Vec3 diff = random_vec_hemisphere(rec.normal);
    Vec3 refl = reflect_perfectly(ray.dir, rec.normal);
    return lerp(this->roughness, refl, diff);
}