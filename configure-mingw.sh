#!/bin/sh
set -e
[ -e build-mingw ] || mkdir build-mingw
cd build-mingw

MINGW_SDL2_DIR="/usr/local/custom/mingw/SDL2"
MINGW_SDL2_ttf_DIR="/usr/local/custom/mingw/SDL2_ttf"

REL_PKG_PATH="x86_64-w64-mingw32/lib/pkgconfig"

SDL2_PKG_PATH="$MINGW_SDL2_DIR/$REL_PKG_PATH"
SDL2_ttf_PKG_PATH="$MINGW_SDL2_ttf_DIR/$REL_PKG_PATH"

export PKG_CONFIG_PATH="$SDL2_PKG_PATH:$SDL2_ttf_PKG_PATH"

export CC="/usr/bin/x86_64-w64-mingw32-gcc"
export CXX="/usr/bin/x86_64-w64-mingw32-g++"
export CFLAGS="-pipe -O2"
export CXXFLAGS="$CFLAGS"

cmake -DCMAKE_SYSTEM_NAME=Windows -G Ninja ..
