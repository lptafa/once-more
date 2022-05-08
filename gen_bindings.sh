#!/bin/bash

CFLAGS="-Wall -Werror -std=c++11 -fpic -undefined dynamic_lookup -lm"


set -xe

g++ -shared $CFLAGS -I . $(python3 -m pybind11 --includes) -o raytrace.so \
    bindings/bindings.cpp \
    bindings/vec.cpp \
    bindings/image.cpp \
    bindings/camera.cpp \

