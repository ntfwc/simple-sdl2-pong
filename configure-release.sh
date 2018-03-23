#!/bin/sh
set -e
[ -e build-release ] || mkdir build-release
cd build-release

export CC="/usr/lib/ccache/clang"
export CXX="/usr/lib/ccache/clang++"
export CFLAGS="-pipe -O2"
export CXXFLAGS="$CFLAGS"

cmake -G Ninja ..
