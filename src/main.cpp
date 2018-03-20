#include <stdio.h>
#include <SDL.h>

#include "SdlSession.hpp"
#include "SdlWindow.hpp"

int main()
{
	SdlSession session;
	if (!session.init())
		return 1;
	SdlWindow window;
	if (!window.init("Pong"))
		return 2;
	SDL_Delay(2000);
	return 0;
}
