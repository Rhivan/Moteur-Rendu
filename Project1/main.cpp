// main.cpp
#include "Window.h"
#include "Object.h"
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>


using namespace std;

int main(int argc, char* argv[]) {
    Window window("Ma Fenêtre SDL", 800, 600);
    SDL_Renderer* renderer = window.GetRenderer();

    Object rectangle(renderer, 100, 100, 200, 100);

    bool quit = false;
    SDL_Event event;

    float speed = 100.0f;

    Uint32 lastTime;
    Uint32 beginTime;

    int fps = 0;
    int count = 0;

    Uint32 start = SDL_GetTicks();


    while (!quit) {
        //STARTLOOP

        beginTime = SDL_GetTicks();

        //EVENT
        while (SDL_PollEvent(&event)) {

            
            

            if (event.type == SDL_QUIT) {
                quit = true; 
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true; 
                }
                else if (event.key.keysym.sym == SDLK_RIGHT) {
                    //rectangle.MoveRight(speed * (deltaTime / 1000.0f));
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
        //UPDATE

        //DRAW
        window.Clear();

        rectangle.Draw();

        window.Present();

        SDL_Delay(1);

        //ENDLOOP
        lastTime = SDL_GetTicks();

        Uint32 deltaTime = lastTime - beginTime;

        fps++;

        if (SDL_GetTicks() - start >= 1000) {
			start = SDL_GetTicks();
			cout << fps << endl;
			fps = 0;
		}            
    }

    return 0;
}
