#pragma once
#include "Button.h"
#include "global.h"
#include "Mouse.h"
class GameState
{
public:
	static std::vector<Button*> buttons;

	virtual void enter() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

	void shutdown();
	void baseUpdate();

	static SDL_Window* window;
	static SDL_Renderer* renderer;
	SDL_Texture* backgroundTexture;
	SDL_Texture* titleTexture;
	SDL_Texture* welcomeTexture;
	SDL_Texture* instructionTexture;
	static Mouse* mouse;

	static GameState* start;
	//static GameState* signup;
	static GameState* menu;
	//static GameState* leaderboard;
	//static GameState* leaderboardEasy;
	//static GameState* leaderboardNormal;
	//static GameState* leaderboardHard;
	static GameState* difficulty;
	//static GameState* level;
	static GameState* welcome;
	static GameState* instruction;
	static GameState* funFact;
	static GameState* memorygame;
	static GameState* trivia;

	static GameState* currentGameState;

	GameState();
	virtual ~GameState();
};

class Start : public GameState {
public:
	Start();
	virtual ~Start();
	virtual void enter();
	virtual void update();
	virtual void exit();
private:
	Button* playButton;

};

class Menu : public GameState {
public:
	Menu();
	virtual ~Menu();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* newGameButton;
	Button* newLeaderBoard;
	Button* exitButton;
};

class Difficulty : public GameState {
public:
	Difficulty();
	virtual ~Difficulty();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* easyButton;
	Button* hardButton;
};

class Welcome : public GameState {
public:
	Welcome();
	virtual ~Welcome();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* rightButton;
};

class Instruction : public GameState {
public:
	Instruction();
	virtual ~Instruction();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* leftButton;
	Button* rightButton;
	Button* startButton;
};

class FunFact : public GameState {
public:
	FunFact();
	virtual ~FunFact();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* forwardButton;
	Button* backButton;
	Button* startButton;
};

class MemoryGame : public GameState {
public:

	bool isPointInRect(int x, int y, const SDL_Rect& rect);
	MemoryGame();
	~MemoryGame();

	void enter() override;
	void update() override;
	void exit() override;

private:
	SDL_Texture* backgroundTexture;
	std::vector<SDL_Texture*> cardTextures;
	std::vector<SDL_Rect> cardPositions;

	int matchedPairs;
	int currentSelections[2];
	bool cardFlipped[16];

	void loadCardTextures();
	void drawCards();
	void checkForMatch();
};

class Trivia : public GameState {
public:
	Trivia();
	virtual ~Trivia();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* homeButton;
};

