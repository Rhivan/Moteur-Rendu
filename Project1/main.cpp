// main.cpp
#include "Window.h"
#include "Object.h"
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include "Grid.h"

using namespace std;

int main(int argc, char* argv[]) {
    Window window("Ma Fenêtre SDL", 800, 600);
    SDL_Renderer* renderer = window.GetRenderer();

    Object rectangle(renderer, 100, 100, 200, 100);

    Grid grid(renderer);

    bool quit = false;
    SDL_Event event;

    float speed = 100.0f;

    Uint64 beginTime;

    int fps = 0;

    Uint64 start = SDL_GetPerformanceCounter();

    Uint64 startTime = SDL_GetPerformanceCounter();
    Uint64 lastTime = startTime;
    int frameCount = 0;

    while (!quit) {
        //STARTLOOP

        beginTime = SDL_GetPerformanceCounter();
        Uint64 currentTime = SDL_GetPerformanceCounter();
        int deltaTime = (int)(currentTime - lastTime) / SDL_GetPerformanceFrequency();

        float moveDistance = speed * (deltaTime / 1000.0f);


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
                    rectangle.MoveRight(moveDistance);
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

        grid.Draw();

        window.Present();

        SDL_Delay(1);

        //ENDLOOP

        frameCount++;

        
        

        if (deltaTime >= 1) {
            int fps = frameCount / deltaTime;
            cout << "FPS: " << fps << endl;

            frameCount = 0;
            lastTime = currentTime;
        }
    }
    return 0;
}
