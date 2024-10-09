#include "GameState.h"

SDL_Window* GameState::window = SDL_CreateWindow("Home", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
SDL_Renderer* GameState::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

std::vector<Button*> GameState::buttons;

GameState* GameState::start = new Start;
GameState* GameState::menu = new Menu;
GameState* GameState::difficulty = new Difficulty;
GameState* GameState::welcome = new Welcome;
GameState* GameState::instruction = new Instruction;
GameState* GameState::funFact = new FunFact;
//GameState* GameState::game = new Game;
GameState* GameState::trivia = new Trivia;
GameState* GameState::currentGameState = nullptr;
Mouse* GameState::mouse = new Mouse(renderer);


void GameState::shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    cleanupSDL();
}

void GameState::baseUpdate()
{
    mouse->update();
}

GameState::GameState()
{
}

GameState::~GameState()
{
}



Start::Start()
{
    backgroundTexture = IMG_LoadTexture(renderer, "background.png");
    if (!backgroundTexture) {
        cout << "Menu Constructor: Load Background: " << SDL_GetError() << std::endl;
    }
    playButton = new Button("play button.png", "play_btn_glow.png", "play button.png", renderer);
    buttons.push_back(playButton);
}

Start::~Start()
{
    delete playButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Start::enter()
{
    cout << "Entered start state" << endl;
}

void Start::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (playButton->isSelected) {
                        currentGameState = menu;
                        menu->enter();
                        return;
                    }
                }
                break;
            }
        }

        baseUpdate();

        for (auto& button : buttons) {
            playButton->update();
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        for (auto& button : buttons) {
            playButton->draw(renderer);
        }
        mouse->draw(renderer);
        SDL_RenderPresent(renderer);
    }

}

void Start::exit()
{
}



Menu::Menu() {
    backgroundTexture = IMG_LoadTexture(renderer, "background.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    newGameButton = new Button("new game.png", "newgame_glow.png", "new game.png", renderer);
    buttons.push_back(newGameButton);
    if (!newGameButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    exitButton = new Button("exit.png", "exit_glow.png", "exit.png", renderer);
    buttons.push_back(exitButton);
    if (!exitButton) {
        cout << "Failed to create exit button: " << IMG_GetError() << endl;
    }

    newGameButton->rect = { 100, 200, 700, 400 };
    exitButton->rect = { 100, 350, 700, 400 };
}

Menu::~Menu()
{
    delete newGameButton;
    delete exitButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Menu::enter()
{
    cout << "Entered menu state" << endl;
}

void Menu::update()
{
        bool running = true;
        while (running) {
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    shutdown();
                    break;
                }

                if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                    if (newGameButton->isSelected) {
                        currentGameState = difficulty;
                    }
                    else if (exitButton->isSelected) {
                        shutdown();
                        running = false;
                    }
                }
            }

            baseUpdate();

            newGameButton->update();
            exitButton->update();

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            newGameButton->draw(renderer);
            exitButton->draw(renderer);
            mouse->draw(renderer);

            SDL_RenderPresent(renderer);
    }

}

void Menu::exit()
{
}



Difficulty::Difficulty()
{
    backgroundTexture = IMG_LoadTexture(renderer, "background.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    easyButton = new Button("easy_btn.png", "easy_btnglow.png", "easy_btn.png", renderer);
    buttons.push_back(easyButton);
    if (!easyButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    hardButton = new Button("hard_btn.png", "hard_btnglow.png", "hard_btn.png", renderer);
    buttons.push_back(hardButton);
    if (!hardButton) {
        cout << "Failed to create exit button: " << IMG_GetError() << endl;
    }

    easyButton->rect = { 100, 200, 700, 400 };
    hardButton->rect = { 100, 350, 700, 400 };
}

Difficulty::~Difficulty()
{
    delete easyButton;
    delete hardButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Difficulty::enter()
{
    cout << "Entered difficulty state" << endl;
}

void Difficulty::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (easyButton->isSelected) {
                    currentGameState = welcome;
                }
                else if (hardButton->isSelected) {
                    currentGameState = welcome;
                }
            }
        }

        baseUpdate();

        easyButton->update();
        hardButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        easyButton->draw(renderer);
        hardButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Difficulty::exit()
{
}



Welcome::Welcome()
{
    backgroundTexture = IMG_LoadTexture(renderer, "welcome bg.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    rightButton = new Button("arrow_rightGlow.png", "arrow_rightGlow.png", "arrow_rightGlow.png", renderer);
    buttons.push_back(rightButton);
    if (!rightButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    rightButton->rect = { 100, 200, 700, 400 };
}

Welcome::~Welcome()
{
    delete rightButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Welcome::enter()
{
    cout << "Entered welcome state" << endl;
}

void Welcome::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (rightButton->isSelected) {
                    currentGameState = instruction;
                }
            }
        }

        baseUpdate();

        rightButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        rightButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Welcome::exit()
{
}



Instruction::Instruction()
{
    backgroundTexture = IMG_LoadTexture(renderer, "welcome bg.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    leftButton = new Button("arrow_leftGlow.png", "arrow_leftGlow.png", "arrow_leftGlow.png", renderer);
    buttons.push_back(leftButton);
    if (!leftButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    rightButton = new Button("arrow_rightGlow.png", "arrow_rightGlow.png", "arrow_rightGlow.png", renderer);
    buttons.push_back(rightButton);
    if (!rightButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    leftButton->rect = { 100, 200, 700, 400 };
    rightButton->rect = { 100, 200, 700, 400 };
}

Instruction::~Instruction()
{
    delete leftButton;
    delete rightButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Instruction::enter()
{
    cout << "Entered instruction state" << endl;
}

void Instruction::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (leftButton->isSelected) {
                    currentGameState = welcome;
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (rightButton->isSelected) {
                    currentGameState = funFact;
                }
            }
        }

        baseUpdate();

        leftButton->update();
        rightButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        leftButton->draw(renderer);
        rightButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Instruction::exit()
{
}



FunFact::FunFact()
{
    backgroundTexture = IMG_LoadTexture(renderer, "welcome bg.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    backButton = new Button("arrow_back.png", "arrow_back.png", "arrow_back.png", renderer);
    buttons.push_back(backButton);
    if (!backButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    forwardButton = new Button("arrow_forward.png", "arrow_forward.png", "arrow_forward.png", renderer);
    buttons.push_back(forwardButton);
    if (!forwardButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    backButton->rect = { 100, 200, 700, 400 };
    forwardButton->rect = { 100, 200, 700, 400 };
}

FunFact::~FunFact()
{
    delete backButton;
    delete forwardButton;
    SDL_DestroyTexture(backgroundTexture);
}

void FunFact::enter()
{
    cout << "Entered fun fact state" << endl;
}

void FunFact::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (backButton->isSelected) {
                    currentGameState = instruction; //to change: should be to other fun fact window
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (forwardButton->isSelected) {
                    currentGameState = trivia; //should have start button, replace to game once connected
                }
            }
        }

        baseUpdate();

        backButton->update();
        forwardButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        backButton->draw(renderer);
        forwardButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }

}

void FunFact::exit()
{
}







Trivia::Trivia()
{
    backgroundTexture = IMG_LoadTexture(renderer, "laniakea supercluster.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    homeButton = new Button("arrow_forward.png", "arrow_forward.png", "arrow_forward.png", renderer);//make button
    buttons.push_back(homeButton);
    if (!homeButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    homeButton->rect = { 100, 200, 700, 400 };
}

Trivia::~Trivia()
{
    delete homeButton;
    SDL_DestroyTexture(backgroundTexture);
}

void Trivia::enter()
{
    cout << "Entered trivia state" << endl;
}

void Trivia::update()
{
    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                break;
            }

            
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (homeButton->isSelected) {
                    currentGameState = start; //should have start button
                }
            }
        }

        baseUpdate();

        homeButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        homeButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Trivia::exit()
{
}
