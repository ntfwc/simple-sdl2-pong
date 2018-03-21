#pragma once

#include <SDL.h>

#include "Score.hpp"

class Ball
{
	public:
		Ball(Score* player1Score, Score* player2Score);
		void run();
		void draw(SDL_Renderer*);
	private:
		SDL_Rect rect;
		int xVel;
		int yVel;
		Score* player1Score;
		Score* player2Score;
};
