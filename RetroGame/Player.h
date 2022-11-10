#pragma once
#include "GameObject.h"
#include "raylib-cpp.hpp"

class Player : public SpriteObject
{
	int health;
	float shootCooldown;
	float timeElapsed;

public:
	float movementSpeed;
	int rectWidth;
	int rectHeight;

	Player(int health);

	void Start() override;
	void Update() override;
	void LateDraw() override;

	void Shoot(Vector2 vel);

	void TakeDamage();

	void OnCollisionStay(Collider* other) override;
};