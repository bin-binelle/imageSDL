#include "global.h"
#include "Mouse.h"
#include "Button.h"

int main(int argc, char* argv[]) {
    initSDL();
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 850, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Texture* texture = IMG_LoadTexture(renderer, "background.png");
    if (!texture) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    Button myButton("easy_btnglow.png", renderer);

    Mouse mouse;

    bool running = true;
    double delta = .0001;
    double time = SDL_GetTicks();



    SDL_Rect position{ 50, 50, 1000, 600 };  // Some other rectangle, unrelated to the button
    SDL_Rect area{ 0, 0, 600, 400 };  // Another unrelated area

    while (running) {


        delta = (SDL_GetTicks() - time) / 1000;
        time = SDL_GetTicks();

        SDL_Event event;

        // Event loop
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                    // Check if the button was clicked
                    if (myButton.isClicked(mouseX, mouseY)) {
                        std::cout << "Button clicked!" << std::endl;
                    }
                
                break;
            }
        }

        // Update mouse position
        mouse.update();

        // Rendering part
        SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
        SDL_RenderClear(renderer);

        /*SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
        SDL_RenderFillRect(renderer, &position);

        SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
        SDL_RenderDrawRect(renderer, &position);*/

        SDL_RenderCopy(renderer, texture, NULL, NULL);  // Rendering background

        // Render button and mouse
        myButton.render(renderer);
        mouse.draw();

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    cleanupSDL();

    return 0;
}
