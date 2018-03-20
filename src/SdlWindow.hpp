#pragma once
#include <SDL.h>

#include "SdlSession.hpp"

const int WINDOW_WIDTH = 480;
const int WINDOW_HEIGHT = 360;

class SdlWindow
{
	public:
		~SdlWindow();
		bool init(const char* title);
		SDL_Window* getWindow();
	private:
		SDL_Window* window;
};
