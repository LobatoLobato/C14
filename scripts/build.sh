#!/bin/bash

ROOT_DIR=$(dirname $(dirname $(realpath "$0")))

cmake -S "$ROOT_DIR" -B "$ROOT_DIR/build" -G "Ninja" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$ROOT_DIR/build" --target $1