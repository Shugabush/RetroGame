#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib.h"

class Enemy : public GameObject
{
	int health;
	
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

