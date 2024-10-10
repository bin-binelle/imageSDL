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
extern const int WIDTH;
extern const int HEIGHT;
extern const int CARD_SIZE;
extern const int GAP;
extern const int NUM_IMAGES;
extern const int FLIP_DELAY;

struct Card {
    SDL_Texture* texture;
    bool isFlipped;
    bool isMatched;
    int pairId;
};

struct CardPair {
    std::string planetImage;
    std::string satelliteImage;
};

struct HighScore {
    int moves;
    Uint32 time;
};

HighScore loadHighScore(const std::string& filename);
void saveHighScore(const std::string& filename, const HighScore& highScore);
void initializeCards(std::vector<Card>& cards, SDL_Renderer* renderer);
void drawCards(SDL_Renderer* renderer, const std::vector<Card>& cards, bool showAll);
void displayResult(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, Uint32 elapsedTime, int moves, TTF_Font* font);
void playGame(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, TTF_Font* font, TTF_Font* resultFont);
void cleanupCards(std::vector<Card>& cards);
void cleanup(SDL_Texture* backgroundTexture);
void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color, int x, int y);

void initSDL();
void cleanupSDL();

#endif GLOBAL_H
