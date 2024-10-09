#pragma once
#include "global.h"
class Mouse
{
public:
	SDL_Texture* texture;
	SDL_Rect rect; //for image
	SDL_Rect point; //for contact precision

	Mouse(SDL_Renderer* renderer);
	~Mouse();
	void update();
	void draw(SDL_Renderer* renderer);
};

