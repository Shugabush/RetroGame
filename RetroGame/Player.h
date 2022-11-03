#pragma once
#include "GameObject.h"
#include "raylib.h"

class Player : public SpriteObject
{
	int health;

public:
	float movementSpeed;

	Player();

	void Start();
	void Update();
	void Draw();

	void Shoot(Vector2 vel);
};