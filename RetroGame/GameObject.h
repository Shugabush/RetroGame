#pragma once
#include "raylib.h"

class GameObject
{
public:
	Vector2 position;
	float rotation;

	GameObject();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
};

class SpriteObject : public GameObject
{
public:
	Texture2D* sprite;

	void Draw() override;
};

class Collider : public GameObject
{
public:
	Collider(Rectangle bounds);

	Rectangle bounds;

	void Update() override;
	void OnCollisionStay(Collider* other);
};