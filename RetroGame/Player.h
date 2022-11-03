#pragma once
#include "GameObject.h"
#include "raylib.h"

class Player : GameObject
{
	int health;

public:
	Player();

	void Update();

	void Shoot();
};