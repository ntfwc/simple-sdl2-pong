#include "Paddle.hpp"

const int PADDLE_HEIGHT = 40;
const int PADDLE_WIDTH = 10;

Paddle::Paddle(int x, int y)
{
	rect.x = x;
	rect.y = y;
	rect.w = PADDLE_WIDTH;
	rect.h = PADDLE_HEIGHT;
}

SDL_Rect* Paddle::getRect()
{
	return &this->rect;
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &this->rect);
}