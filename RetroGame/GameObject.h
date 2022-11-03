#pragma once
#include "raylib.h"

class GameObject
{
public:
	Vector2 position;
	float rotation;

	GameObject();
	virtual void Update();
	virtual void Draw();
};