#!/bin/sh
C_DLL_PATH="/usr/lib/gcc/x86_64-w64-mingw32/5.3-win32"
SDL2_DLL_PATH="/usr/local/custom/mingw/SDL2/x86_64-w64-mingw32/bin"
export WINEPATH="$SDL2_DLL_PATH;$C_DLL_PATH"

wine build-mingw/pong.exe
