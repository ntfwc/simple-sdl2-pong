#include "Ball.hpp"
#include "SdlWindow.hpp"

const int BALL_SIZE = 10;
const int MAX_X = WINDOW_WIDTH - BALL_SIZE;
const int MAX_Y = WINDOW_HEIGHT - BALL_SIZE;

const int START_POSX = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
const int START_POSY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;

const int STARTING_X_SPEED = 3;
const int MAX_X_SPEED = 7;

Ball::Ball(Score* player1Score, Score* player2Score, Paddle* paddle1, Paddle* paddle2)
{
	resetPosition();
	this->rect.w = BALL_SIZE;
	this->rect.h = BALL_SIZE;
	this->xVel = -STARTING_X_SPEED;
	this->yVel = -3;

	this->player1Score = player1Score;
	this->player2Score = player2Score;

	this->paddle1 = paddle1;
	this->paddle2 = paddle2;
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

	const SDL_Rect* paddle1Rect = this->paddle1->getRect();
	if (SDL_HasIntersection(&this->rect, this->paddle1->getRect()))
	{
		handlePaddleCollision(paddle1Rect, true);
	}
	else
	{
		const SDL_Rect* paddle2Rect = this->paddle2->getRect();
		if (SDL_HasIntersection(&this->rect, paddle2Rect))
		{
			handlePaddleCollision(paddle2Rect, false);
		}
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

	this->xVel = this->xVel > 0 ? STARTING_X_SPEED : -STARTING_X_SPEED;
}

void Ball::handlePaddleCollision(const SDL_Rect* paddleRect, bool isLeft)
{
	//For now lets just reverse, boring I know
	SDL_Rect intersection;
	SDL_IntersectRect(paddleRect, &this->rect, &intersection);
	int correctionMult = isLeft ? 1 : -1;
	this->rect.x += correctionMult * intersection.w * 2;

	this->xVel = -(this->xVel + (this->xVel > 0 ? 1 : -1));
	if (this->xVel > MAX_X_SPEED)
		this->xVel = MAX_X_SPEED;
	else if (this->xVel < -MAX_X_SPEED)
		this->xVel = -MAX_X_SPEED;
}
