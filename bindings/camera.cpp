#include <raytrace/camera.cpp>

#include "bindings.h"

void init_camera(py::module_ &m) {
    py::class_<Camera>(m, "Camera")
        .def(py::init<Vec3, Vec3, Vec3, float>())
        .def("set_resolution", &Camera::set_resolution)

        .def_readwrite("pos", &Camera::pos)
        .def_readwrite("u", &Camera::u)
        .def_readwrite("v", &Camera::v)
        .def_readwrite("w", &Camera::w)

        .def_readwrite("fov", &Camera::fov)
        .def_readwrite("corner", &Camera::corner)
        .def_readwrite("horizontal", &Camera::horizontal)
        .def_readwrite("vertical", &Camera::vertical)

    ;
}