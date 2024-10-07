#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL_image.h>
#include <SDL.h>
#include <iostream>

using namespace std;

extern SDL_Renderer* renderer;
extern double delta;

void initSDL();
void cleanupSDL();

#endif GLOBAL_H
