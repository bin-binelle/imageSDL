#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL.h> 
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <vector> 
#include <algorithm> 
#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <random> 

using namespace std;

static int k = SDL_Init(SDL_INIT_EVERYTHING);

extern SDL_Renderer* renderer;
extern double delta;

void initSDL();
void cleanupSDL();

#endif GLOBAL_H
