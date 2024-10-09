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
	static GameState* funFact1;
	//static GameState* funFact2;
	//static GameState* funFact3;
	//static GameState* funFact4;
	//static GameState* funFact5;
	//static GameState* funFact6;
	//static GameState* funFact7;
	//static GameState* funFact8;
	//static GameState* gameEasy;
	//static GameState* gameNormal;
	//static GameState* gameHard;
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
};

class FunFact1 : public GameState {
public:
	FunFact1();
	virtual ~FunFact1();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	Button* forwardButton;
	Button* backButton;
	Button* startButton;
};

/*class Game : public GameState {
public:
	Game();
	virtual ~Game();
	virtual void enter();
	virtual void update();
	virtual void exit();

private:
	//tentative
};*/

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

