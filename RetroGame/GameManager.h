#pragma once
#include "Utility.h"
#include "TextObject.h"

class TextScreen;

enum GameState
{
	PENDING,
	ACTIVE,
	VICTORY,
	DEFEAT,
};

void Play();
void Win();
void Lose();

extern GameState gameState;

class GameManager : public GameObject
{
	TextScreen* winScreen;
	TextScreen* loseScreen;

public:
	GameManager();
};

class TextScreen : public GameObject
{
	TextObject text;

public:
	TextScreen();
	TextScreen(std::string text);
	void Draw() override;
};