#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "image.h"
#include "camera.h"
#include "sphere.h"
#include "scene.h"
#include "ray.h"
#include "rng.h"

constexpr int MAX_DEPTH = 10;

Vec3 raytrace(Scene &scene, Ray& ray)
{
    HitRecord rec;
    const Vec3 sky_color = Vec3(173, 237, 255) / 255;

    Vec3 result = Vec3(1, 1, 1);

    for (int bounce = 0; bounce < MAX_DEPTH; ++bounce) {
        if (!scene.hit(ray, rec))
            return result * sky_color;

        result = result * rec.obj->color;

        Vec3 dir = random_vec_hemisphere(rec.normal);
        ray.pos = rec.pos;
        ray.dir = dir;
    }

    return 0;
}


int main() {
    const int WIDTH = 800;
    const int HEIGHT = 500;
    const int NUM_SAMPLES = 25;

    Image img = Image(WIDTH, HEIGHT);
    Camera cam = Camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0), 90);
    cam.set_resolution(WIDTH, HEIGHT);

    Scene scene;
    scene.add(Sphere(Vec3(0, -100.5, 1), 100, Vec3(1, 0.6, 0.3)));
    scene.add(Sphere(Vec3(0, 0, 1), 0.5, Vec3(0.5, 0.5, 0.5)));

    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            Vec3 col = Vec3();
            for (int sample = 0; sample < NUM_SAMPLES; ++sample) {
                Ray ray = cam.get_ray(i, HEIGHT-j-1);
                col = col + raytrace(scene, ray);
            }
            img.set_pixel(i, j, col / NUM_SAMPLES);
        }
    }

    img.save("test.ppm");
}