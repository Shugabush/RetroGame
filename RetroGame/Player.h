#pragma once
#include "GameObject.h"
#include "raylib.h"

class Player : public GameObject
{
	int health;

public:
	float movementSpeed;

	Player();

	void Start();
	void Update();
	void Draw();

	void Shoot();
};