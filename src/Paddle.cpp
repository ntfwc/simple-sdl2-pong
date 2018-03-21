#include "Paddle.hpp"
#include "SdlWindow.hpp"

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

void Paddle::inputMoveUp()
{
	this->rect.y -= 2;
	if (this->rect.y < 0)
		this->rect.y = 0;
}

void Paddle::inputMoveDown()
{
	this->rect.y += 2;
	if (this->rect.y + this->rect.h > WINDOW_HEIGHT)
		this->rect.y = WINDOW_HEIGHT - this->rect.h;
}
