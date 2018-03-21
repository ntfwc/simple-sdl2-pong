cmake_minimum_required (VERSION 2.6)
project (SDL_Tutorial)
INCLUDE(FindPkgConfig)
set(CMAKE_CXX_STANDARD 11)

### Dependencies
find_package(SDL2)
IF (NOT SDL2_FOUND)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
ENDIF()
include_directories(${SDL2_INCLUDE_DIRS})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

set(GAME_EXE pong)
add_executable(${GAME_EXE} src/main.cpp src/SdlSession.cpp src/SdlWindow.cpp src/Paddle.cpp src/InputManager.cpp)
target_link_libraries(${GAME_EXE} ${SDL2_LIBRARIES})
