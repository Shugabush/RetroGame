#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib.h"

class Enemy : public GameObject
{
	int health;
	float moveTimer; // Used to determine when the enemy should shift over

	Vector2 startingPosition;
	
public:
	int rectWidth;
	int rectHeight;

	float timeElapsed; // Time elapsed since the last shift

	Enemy(float delay);

	void UpdateStartingPosition();

	void Update() override;
	void Draw() override;

	void Shoot(Vector2 vel);

	void ShiftDown();
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

	void ShiftDown();

	void Update() override;
	void Draw() override;

	void DrawCollider() override;

	void OnCollisionStay(Collider* other) override;
};

