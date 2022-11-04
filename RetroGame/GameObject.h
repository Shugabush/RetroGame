#pragma once
#include "raylib.h"

class Collider;

class GameObject
{
public:
	Vector2 position;
	float rotation;
	Collider* collider;

	GameObject();
	~GameObject();

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

class Collider
{
public:
	Collider();
	Collider(Rectangle bounds);

	Rectangle bounds;

	void OnCollisionStay(Collider* other);
};