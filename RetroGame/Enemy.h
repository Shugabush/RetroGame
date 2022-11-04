#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib.h"

class Enemy : public GameObject
{
	int health;
	float moveTimer; // Used to determine when the enemy should shift over
	float timeElapsed; // Time elapsed since the last shift
	
public:
	int rectWidth;
	int rectHeight;

	Enemy();

	void Update() override;
	void Draw() override;

	void Shoot(Vector2 vel);
};

class EnemyManager : public GameObject
{
	// Enemies that are stored specifically in this class
	// (not part of the main objects list in utility)
	Enemy** enemies;

	Rectangle spawnRange;

public:
	const int ROWS = 11;
	const int COLS = 5;

	EnemyManager();
	~EnemyManager();

	void Update() override;
	void Draw() override;

	void DrawCollider() override;
};

