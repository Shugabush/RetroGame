#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib-cpp.hpp"

class Enemy : public SpriteObject
{
	float shootTimer; // Used to determine when the enemy is ready to shoot
	float timeElapsed; // Time elapsed since the last shift

	int direction;

	int health;
	float moveTimer; // Used to determine when the enemy should shift over

	Vector2 startingPosition;

	bool defeated;

	bool fastMode; // Set this to true when this enemy is the only one left
	
public:
	int rectWidth;
	int rectHeight;

	Enemy(float delay, int dir);

	bool Defeated(); // Read-only access to defeated bool

	void FastMode(); // Significantly reduce the move timer

	void UpdateStartingPosition();

	void Update() override;

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

	int direction;

public:
	static EnemyManager* instance;
	bool reset = false;

	const int BIGROWS = 3; // Big enemy sprite rows
	const int NORMALROWS = 3; // Normal enemy sprite rows
	// The remaining rows will be filled with small enemy sprites

	const int ROWS = 11;
	const int COLS = 5;

	EnemyManager();

	void ShiftDown();

	void Update() override;
	void Draw() override;

	bool ShouldShift();

	void FixUndefeatedEnemies();

	Enemy* GetRandomEnemy();

	int LastColumn();
	int LastRow();
};

