#pragma once

#include <SDL.h>

class Paddle
{
	public:
		/**
		 * @param x The starting x position.
		 * @param y The starting y position.
		 */
		Paddle(int x, int y);

		SDL_Rect* getRect();

		void draw(SDL_Renderer* renderer);

		void inputMoveUp();
		void inputMoveDown(int windowHeight);
	private:
		SDL_Rect rect;
};
