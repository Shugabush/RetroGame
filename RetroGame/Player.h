#pragma once
#include "GameObject.h"
#include "raylib-cpp.hpp"

class Player : public SpriteObject
{
	int health;
	Timer shootTimer;

public:
	float movementSpeed;

	Player(int health);

	void Start() override;
	void Update() override;

	void Draw() override;
	void LateDraw() override;

	void Shoot(Vector2 vel);

	void TakeDamage();

	void OnCollisionStay(Collider* other) override;
};