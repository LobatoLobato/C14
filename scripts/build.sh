#!/bin/bash

ROOT_DIR=$(dirname $(dirname $(realpath "$0")))

cmake -S "$ROOT_DIR" -B "$ROOT_DIR/build" -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build "$ROOT_DIR/build" --target $1