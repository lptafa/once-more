#include "camera.h"
#include <stdlib.h>

void Camera::set_resolution(int width, int height)
{
    this->width = width;
    this->height = height;

    float aspect = (float)width / (float)height;

    float theta = radians(fov);
    float ysize = 2 * tan(theta / 2.0);
    float xsize = ysize * aspect;

    horizontal = -xsize * u;
    vertical = ysize * v;
    corner = pos - horizontal / 2 - vertical / 2 - w;
}

Ray Camera::get_ray(int i, int j)
{
    float dx = (i + drand48()) / (float)width;
    float dy = (j + drand48()) / (float)height;

    return Ray(
        pos,
        normalized(corner + (dx * horizontal) + (dy * vertical) - pos));
}
