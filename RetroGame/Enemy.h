#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib-cpp.hpp"

class Enemy : public GameObject
{
	float shootTimer; // Used to determine when the enemy is ready to shoot
	float timeElapsed; // Time elapsed since the last shift

	int health;
	float moveTimer; // Used to determine when the enemy should shift over

	Vector2 startingPosition;

	bool defeated;
	
public:
	int rectWidth;
	int rectHeight;

	Enemy(float delay);

	bool Defeated(); // read-only access to defeated bool

	void UpdateStartingPosition();

	void Update() override;
	void Draw() override;

	void Shoot(Vector2 vel);
	void ShiftDown(float yShift);

	void OnCollisionStay(Collider* other) override;
};

class EnemyManager : public GameObject
{
	// Enemies that are stored specifically in this class
	// (not part of the main objects list in utility)
	Enemy*** enemies;

	std::vector<Enemy*> undefeatedEnemies;

	Rectangle spawnRange;

	float yCross; // If any undefeated enemy is beyond this imaginary line, the game is lost

	float shootTimer; // Used to determine when the enemy is ready to shoot
	float timeElapsed; // Time elapsed since last shoot

public:
	static EnemyManager* instance;
	bool reset = false;

	const int ROWS = 11;
	const int COLS = 5;

	EnemyManager();

	void ShiftDown();

	void Update() override;
	void Draw() override;

	void DrawCollider() override;

	void FixUndefeatedEnemies();

	Enemy* GetRandomEnemy();

	int LastColumn();
	int LastRow();
};

