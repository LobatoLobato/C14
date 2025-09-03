#!/bin/bash

ROOT_DIR=$(dirname $(dirname $(realpath "$0")))

"$ROOT_DIR/scripts/build.sh" $1
"$ROOT_DIR/build/$1/$1"