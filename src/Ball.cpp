#include "Ball.hpp"
#include "SdlWindow.hpp"

const int BALL_SIZE = 10;
const int MAX_X = WINDOW_WIDTH - BALL_SIZE;
const int MAX_Y = WINDOW_HEIGHT - BALL_SIZE;

const int START_POSX = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
const int START_POSY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;

Ball::Ball(Score* player1Score, Score* player2Score)
{
	resetPosition();
	this->rect.w = BALL_SIZE;
	this->rect.h = BALL_SIZE;
	this->xVel = -3;
	this->yVel = -3;

	this->player1Score = player1Score;
	this->player2Score = player2Score;
}

void Ball::run()
{
	this->rect.y += this->yVel;
	if (this->rect.y < 0)
	{
		this->rect.y = -this->rect.y;
		this->yVel = -this->yVel;
	}
	else if (this->rect.y >= MAX_Y)
	{
		this->rect.y -= (this->rect.y - MAX_Y) * 2;
		this->yVel = -this->yVel;
	}

	this->rect.x += this->xVel;
	if (this->rect.x < 0)
	{
		resetPosition();
		this->xVel = -this->xVel;
		this->player2Score->increment();
	}
	else if (this->rect.x >= MAX_X)
	{
		resetPosition();
		this->xVel = -this->xVel;
		this->player1Score->increment();
	}
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &this->rect);
}

void Ball::resetPosition()
{
	this->rect.x = START_POSX;
	this->rect.y = START_POSY;
}
