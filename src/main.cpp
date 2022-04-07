#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "image.h"
#include "ray.h"
#include "rng.h"
#include "scene.h"
#include "sphere.h"
#include "texture.h"

constexpr int MAX_DEPTH = 10;

Vec3 reflect_perfectly(const Vec3& dir, const Vec3& n)
{
    return dir - 2 * dot(dir, n) * n;
}

Vec3 raytrace(Scene& scene, Ray& ray)
{
    HitRecord rec;
    const Vec3 sky_color = Vec3(173, 237, 255) / 255;

    Vec3 result = Vec3(1, 1, 1);

    for (int bounce = 0; bounce < MAX_DEPTH; ++bounce) {
        if (!scene.hit(ray, rec))
            return result * sky_color;

        Sphere* obj = rec.obj;
        result = result * obj->tex->at(rec.uv);

        Vec3 dir;

        if (obj->mat == Material::Diffuse)
            dir = random_vec_hemisphere(rec.normal);
        else if (obj->mat == Material::Mirror)
            dir = reflect_perfectly(ray.dir, rec.normal);
        else
            assert(false && "Unhandled material");

        ray.pos = rec.pos;
        ray.dir = dir;
    }

    return 0;
}

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 500;
    const int NUM_SAMPLES = 200;

    Image img = Image(WIDTH, HEIGHT);
    Camera cam = Camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0), 90);
    cam.set_resolution(WIDTH, HEIGHT);

    Scene scene;
    scene.add(Sphere(Vec3(0, -100.5, 1), 100, new SolidColor(Vec3(1, 0.6, 0.3)), Material::Diffuse));
    scene.add(Sphere(Vec3(-0.5, 0, 1), 0.5, new CheckeredTexture(), Material::Diffuse));
    scene.add(Sphere(Vec3(0.5, 0, 1), 0.5, new SolidColor(Vec3(1, 0.5, 0.5)), Material::Mirror));

    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            Vec3 col = Vec3();
            for (int sample = 0; sample < NUM_SAMPLES; ++sample) {
                Ray ray = cam.get_ray(i, HEIGHT - j - 1);
                col = col + raytrace(scene, ray);
            }
            img.set_pixel(i, j, col / NUM_SAMPLES);
        }
    }

    img.save("test.ppm");
}