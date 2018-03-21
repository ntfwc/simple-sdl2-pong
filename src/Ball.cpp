#include "Ball.hpp"
#include "SdlWindow.hpp"

const int BALL_SIZE = 10;

Ball::Ball()
{
	rect.x = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
	rect.y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
	rect.w = BALL_SIZE;
	rect.h = BALL_SIZE;
}

void Ball::run()
{
	//Do nothing for now
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &this->rect);
}
