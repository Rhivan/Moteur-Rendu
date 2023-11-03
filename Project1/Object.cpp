#include "Object.h"

Object::Object(SDL_Renderer* renderer, int x, int y, int width, int height)
	: renderer(renderer) {

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}

void Object::Draw() {
	SDL_RenderDrawRect(renderer, &rect); // Dessine le rectangle creux.
	SDL_SetRenderDrawColor(renderer, 255,255, 255, 255);
}
