#include <stdio.h>
#include <SDL.h>

#include "SdlSession.hpp"
#include "SdlWindow.hpp"

void mainLoop(SDL_Renderer* renderer)
{
	const SDL_Rect rect = {100, 100, 100, 100};

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
		}
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &rect);

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
