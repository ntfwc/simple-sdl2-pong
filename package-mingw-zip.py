#!/usr/bin/python3
import zipfile

MINGW_C_DLL_DIR="/usr/lib/gcc/x86_64-w64-mingw32/5.3-win32"
MINGW_SDL2_DLL_DIR="/usr/local/custom/mingw/SDL2/x86_64-w64-mingw32/bin"
MINGW_SDL2_TTF_DLL_DIR="/usr/local/custom/mingw/SDL2_ttf/x86_64-w64-mingw32/bin"

MINGW_C_DLLS=["libstdc++-6.dll", "libgcc_s_seh-1.dll"]
MINGW_SDL2_DLLS=["SDL2.dll"]
MINGW_SDL2_TTF_DLLS=["SDL2_ttf.dll", "libfreetype-6.dll", "zlib1.dll"]

OUT_FILE="/tmp/pong.zip"

def add(f, filePath, relative_arcname):
    f.write(filePath, arcname="pong/" + relative_arcname)

def addDlls(f, dllPath, dllList):
    for dll in dllList:
        add(f, dllPath + "/" + dll, dll)

def main():
    with zipfile.ZipFile(OUT_FILE, 'w', compression=zipfile.ZIP_DEFLATED) as f:
        add(f, "build-mingw/pong.exe", "pong.exe")
        add(f, "res", "res")
        addDlls(f, MINGW_C_DLL_DIR, MINGW_C_DLLS)
        addDlls(f, MINGW_SDL2_DLL_DIR, MINGW_SDL2_DLLS)
        addDlls(f, MINGW_SDL2_TTF_DLL_DIR, MINGW_SDL2_TTF_DLLS)

if __name__ == "__main__":
    main()
