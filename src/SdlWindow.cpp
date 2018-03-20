#include "SdlWindow.hpp"

bool SdlWindow::init(const char* title)
{
	if ((this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) == nullptr)
		return false;
	return true;
}

SdlWindow::~SdlWindow()
{
	if (this->window != nullptr)
		SDL_DestroyWindow(this->window);
}

SDL_Window* SdlWindow::getWindow()
{
	return this->window;
}
