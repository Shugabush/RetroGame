#pragma once
#include "Utility.h"

class GameManager : public GameObject
{
	enum GameState
	{
		ACTIVE,
		VICTORY,
		LOSS,
	};

	GameState state;

	WinScreen* winScreen;
	LoseScreen* loseScreen;

public:
	GameManager();
	void Update() override;

	void Play();
	void Win();
	void Lose();
};

class WinScreen : public GameObject
{
public:
	void Draw() override;
};

class LoseScreen : public GameObject
{
public:
	void Draw() override;
};