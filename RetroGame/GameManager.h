#pragma once
#include "Utility.h"

class WinScreen;
class LoseScreen;

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

	static GameManager* instance;

public:
	GameManager();

	static GameManager* Instance();

	void Update() override;

	void Play();
	void Win();
	void Lose();
};

class WinScreen : public GameObject
{
public:
	WinScreen();
	void Draw() override;
};

class LoseScreen : public GameObject
{
public:
	LoseScreen();
	void Draw() override;
};