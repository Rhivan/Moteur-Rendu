#include "TextureRenderer.h"

using namespace std;

TextureRenderer::TextureRenderer(SDL_Renderer* renderer) : renderer(renderer) {
    // Initialise SDL_image au préalable
    IMG_Init(IMG_INIT_JPG);
}

TextureRenderer::~TextureRenderer() {
    // Libérez les textures chargées
    for (const auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
    }

    // Quitte SDL_image
    IMG_Quit();
}

bool TextureRenderer::LoadTexture(const std::string& filePath, const std::string& key) {
    if (textures[key]) {
        return false;
	}
    SDL_Surface* imageSurface = IMG_Load(filePath.c_str());
    if (imageSurface == nullptr) {
        // Gestion de l'erreur si le chargement de l'image échoue
        cout << "Erreur de chargement de l'image : " << IMG_GetError() << endl;
        return false;
    }

    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    if (imageTexture != nullptr) {
        textures[key] = imageTexture;
        return true;
    }

    return false;
}

void TextureRenderer::RenderTexture(const string& key, int x, int y) {
    SDL_Texture* texture = textures[key];
    if (texture != nullptr) {
        SDL_Rect destRect;
        destRect.x = x;
        destRect.y = y;
        SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
        SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    }
}
