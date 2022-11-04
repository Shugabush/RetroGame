#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib.h"

class Enemy : public GameObject
{
	int health;
public:
	Enemy();

	void Update() override;
	void Draw() override;

	void Shoot(Vector2 vel);
};

