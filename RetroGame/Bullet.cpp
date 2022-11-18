#include "Bullet.h"
#include "Utility.h"
#include "raylib-cpp.hpp"
#include <iostream>

Bullet::Bullet() : SpriteObject()
{
	name = "Bullet";
	velocity = { 0, 0 };
	animationTimer = Timer(0.25f);
	width = 10;
	height = 25;
}

void Bullet::Update()
{
	position.x += velocity.x;
	position.y -= velocity.y;
	collider->SetBounds({ position.x, position.y, (float)width, (float)height});

	if (!InBounds(this))
	{
		Destroy(this);
	}
}

void Bullet::OnCollisionStay(Collider* other)
{
	if (other->gameObject->name == "Enemy Bullet" || other->gameObject->name == "Player Bullet")
	{
		// We collided with a bullet, so destroy that bullet and this one
		Destroy(other->gameObject);
		Destroy(this);
	}
}