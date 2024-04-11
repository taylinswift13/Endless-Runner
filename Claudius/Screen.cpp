#include "Screen.h"
void Screen::Init(int width, int height)
{
	// Create a window of size (800 x 600)
	window = SDL_CreateWindow("Hello World",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_ALLOW_HIGHDPI);

	renderer = SDL_CreateRenderer(window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

Screen::~Screen()
{
	SDL_DestroyRenderer(renderer);
	// Destroy window (do not use delete window)
	SDL_DestroyWindow(window);
}