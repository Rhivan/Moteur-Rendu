#pragma once

#include <SDL.h>

class Window
{
public:
	Window(const char* title, int width, int height);
	~Window();
	void Clear();
	void Present();
	bool IsClosed();
	SDL_Renderer* GetRenderer();

private :
	SDL_Window* window;
	SDL_Renderer* renderer;
};