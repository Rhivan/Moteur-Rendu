// Window.cpp
#include "Window.h"
#include <SDL_ttf.h>

// Le constructeur de la classe Window est appel� lorsqu'une instance de Window est cr��e.
// Il initialise la biblioth�que SDL2, cr�e une fen�tre et un rendu (renderer) associ�.
Window::Window(const char* title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);  // Initialise la biblioth�que SDL2 pour la gestion graphique.
    TTF_Init();
    
    // Cr�e une fen�tre avec le titre sp�cifi�, les dimensions (largeur et hauteur) et le drapeau SDL_WINDOW_SHOWN.
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    // Cr�e un renderer pour la fen�tre qui permet de dessiner des graphiques.
    // L'argument -1 indique que le premier rendu disponible doit �tre utilis�.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// Le destructeur est appel� lorsque l'objet Window est d�truit, g�n�ralement lorsque la port�e de l'objet se termine.
// Il lib�re les ressources associ�es � la fen�tre et au rendu, puis quitte la biblioth�que SDL2.
Window::~Window() {
    SDL_DestroyRenderer(renderer);  // Lib�re le rendu.
    SDL_DestroyWindow(window);      // Lib�re la fen�tre.
    TTF_Quit();                     // Quitte la biblioth�que SDL2_ttf.
    SDL_Quit();                     // Quitte la biblioth�que SDL2.
}

// La fonction Clear() est utilis�e pour effacer le contenu de la fen�tre en remplissant la zone avec une couleur sp�cifique.
// Ici, nous remplissons la fen�tre avec du noir (0, 0, 0, 255), qui signifie une couleur noire opaque.
void Window::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // D�finit la couleur de dessin � noir.
    SDL_RenderClear(renderer);                      // Efface la fen�tre avec la couleur actuelle.
}

// La fonction Present() est utilis�e pour mettre � jour l'affichage en montrant le contenu rendu � l'�cran.
void Window::Present() {
    SDL_RenderPresent(renderer);  // Montre le contenu du rendu sur l'�cran.
}

// La fonction IsClosed() est utilis�e pour v�rifier si l'utilisateur a ferm� la fen�tre en cliquant sur la croix de fermeture.
// Elle parcourt la file d'�v�nements SDL et renvoie true si un �v�nement SDL_QUIT est d�tect�.
bool Window::IsClosed() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true; // La fen�tre est ferm�e.
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            return true; // L'utilisateur a appuy� sur la touche "Escape".
        }
    }
    return false; // La fen�tre n'est pas ferm�e.
}

SDL_Renderer* Window::GetRenderer() {
    return renderer;
}