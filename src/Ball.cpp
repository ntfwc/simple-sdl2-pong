#include "Ball.hpp"
#include "SdlWindow.hpp"

const int BALL_SIZE = 10;

Ball::Ball()
{
	rect.x = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
	rect.y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
	rect.w = BALL_SIZE;
	rect.h = BALL_SIZE;
	xVel = 0;
	yVel = -3;
}

void Ball::run()
{
	this->rect.y += this->yVel;
	if (this->rect.y < 0)
	{
		this->rect.y = -this->rect.y;
		this->yVel = -this->yVel;
	}
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &this->rect);
}
