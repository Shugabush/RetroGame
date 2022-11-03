#pragma once
#include "GameObject.h"
#include "raylib.h"

class Bullet : public SpriteObject
{
public:
	Vector2 velocity;

	void Update() override;
	void Draw() override;
};