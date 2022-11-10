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
	static void Pending(std::string text);

	static void Play();

	static void Win();
	static void Win(std::string text);

	static void Lose();
	static void Lose(std::string text);

	void Draw() override;
};

class TextScreen : public GameObject
{
public:
	TextObject text;

	TextScreen();
	TextScreen(std::string text);

	void Update() override;
	void Draw() override;
};