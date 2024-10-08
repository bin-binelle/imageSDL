#include "Button.h"

Button::Button(const char* texturePath, SDL_Renderer* renderer) {
    texture = IMG_LoadTexture(renderer, texturePath);
    if (!texture) {
        std::cout << "Failed to load texture: " << IMG_GetError() << std::endl;
        texture = nullptr; 
    }

    rect.x = 100; 
    rect.y = 100; 
    rect.w = 700; 
    rect.h = 300; 
}

Button::~Button() {
    if (texture) {
        SDL_DestroyTexture(texture); 
    }
}

void Button::render(SDL_Renderer* renderer) {
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

bool Button::isClicked(int mouseX, int mouseY) {
    return mouseX >= rect.x && mouseX <= rect.x + rect.w &&
        mouseY >= rect.y && mouseY <= rect.y + rect.h;
}

