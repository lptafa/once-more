#include "bindings.h"

#include <raytrace/math.h>

namespace py = pybind11;

void init_vec(py::module_ &m) {
    py::class_<Vec3>(m, "Vec3")
        .def(py::init<float, float, float>())
        .def_readwrite("x", &Vec3::x)
        .def_readwrite("y", &Vec3::y)
        .def_readwrite("z", &Vec3::z)

        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self / py::self)
        .def(py::self * py::self)

        .def("__repr__", [](const Vec3 &v) {
            return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")";
        })

        .def("dot", &Vec3::dot)
        .def("cross", &Vec3::cross)
        .def("length", &Vec3::length)
        .def("length2", &Vec3::length2)
        .def("normalized", &Vec3::normalized)
        .def("abs", &Vec3::abs)

        .def("cwise_min", &Vec3::cwise_min)
        .def("cwise_max", &Vec3::cwise_max)

        .def("min_coeff", &Vec3::min_coeff)
        .def("max_coeff", &Vec3::max_coeff)

        .def("min_coeff_index", &Vec3::min_coeff_index)
        .def("max_coeff_index", &Vec3::max_coeff_index)

        .def(py::self * float())
        .def(py::self / float())
        .def(py::self + float())
        .def(py::self - float())


        .def(float() * py::self)
        .def(float() / py::self)
        .def(float() + py::self)
        .def(float() - py::self)
    ;
}