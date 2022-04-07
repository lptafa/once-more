#include "image.h"
#include <stdio.h>
#include <stdlib.h>

Image::Image(const char* filename)
{
}

Image::Image(int width, int height)
    : width(width)
    , height(height)
    , data(new float[width * height * 3])
{
}

void Image::save(const char* filename)
{
    unsigned char* data_char = new unsigned char[width * height * 3];
    for (int i = 0; i < width * height * 3; i++) {
        data_char[i] = (unsigned char)(data[i] * 255);
    }

    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return;
    }
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(data_char, 1, width * height * 3, fp);
    fclose(fp);
}

void Image::set_pixel(int i, int j, Vec3 const& color)
{
    int idx = (i + j * width) * 3;
    data[idx + 0] = color.x;
    data[idx + 1] = color.y;
    data[idx + 2] = color.z;
}

Vec3 Image::pixel(int i, int j)
{
    int idx = (i + j * width) * 3;
    return Vec3(
        data[idx + 0],
        data[idx + 1],
        data[idx + 2]);
}
