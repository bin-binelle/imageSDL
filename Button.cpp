#include "Button.h"

Button::Button(const char* normalTexturePath, const char* hoveredTexturePath, const char* clickedTexturePath, SDL_Renderer* renderer) {
    textureNormal = IMG_LoadTexture(renderer, normalTexturePath);
    textureHovered = IMG_LoadTexture(renderer, hoveredTexturePath);
    textureClicked = IMG_LoadTexture(renderer, clickedTexturePath);
    if (!textureNormal || textureHovered || textureClicked) {
        cout << "Failed to load texture: " << IMG_GetError() << endl;
    }
    rect = { 100, 110, 700, 400 };
}

Button::~Button() {
    SDL_DestroyTexture(textureNormal);
    SDL_DestroyTexture(textureHovered);
    SDL_DestroyTexture(textureClicked);
}

void Button::update() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    isSelected = (mouseX > rect.x && mouseX < rect.x + rect.w &&
        mouseY > rect.y && mouseY < rect.y + rect.h);
}

void Button::draw(SDL_Renderer* renderer) {
    SDL_Texture* textureToDraw = textureNormal;

    if (isSelected) {
        textureToDraw = textureHovered;
    }

    SDL_RenderCopy(renderer, textureToDraw, NULL, &rect);
}