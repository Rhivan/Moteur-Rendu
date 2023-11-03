#include "Window.h"
#include "Object.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <iostream>

#include "Move.h"
#include "textureRenderer.h"

using namespace std;

int main(int argc, char* argv[]) {
    Window window("2048 Destiny 2", 800, 600);
    SDL_Renderer* renderer = window.GetRenderer();

    srand(time(0));

    TextureRenderer textureRenderer(renderer); // Créez une instance de TextureRenderer

    if (textureRenderer.LoadTexture("images/2.jpg", "2")) {
        // La texture "2" a été chargée avec succès
        cout << "2" << endl;
    }
    if (textureRenderer.LoadTexture("images/4.jpg", "4")){
        	// La texture "4" a été chargée avec succès
        cout << "4" << endl;
	}
    if (textureRenderer.LoadTexture("images/8.jpg", "8")) {
		// La texture "8" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/16.jpg", "16")) {
		// La texture "16" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/32.jpg", "32")) {
		// La texture "32" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/64.jpg", "64")) {
		// La texture "64" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/128.jpg", "128")) {
		// La texture "128" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/256.jpg", "256")) {
		// La texture "256" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/512.jpg", "512")) {
		// La texture "512" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/1024.jpg", "1024")) {
		// La texture "1024" a été chargée avec succès
	}
    if (textureRenderer.LoadTexture("images/2048.jpg", "2048")) {
		// La texture "2048" a été chargée avec succès
	}
    else {
		// La texture n'a pas été chargée
    }

    int rows = 4;
    int cols = 4;
    Data_Grid dataGrid(rows, cols);
    Move move;

    for (int count = 0; count < 2; count++) {
        dataGrid.generateRandomCell();
    }

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

        if (move.moved == true) {
            dataGrid.updateMergedCells();
            dataGrid.updateEmptyCells();
            dataGrid.generateRandomCell();
            dataGrid.clearCheckGameOver();
            move.moved = false;
        }

        //EVENT
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    move.moveRight(dataGrid);
				}
                else if (event.key.keysym.sym == SDLK_LEFT) {
                    move.moveLeft(dataGrid);
                }
				else if (event.key.keysym.sym == SDLK_UP) {
                    move.moveUp(dataGrid);
                }
				else if (event.key.keysym.sym == SDLK_DOWN) {
                    move.moveDown(dataGrid);
                }
                else if (event.key.keysym.sym == SDLK_SPACE) {
                    dataGrid.display();

                }
                else if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
            }
        }
        //UPDATE

        //DRAW
        window.Clear();
        for (int i = 0; i < dataGrid.rows; ++i) {
            for (int j = 0; j < dataGrid.cols; ++j) {
                int nbrImg;
                if (dataGrid.dataGrid[i][j].isEmptyCell()) {

                }
                else {
                    textureRenderer.RenderTexture(to_string(dataGrid.dataGrid[i][j].getValue()), j * 96, i * 96);
                }

                Object rectangle(renderer, j * 96, i * 96, 96, 96);
                rectangle.Draw();

            }
        }

        window.Present();

        // Vérifie si le jeu est terminé
        if (dataGrid.isGameOver()) {
            cout << "Game Over" << endl;
            break;
        }
        SDL_Delay(1);

        //ENDLOOP

        frameCount++;

        if (deltaTime >= 1) {
            int fps = frameCount;
            cout << "FPS: " << fps << endl;

            frameCount = 0;
            lastTime = currentTime;
        }
    }
    return 0;
}
