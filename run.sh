#!/bin/bash

set -xe

g++ -std=c++17 src/*.cpp -o rt -Wall -O3
time ./rt "$@"