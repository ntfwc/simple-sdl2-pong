#include <stdio.h>
#include <SDL.h>

#include "SdlSession.hpp"
#include "SdlWindow.hpp"
#include "Paddle.hpp"

void mainLoop(SDL_Renderer* renderer)
{
	Paddle paddle1(20, 100);

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
				if (e.key.keysym.sym == SDLK_UP)
					paddle1.inputMoveUp();
				else if (e.key.keysym.sym == SDLK_DOWN)
					paddle1.inputMoveDown(WINDOW_HEIGHT);
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);

		paddle1.draw(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}
}

int main()
{
	SdlSession session;
	if (!session.init())
		return 1;
	SdlWindow window;
	if (!window.init("Pong"))
		return 2;
	mainLoop(window.getRenderer());
	return 0;
}
