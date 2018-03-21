#pragma once

#include <SDL.h>

class Ball
{
	public:
		Ball();
		void run();
		void draw(SDL_Renderer*);
	private:
		SDL_Rect rect;
};
