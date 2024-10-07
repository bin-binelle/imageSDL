#pragma once
#include "global.h"

class Mouse {
public:
    SDL_Texture* texture;
    SDL_Rect *rect;
    SDL_Rect* point;

    Mouse() {
        rect = new SDL_Rect();
        point = new SDL_Rect();

        texture = IMG_LoadTexture(renderer, "mouse.png");
        if (!texture) {
            cout << "Failed to load texture: " << IMG_GetError() << endl;
        }

        rect->w = 25;
        rect->h = 25;
        point->w = 1;
        point->h = 1;
        SDL_ShowCursor(false);
    }

    ~Mouse() {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
        delete rect;
        delete point;
    }

    void update() {
        SDL_GetMouseState(&rect->x, &rect->y);
        point->x = rect->x;
        point->y = rect->y;
    }

    void draw() {
        SDL_RenderCopy(renderer, texture, NULL, rect);
    }
};
