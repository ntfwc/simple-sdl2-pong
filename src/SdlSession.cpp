#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "SdlSession.hpp"

SdlSession::~SdlSession()
{
	if (this->ttfInitialized)
	{
		printf("Quitting SDL_ttf\n");
		TTF_Quit();
	}
	if (this->initialized)
	{
		printf("Quitting SDL\n");
		SDL_Quit();
	}
}

bool SdlSession::init()
{
	printf("Initializing SDL\n");
	if (!(this->initialized = SDL_Init(SDL_INIT_VIDEO) == 0))
	{
		printf("Failed to initialize SDL\n");
		return false;
	}
	printf("Initialized SDL\n");

	printf("Initializing SDL_ttf\n");
	if (!(this->ttfInitialized = TTF_Init() == 0))
	{
		printf("Failed to initialize SDL_ttf\n");
		return false;
	}
	printf("Initialized SDL_ttf\n");

	return true;
}
