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

find_package(SDL2_ttf)
IF (NOT SDL2_TTF_FOUND)
	PKG_SEARCH_MODULE(SDL2_TTF REQUIRED SDL2_ttf)
ENDIF()
include_directories(${SDL2_TTF_INCLUDE_DIRS})

set(GAME_EXE pong)
add_executable(${GAME_EXE} src/main.cpp src/SdlSession.cpp src/SdlWindow.cpp src/Paddle.cpp src/InputManager.cpp src/Ball.cpp)
target_link_libraries(${GAME_EXE} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
