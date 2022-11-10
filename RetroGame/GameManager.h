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

extern GameState gameState;

class GameManager : public GameObject
{
public:
	static TextScreen* pendingScreen;
	static TextScreen* winScreen;
	static TextScreen* loseScreen;

	GameManager();

	static void Pending();
	static void Play();
	static void Win();
	static void Lose();

	void Draw() override;
};

class TextScreen : public GameObject
{
	TextObject text;

public:
	TextScreen();
	TextScreen(std::string text);

	void Update() override;
	void Draw() override;
};