#pragma once
#include "GameObject.h"
#include "raylib.h"

class Player : public SpriteObject
{
	int health;

public:
	float movementSpeed;
	int rectWidth;
	int rectHeight;

	Player();

	void Start();
	void Update();
	void Draw();

	void Shoot(Vector2 vel);
};