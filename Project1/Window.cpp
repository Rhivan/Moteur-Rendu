// Window.cpp
#include "Window.h"
#include <SDL_ttf.h>

// Le constructeur de la classe Window est appelé lorsqu'une instance de Window est créée.
// Il initialise la bibliothèque SDL2, crée une fenêtre et un rendu (renderer) associé.
Window::Window(const char* title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);  // Initialise la bibliothèque SDL2 pour la gestion graphique.
    TTF_Init();
    
    // Crée une fenêtre avec le titre spécifié, les dimensions (largeur et hauteur) et le drapeau SDL_WINDOW_SHOWN.
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    // Crée un renderer pour la fenêtre qui permet de dessiner des graphiques.
    // L'argument -1 indique que le premier rendu disponible doit être utilisé.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// Le destructeur est appelé lorsque l'objet Window est détruit, généralement lorsque la portée de l'objet se termine.
// Il libère les ressources associées à la fenêtre et au rendu, puis quitte la bibliothèque SDL2.
Window::~Window() {
    SDL_DestroyRenderer(renderer);  // Libère le rendu.
    SDL_DestroyWindow(window);      // Libère la fenêtre.
    TTF_Quit();                     // Quitte la bibliothèque SDL2_ttf.
    SDL_Quit();                     // Quitte la bibliothèque SDL2.
}

// La fonction Clear() est utilisée pour effacer le contenu de la fenêtre en remplissant la zone avec une couleur spécifique.
// Ici, nous remplissons la fenêtre avec du noir (0, 0, 0, 255), qui signifie une couleur noire opaque.
void Window::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Définit la couleur de dessin à noir.
    SDL_RenderClear(renderer);                      // Efface la fenêtre avec la couleur actuelle.
}

// La fonction Present() est utilisée pour mettre à jour l'affichage en montrant le contenu rendu à l'écran.
void Window::Present() {
    SDL_RenderPresent(renderer);  // Montre le contenu du rendu sur l'écran.
}

// La fonction IsClosed() est utilisée pour vérifier si l'utilisateur a fermé la fenêtre en cliquant sur la croix de fermeture.
// Elle parcourt la file d'événements SDL et renvoie true si un événement SDL_QUIT est détecté.
bool Window::IsClosed() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true; // La fenêtre est fermée.
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            return true; // L'utilisateur a appuyé sur la touche "Escape".
        }
    }
    return false; // La fenêtre n'est pas fermée.
}

SDL_Renderer* Window::GetRenderer() {
    return renderer;
}