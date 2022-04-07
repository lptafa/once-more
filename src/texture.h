#pragma once

#include "math.h"

struct Texture {
    virtual Vec3 at(Vec3 uv) const = 0;
};

struct SolidColor : Texture {
    Vec3 color;
    SolidColor(Vec3 color)
        : color(color)
    {
    }
    Vec3 at(Vec3 uv) const {
        return color;
    }
};

struct CheckeredTexture : Texture {
    Vec3 at(Vec3 uv) const {
        float factor = 100;
        int dx = uv.x * factor;
        int dy = uv.y * factor;
        if ((dx + dy) % 2 == 0) {
            return Vec3(1, 1, 1);
        } else {
            return Vec3(0, 0, 0);
        }
    }
};