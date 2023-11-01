#include "Grid.h"

const int GRID_SIZE = 4;
const int CELL_SIZE = 100;

Grid::Grid(SDL_Renderer* renderer) : renderer(renderer) {}

void Grid::Draw() {
    for (int x = 0; x <= GRID_SIZE; x++) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Couleur blanche.
        SDL_RenderDrawLine(renderer, x * CELL_SIZE, 0, x * CELL_SIZE, GRID_SIZE * CELL_SIZE);
    }

    for (int y = 0; y <= GRID_SIZE; y++) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Couleur blanche.
        SDL_RenderDrawLine(renderer, 0, y * CELL_SIZE, GRID_SIZE * CELL_SIZE, y * CELL_SIZE);
    }
}