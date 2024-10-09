#include "Mouse.h"

Mouse::Mouse(SDL_Renderer *renderer)
{
    texture = IMG_LoadTexture(renderer, "mouse.png");
    rect = { 300, 300, 300, 300 };
    point = { 300, 300, 100, 100};
    if (!texture) {
        cout << "Failed to load texture: " << IMG_GetError() << endl;
    }

    SDL_ShowCursor(SDL_DISABLE);

}

Mouse::~Mouse()
{
}

void Mouse::update()
{
    SDL_GetMouseState(&rect.x, &rect.y);
    rect.x -= rect.w / 2;
    rect.y -= rect.h / 2;
    point.x = rect.x;
    point.y = rect.y;
}

void Mouse::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
