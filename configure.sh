#!/bin/sh
set -e
[ -e build ] || mkdir build
cd build

SANITIZE_FLAGS="-fsanitize=address"

export CC="/usr/lib/ccache/clang"
export CXX="/usr/lib/ccache/clang++"
export CFLAGS="-pipe -g -O0 -Wall -Wextra $SANITIZE_FLAGS"
export CXXFLAGS="$CFLAGS"

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja ..

sed -i 's/'"$SANITIZE_FLAGS"'//' compile_commands.json
