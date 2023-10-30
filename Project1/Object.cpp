#include "Object.h"

Object::Object(SDL_Renderer* renderer, int x, int y, int width, int height)
	: renderer(renderer) {

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}

void Object::Draw() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Object::MoveRight(int distance) {
	rect.x += distance;
}