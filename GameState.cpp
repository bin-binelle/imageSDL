#include "GameState.h"

SDL_Window* GameState::window = SDL_CreateWindow("Home", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN/* || SDL_WINDOW_FULLSCREEN*/);
SDL_Renderer* GameState::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

std::vector<Button*> GameState::buttons;

GameState* GameState::start = new Start;
GameState* GameState::menu = new Menu;
GameState* GameState::difficulty = new Difficulty;
GameState* GameState::welcome = new Welcome;
GameState* GameState::instruction = new Instruction;
GameState* GameState::funFact = new FunFact;
GameState* GameState::memorygame = new MemoryGame;
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

    titleTexture = IMG_LoadTexture(renderer, "title.png");
    if (!titleTexture) {
        cout << "Menu Constructor: Load Background: " << SDL_GetError() << std::endl;
    }

    playButton = new Button("buttons/play button.png", "buttons/play_btn_glow.png", "buttons/play_darkened.png", renderer);
    buttons.push_back(playButton);

    playButton->rect = { 100, 200, 700, 400 };
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
        SDL_RenderCopy(renderer, titleTexture, NULL, NULL);
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

    newGameButton = new Button("buttons/new game.png", "buttons/newgame_glow.png", "buttons/new game.png", renderer);
    buttons.push_back(newGameButton);
    if (!newGameButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    leaderboardButton = new Button("buttons/leaderboard_normal.png", "buttons/leaderboard_glow.png", "buttons/leaderboard_normal", renderer);
    buttons.push_back(leaderboardButton);
    if (!leaderboardButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    exitButton = new Button("buttons/exit.png", "buttons/exit_glow.png", "buttons/exit.png", renderer);
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
                        currentGameState->enter();
                        return;
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

    easyButton = new Button("buttons/easy_btn.png", "buttons/easy_btnglow.png", "buttons/easy_btn.png", renderer);
    buttons.push_back(easyButton);
    if (!easyButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    hardButton = new Button("buttons/hard_btn.png", "buttons/hard_btnglow.png", "buttons/hard_btn.png", renderer);
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
                    currentGameState->enter();
                    return;
                }
                else if (hardButton->isSelected) {
                    currentGameState = welcome;
                    currentGameState->enter();
                    return;
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

    welcomeTexture = IMG_LoadTexture(renderer, "welcome message1.png");
    if (!welcomeTexture) {
        cout << "Menu Constructor: Load Background: " << SDL_GetError() << std::endl;
    }

    rightButton = new Button("buttons/arrow_rightGlow.png", "buttons/arrow_rightGlow.png", "buttons/arrow_rightGlow.png", renderer);
    buttons.push_back(rightButton);
    if (!rightButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    rightButton->rect = { 100, 100, 700, 400 };
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
                    currentGameState->enter();
                    return;
                }
            }
        }

        baseUpdate();

        rightButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        SDL_RenderCopy(renderer, welcomeTexture, NULL, NULL);
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

    instructionTexture = IMG_LoadTexture(renderer, "welcome message 2.png");
    if (!instructionTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    leftButton = new Button("buttons/arrow_leftGlow.png", "buttons/arrow_leftGlow.png", "buttons/arrow_leftGlow.png", renderer);
    buttons.push_back(leftButton);
    if (!leftButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    rightButton = new Button("buttons/arrow_rightGlow.png", "buttons/arrow_rightGlow.png", "buttons/arrow_rightGlow.png", renderer);
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
                    currentGameState->enter();
                    return;
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (rightButton->isSelected) {
                    currentGameState = funFact;
                    currentGameState->enter();
                    return;
                }
            }
        }

        baseUpdate();

        leftButton->update();
        rightButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        SDL_RenderCopy(renderer, instructionTexture, NULL, NULL);
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

    backButton = new Button("buttons/arrow_back.png", "buttons/arrow_back.png", "buttons/arrow_back.png", renderer);
    buttons.push_back(backButton);
    if (!backButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    forwardButton = new Button("buttons/arrow_forward.png", "buttons/arrow_forward.png", "buttons/arrow_forward.png", renderer);
    buttons.push_back(forwardButton);
    if (!forwardButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    startButton = new Button("buttons/start_level.png", "buttons/start_glow.png", "buttons/start_level.png", renderer);
    buttons.push_back(startButton);
    if (!startButton) {
        cout << "Failed to create new game button: " << IMG_GetError() << endl;
    }

    backButton->rect = { 100, 200, 700, 400 };
    forwardButton->rect = { 100, 200, 700, 400 };
    startButton->rect = { 100, 200, 700, 400 };
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
                    currentGameState->enter();
                    return;
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (forwardButton->isSelected) {
                    currentGameState = trivia;
                    currentGameState->enter();
                    return;
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                if (startButton->isSelected) {
                    currentGameState = memorygame;
                    currentGameState->enter();
                    return;
                }
            }
        }

        baseUpdate();

        backButton->update();
        forwardButton->update();
        startButton->update();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        backButton->draw(renderer);
        forwardButton->draw(renderer);
        startButton->draw(renderer);
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }

}

void FunFact::exit()
{
}


bool MemoryGame::isPointInRect(int x, int y, const SDL_Rect& rect) {
    return (x >= rect.x && x <= (rect.x + rect.w) &&
        y >= rect.y && y <= (rect.y + rect.h));
}

MemoryGame::MemoryGame()
{
    backgroundTexture = IMG_LoadTexture(renderer, "welcome bg.png");
    if (!backgroundTexture) {
        std::cout << "Failed to load memory game background: " << IMG_GetError() << std::endl;
    }

    matchedPairs = 0;
    currentSelections[0] = -1;
    currentSelections[1] = -1;

    for (int i = 0; i < 16; i++) {
        cardFlipped[i] = false;
    }

    loadCardTextures();
}

MemoryGame::~MemoryGame()
{
    SDL_DestroyTexture(backgroundTexture);
    for (auto& texture : cardTextures) {
        SDL_DestroyTexture(texture);
    }
}

void MemoryGame::enter()
{
    std::cout << "Entered memory game state" << std::endl;
    matchedPairs = 0;
    for (int i = 0; i < 16; i++) {
        cardFlipped[i] = false;
    }
}

void MemoryGame::update()
{
    bool running = true;

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdown();
                running = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;

                    for (int i = 0; i < 16; i++) {
                        if (!cardFlipped[i] &&
                            isPointInRect(mouseX, mouseY, cardPositions[i])) {

                            if (currentSelections[0] == -1) {
                                currentSelections[0] = i;
                            }
                            else if (currentSelections[1] == -1 && i != currentSelections[0]) {
                                currentSelections[1] = i;
                                checkForMatch();
                            }
                        }
                    }
                }
                break;
            }
        }

        baseUpdate();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        drawCards();
        mouse->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void MemoryGame::exit()
{
}


void MemoryGame::loadCardTextures()
{
    for (int i = 0; i < 8; i++) {
        std::string cardPath = "assets/card" + std::to_string(i + 1) + ".png";
        SDL_Texture* texture = IMG_LoadTexture(renderer, cardPath.c_str());
        if (texture) {
            cardTextures.push_back(texture);
            cardTextures.push_back(texture);
        }
        else {
            std::cout << "Failed to load card texture: " << IMG_GetError() << std::endl;
        }
    }

    // Shuffle card positions
    // (Add shuffling logic for card positions to randomize the pairs)
    cardPositions = {
        {100, 100, 100, 150}, {220, 100, 100, 150}, /*... positions for 16 cards */
    };
}

void MemoryGame::drawCards()
{
    for (int i = 0; i < 16; i++) {
        if (cardFlipped[i]) {
            SDL_RenderCopy(renderer, cardTextures[i], NULL, &cardPositions[i]);
        }
        else {
            SDL_Texture* cardBackTexture = IMG_LoadTexture(renderer, "assets/card_back.png");
            SDL_RenderCopy(renderer, cardBackTexture, NULL, &cardPositions[i]);
            SDL_DestroyTexture(cardBackTexture);
        }
    }
}

void MemoryGame::checkForMatch()
{
    if (cardTextures[currentSelections[0]] == cardTextures[currentSelections[1]]) {
        std::cout << "Match found!" << std::endl;
        cardFlipped[currentSelections[0]] = true;
        cardFlipped[currentSelections[1]] = true;
        matchedPairs++;
    }

    currentSelections[0] = -1;
    currentSelections[1] = -1;

    if (matchedPairs == 8) {
        std::cout << "You won the memory game!" << std::endl;
    }
}





Trivia::Trivia()
{
    backgroundTexture = IMG_LoadTexture(renderer, "trivia/laniakea supercluster.png");
    if (!backgroundTexture) {
        cout << "Failed to load menu background: " << IMG_GetError() << endl;
    }

    homeButton = new Button("buttons/home_normal.png", "buttons/home_glow.png", "buttons/home_bw.png", renderer);//make button
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
                    currentGameState = start;
                    currentGameState->enter();
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


