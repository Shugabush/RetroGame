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

class EnemyManager
{
public:
	const int ROWS = 11;
	const int COLS = 5;

	Enemy* enemies;

	EnemyManager();
	~EnemyManager();
};

