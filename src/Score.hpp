#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class Score
{
	public:
		/**
		 * @param x The x position of the score display.
		 * @param y The y position of the score display.
		 */
		Score(int x, int y);
		void draw(TTF_Font*, SDL_Renderer*);
		void increment();
	private:
		int x;
		int y;
		int value;
};
