#include <stdio.h>
#include <SDL.h>

#include "SdlSession.hpp"

int main()
{
	SdlSession session;
	if (!session.init())
		return 1;
	printf("Hello, World!\n");
	return 0;
}
