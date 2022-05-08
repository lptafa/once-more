#include <raytrace/image.cpp>

#include "bindings.h"

void init_image(py::module_ &m) {
    py::class_<Image>(m, "Image")
        .def(py::init<int, int>())
        .def("load", [](const char *filename) {
            return Image(filename);
        })
        .def("save", &Image::save)

        .def_readwrite("width", &Image::width)
        .def_readwrite("height", &Image::height)

        .def("set", &Image::set_pixel)
        .def("get", &Image::pixel)
    ;
}