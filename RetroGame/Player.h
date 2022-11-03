#pragma once
#include "GameObject.h"
#include "raylib.h"

class Player : public GameObject
{
	int health;

public:
	Player();

	void Update();
	void Draw();

	void Shoot();
};