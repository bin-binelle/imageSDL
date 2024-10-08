#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "Mouse.h"
class Button
{
public:
	SDL_Texture* texture;
	SDL_Rect rect;
	bool isSelected = false;

	Button(const char* texturePath, SDL_Renderer* renderer);
	~Button();
	void render(SDL_Renderer* renderer);
	bool isClicked(int mouseX, int mouseY);

	void update(Mouse&);

	void draw();

};
#endif BUTTON_H
