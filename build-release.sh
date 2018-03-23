#!/bin/sh
SCRIPT_DIR=$(dirname "$0")
cd "$SCRIPT_DIR"

[ -e build-release ] || ./configure-release.sh

cd build-release
ninja
