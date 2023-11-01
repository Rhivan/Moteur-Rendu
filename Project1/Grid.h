#include <SDL.h>

class Grid {
public:
    Grid(SDL_Renderer* renderer);
    void Draw();

private:
    SDL_Renderer* renderer;
};