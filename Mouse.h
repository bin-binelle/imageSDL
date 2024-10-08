#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include "global.h"

class Mouse {
    SDL_Texture* texture;
    SDL_Rect rect;

public:
    Mouse() {
       
        texture = IMG_LoadTexture(renderer, "mouse.png");
        if (!texture) {
            cout << "Failed to load texture: " << IMG_GetError() << endl;
        }

        rect.w = 300;
        rect.h = 300;
    
        SDL_ShowCursor(SDL_DISABLE);
    }

    ~Mouse() {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }

    void update() {
        SDL_GetMouseState(&rect.x, &rect.y);
        rect.x -= rect.w / 2;
        rect.y -= rect.h / 2;
        
    }

    void draw() {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    SDL_Rect getRect() {
        return rect;
    }
};

#endif MOUSE_H
