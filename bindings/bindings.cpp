#include "bindings.h"

PYBIND11_MODULE(raytrace, m) {
    init_vec(m);
    init_image(m);
    init_camera(m);
}