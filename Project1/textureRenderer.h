#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class TextureRenderer {
public:
    TextureRenderer(SDL_Renderer* renderer);
    ~TextureRenderer();

    // Charge une texture à partir d'un fichier et l'associe à une clé
    bool LoadTexture(const string& filePath, const string& key);

    // Affiche une texture associée à une clé à une position donnée
    void RenderTexture(const string& key, int x, int y);

private:
    SDL_Renderer* renderer;
    map<string, SDL_Texture*> textures;
};
