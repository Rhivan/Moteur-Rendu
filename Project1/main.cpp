// main.cpp
#include "Window.h"
#include "Object.h"
#include <SDL.h>

int main(int argc, char* argv[]) {
    Window window("Ma Fenêtre SDL", 800, 600);
    SDL_Renderer* renderer = window.GetRenderer();

    Object rectangle(renderer, 100, 100, 200, 100);

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        window.Clear();
        
        
        rectangle.Draw();

        window.Present();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true; 
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true; 
                }
                else if (event.key.keysym.sym == SDLK_RIGHT) {
                    rectangle.MoveRight(10); 
                }
                else if (event.key.keysym.sym == SDLK_LEFT) {
					rectangle.MoveRight(-10); 
				}
                else if (event.key.keysym.sym == SDLK_UP) {
                    rectangle.MoveUp(10);
                }
                else if (event.key.keysym.sym == SDLK_DOWN) {
					rectangle.MoveDown(10);
				}
            }
        }
    }

    return 0;
}
