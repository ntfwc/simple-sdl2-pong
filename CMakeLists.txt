cmake_minimum_required (VERSION 2.6)
project (SDL_Tutorial)
INCLUDE(FindPkgConfig)
set(CMAKE_CXX_STANDARD 11)

### Dependencies
find_package(SDL2 QUIET)
IF (NOT SDL2_FOUND)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
ELSE()
	# Some versions of the configuration have trailing spaces for the libraries
	string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
	set(SDL2_LDFLAGS ${SDL2_LIBRARIES}) 
ENDIF()
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_ttf QUIET)
IF (NOT SDL2_TTF_FOUND)
	PKG_SEARCH_MODULE(SDL2_TTF REQUIRED SDL2_ttf)
ELSE()
	set(SDL2_TTF_LDFLAGS ${SDL2_LIBRARIES}) 
ENDIF()
include_directories(${SDL2_TTF_INCLUDE_DIRS})

set(GAME_EXE pong)
add_executable(${GAME_EXE} src/main.cpp src/SdlSession.cpp src/SdlWindow.cpp src/Paddle.cpp src/InputManager.cpp src/Ball.cpp src/Score.cpp)
target_link_libraries(${GAME_EXE} ${SDL2_LDFLAGS} ${SDL2_TTF_LDFLAGS})
