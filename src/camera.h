#pragma once

#include "math.h"
#include "ray.h"

struct Camera {
    Vec3 pos;
    Vec3 u, v, w;

    float fov;
    int width, height;

    Vec3 corner, horizontal, vertical;

    Camera(Vec3 pos, Vec3 dir, Vec3 up, float fov)
        : fov(fov)
    {
        // "Camera coordinate system"
        w = normalized(-dir);
        u = normalized(cross(up, w));
        v = cross(w, u);
    }
    void set_resolution(int width, int height);
    Ray get_ray(int i, int j);
};