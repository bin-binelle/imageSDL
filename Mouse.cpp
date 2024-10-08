//#include "Mouse.h"
//
//Mouse::Mouse() {
//    texture = IMG_LoadTexture(renderer, "mouse.png");
//    rect = new SDL_Rect{ 0, 0, 50, 50 };
//    SDL_ShowCursor(false);
//}
//
//void Mouse::update() {
//    SDL_GetMouseState(&rect->x, &rect->y);
//}
//
//void Mouse::draw() {
//    SDL_RenderCopy(renderer, texture, NULL, rect);
//}