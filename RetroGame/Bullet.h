#pragma once
#include "GameObject.h"
#include "raylib.h"

class Bullet : public SpriteObject
{
public:
	Bullet();
	Vector2 velocity;
	float size;

	void Update() override;
	void Draw() override;
};