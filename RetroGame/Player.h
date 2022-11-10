#pragma once
#include "GameObject.h"
#include "raylib.h"

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

	void Start();
	void Update();
	void Draw();

	void Shoot(Vector2 vel);

	void TakeDamage();

	void OnCollisionStay(Collider* other) override;
};