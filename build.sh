#!/bin/sh
SCRIPT_DIR=$(dirname "$0")
cd "$SCRIPT_DIR"

[ -e build ] || ./configure.sh

cd build
ninja
