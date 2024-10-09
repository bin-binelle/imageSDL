#pragma once
#include "global.h"

class Button {
public:
    SDL_Texture* textureNormal;
    SDL_Texture* textureHovered;
    SDL_Texture* textureClicked;
    SDL_Rect rect;
    bool isSelected = false;

    Button(const char* normalTexturePath, const char* hoveredTexturePath, const char* clickedTexturePath, SDL_Renderer* renderer);
    ~Button();
    void update();
    void draw(SDL_Renderer* renderer);
};
