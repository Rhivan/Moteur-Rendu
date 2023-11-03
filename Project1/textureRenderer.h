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

    // Charge une texture � partir d'un fichier et l'associe � une cl�
    bool LoadTexture(const string& filePath, const string& key);

    // Affiche une texture associ�e � une cl� � une position donn�e
    void RenderTexture(const string& key, int x, int y);

private:
    SDL_Renderer* renderer;
    map<string, SDL_Texture*> textures;
};
