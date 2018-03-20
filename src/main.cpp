#include <stdio.h>
#include <SDL.h>

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return 1;
	printf("Hello, World!\n");
	SDL_Quit();
	return 0;
}
