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
        
        // Dessinez le rectangle rouge.
        rectangle.Draw();

        window.Present();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;  // L'utilisateur a cliqué sur la croix de fermeture.
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;  // L'utilisateur a appuyé sur la touche "Escape".
                }
                else if (event.key.keysym.sym == SDLK_RIGHT) {
                    rectangle.MoveRight(10); // Déplace le rectangle de 10 pixels vers la droite.
                }
            }
        }
    }

    return 0;
}
