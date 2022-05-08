#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

namespace py = pybind11;

void init_vec(py::module_ &m);
void init_image(py::module_ &m);
void init_camera(py::module_ &m);