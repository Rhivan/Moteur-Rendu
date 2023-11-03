#pragma once

#include <SDL.h>

class Object
{
public:
	Object(SDL_Renderer* renderer, int x, int y, int width, int height);
	void Draw();

private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
};