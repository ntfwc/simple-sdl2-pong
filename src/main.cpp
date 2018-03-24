#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "SdlSession.hpp"
#include "SdlWindow.hpp"
#include "Paddle.hpp"
#include "InputManager.hpp"
#include "Ball.hpp"
#include "Score.hpp"

const int TARGET_FPS = 60;
const char* FONT_PATH = "res/ttf-bitstream-vera-1.10/VeraMono.ttf";

void mainLoop(SDL_Renderer* renderer, TTF_Font* font)
{
	InputManager inputManager;
	const int paddleStartY = WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2;
	Paddle paddle1(20, paddleStartY);
	Paddle paddle2(WINDOW_WIDTH - (20 + PADDLE_WIDTH), paddleStartY);

	Score player1Score(WINDOW_WIDTH/2 - 100, 20);
	Score player2Score(WINDOW_WIDTH/2 + 100, 20);
	Ball ball(&player1Score, &player2Score, &paddle1, &paddle2);

	const int centerX = WINDOW_WIDTH / 2;

	bool running = true;
	SDL_Event e;
	while (running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				inputManager.handleKeyDown(e.key.keysym.sym);
			}
			else if (e.type == SDL_KEYUP)
			{
				inputManager.handleKeyUp(e.key.keysym.sym);
			}
		}

		if (inputManager.isButtonDown(GameInputButton::PLAYER1_DOWN))
				paddle1.inputMoveDown();
		if (inputManager.isButtonDown(GameInputButton::PLAYER1_UP))
				paddle1.inputMoveUp();

		if (inputManager.isButtonDown(GameInputButton::PLAYER2_DOWN))
				paddle2.inputMoveDown();
		if (inputManager.isButtonDown(GameInputButton::PLAYER2_UP))
				paddle2.inputMoveUp();

		ball.run();
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);

		paddle1.draw(renderer);
		paddle2.draw(renderer);
		ball.draw(renderer);
		player1Score.draw(font, renderer);
		player2Score.draw(font, renderer);

		//Draw center dividing dotted line
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		for (int i = 0; i < WINDOW_HEIGHT; i += 4)
		{
			SDL_RenderDrawPoint(renderer, centerX, i);
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / TARGET_FPS);
	}
}

int main(int argc, char** argv)
{
	SdlSession session;
	if (!session.init())
		return 1;
	SdlWindow window;
	if (!window.init("Pong"))
		return 2;
	TTF_Font* font;
	if ((font = TTF_OpenFont(FONT_PATH, 16)) == nullptr)
	{
		printf("Failed to open the font: '%s'\n", FONT_PATH);
		return 3;
	}
	mainLoop(window.getRenderer(), font);
	TTF_CloseFont(font);
	return 0;
}
