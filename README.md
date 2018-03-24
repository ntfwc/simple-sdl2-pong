# Description
A simple clone of pong.

I wrote it for fun to improve my knowledge of C++ and SDL2. I streamed the main part of the development on Twitch TV.

# Features
* Two independently controlled paddles
* A ball with some physics
* Score tracking

# Dependencies
* SDL2
* SDL2_ttf

# Building
This is a cmake based project, you can build with the following:

	mkdir build
	cd build
	cmake ..
	make

There are also some convenience scripts you should be able to use if you are on Linux.

# Running
You must run the game with the "res" folder in your current directory. On Linux, if you used the above building steps, from the project directory, you can run it with:

	build/pong
