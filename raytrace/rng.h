#pragma once

#include "math.h"
#include <stdlib.h>

inline Vec3 random_vec()
{
    return 2 * Vec3(drand48(), drand48(), drand48()) - 1;
}

inline Vec3 random_vec_sphere()
{
    Vec3 v;
    do {
        v = random_vec();
    } while (v.length2() >= 1);
    return normalized(v);
}

// Sample within the hemisphere of the normal, with cosine weight
inline Vec3 random_vec_hemisphere(const Vec3& n)
{
    return normalized(n + random_vec());
}