#include <SDL.h>
#include <stdio.h>

#include "SdlSession.hpp"

SdlSession::~SdlSession()
{
	if (this->initialized)
	{
		printf("Quitting SDL\n");
		SDL_Quit();
	}
}

bool SdlSession::init()
{
	printf("Initializing SDL\n");
	if ((this->initialized = SDL_Init(SDL_INIT_VIDEO) == 0))
		printf("Initialized SDL\n");
	else
		printf("Failed to initialize SDL\n");
	return this->initialized;
}
