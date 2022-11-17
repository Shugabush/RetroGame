#pragma once
#include "raylib-cpp.hpp"
#include "Timer.h"

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

	virtual void OnUpdate();

	virtual void OnDraw();

	virtual void LateDraw();

	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);
};

class SpriteObject : public GameObject
{
protected:
	int currentSprite;

	float WidthToHeight(); // Sprite ratio (width divided by height)
	float HeightToWidth(); // Sprite ratio (height divided by width)

public:
	Timer animationTimer = Timer(5);

	std::vector<Texture2D> sprites;

	void OnUpdate() override;
	void UpdateAnimation(); // Update sprite animation

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