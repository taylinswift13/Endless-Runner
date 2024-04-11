#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Screen
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	void Init(int width, int height);
	~Screen();
};

