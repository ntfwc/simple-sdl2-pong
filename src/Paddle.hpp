#pragma once

#include <SDL.h>

const int PADDLE_HEIGHT = 40;
const int PADDLE_WIDTH = 10;

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
		void inputMoveDown();
	private:
		SDL_Rect rect;
};
