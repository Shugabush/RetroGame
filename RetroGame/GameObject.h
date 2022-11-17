#pragma once
#include "raylib-cpp.hpp"

#include <iostream>

class Collider;

class GameObject
{
protected:
	virtual void Update();
	virtual void Draw();
	void DrawCollider();
public:
	std::string name;
	Vector2 position;
	float rotation;
	Collider* collider;

	GameObject();
	~GameObject();

	virtual void Start();

	void OnUpdate();

	void OnDraw();

	virtual void LateDraw();

	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);
};

class SpriteObject : public GameObject
{
public:
	Texture2D sprite;

	void Draw() override;
};

class Collider
{
	raylib::BoundingBox* bounds;

public:

	GameObject* gameObject;
	Collider(GameObject* obj);
	Collider(GameObject* obj, raylib::BoundingBox bounds);

	raylib::BoundingBox GetBounds();

	Vector3 Size();
	Vector3 Extents();

	void SetBounds(Rectangle rect);
};