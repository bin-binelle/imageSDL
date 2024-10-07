#include "global.h"
#include "Mouse.h"

SDL_Renderer* renderer = nullptr;

int main(int argc, char* argv[]) {
	initSDL();
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 850, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Texture* texture = IMG_LoadTexture(renderer, "background.png");
	if (!texture) {
		cout << SDL_GetError() << endl;
	}

	Mouse mouse;
	bool running = true;
	double delta = .0001;
	double time = SDL_GetTicks();

	SDL_Rect position{ 50, 50, 1000, 600 };
	SDL_Rect area{ 0, 0, 600, 400};

	while (running) {
		delta = (SDL_GetTicks() - time) / 1000;
		time = SDL_GetTicks();

		SDL_Event e;
		//event loop

		while (SDL_PollEvent(&e)) {
			switch(e.type) {
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		mouse.update();
		SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
		SDL_RenderFillRect(renderer, &position);
		SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
		SDL_RenderDrawRect(renderer, &position);
		SDL_RenderCopy(renderer, texture, NULL, &area); //change into &area and &position later
		mouse.draw();
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	cleanupSDL();
	return 0;
}