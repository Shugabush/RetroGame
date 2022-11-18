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

	static TextObject* scoreText; // Display score

	static ScoreAdvanceTable* scoreTable;

	static int score; // How many points we have
	static int roundsCompleted; // How many rounds have we completed?

	GameManager();

	static void UpdateScore(int value); // Add a value to our score and display it

	static void Pending();
	static void Pending(std::string text);

	static void Play();

	static void Win();
	static void Win(std::string text);

	static void Lose();
	static void Lose(std::string text);

	void Update() override;
	void LateDraw() override;
};