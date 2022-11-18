#pragma once
#include "Utility.h"
#include "Bullet.h"
#include "raylib-cpp.hpp"

class Enemy : public SpriteObject
{
	Timer moveTimer;

	int direction;

	int health;

	Vector2 startingPosition;

	bool defeated;
	
public:
	int rectWidth;
	int rectHeight;

	int pointValue; // How many points is this enemy worth when defeated?

	Enemy(float delay, int dir);

	bool Defeated(); // Read-only access to defeated bool

	void MoveFaster(float factor); // Reduce the move timer

	void UpdateStartingPosition();

	void Update() override;

	void Shoot(Vector2 vel);

	void ShiftDown(float yShift);

	void OnCollisionStay(Collider* other) override;
};

class Ufo : public Enemy
{
public:
	Ufo();

	void Update() override;

	void OnCollisionStay(Collider* other) override;
};

class EnemyManager : public GameObject
{
	// Enemies that are stored specifically in this class
	// (not part of the main objects list in utility)
	Enemy*** enemies;

	std::vector<Enemy*> undefeatedEnemies;

	Rectangle spawnRange;

	Timer shootTimer;
	Timer ufoTimer; // Determines when a ufo can move across the top of the screen

	int direction; // What direction are the enemies moving in (1 or -1)?

public:
	static EnemyManager* instance;
	bool reset = false;

	const int SMALLROWS = 3; // Big enemy sprite rows
	const int NORMALROWS = 3; // Normal enemy sprite rows
	// The remaining rows will be filled with small enemy sprites

	const int ROWS = 11; // Total enemy rows
	const int COLS = 5; // Total enemy columns

	EnemyManager();

	void ShiftDown();

	void Update() override;
	void Draw() override;

	void MoveFaster(float factor); // Reduce the move timer for each enemy

	bool ShouldShift();

	void FixUndefeatedEnemies();

	Enemy* GetRandomEnemy();

	int LastColumn();
	int LastRow();
};

