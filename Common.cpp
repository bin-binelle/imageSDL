#include "global.h"

SDL_Renderer* renderer = nullptr;
double delta = 0.0;

void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        exit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        cout << "IMG_Init Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
}

void cleanupSDL() {
    IMG_Quit();
    SDL_Quit();
}