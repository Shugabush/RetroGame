#include "Bullet.h"
#include "Utility.h"
#include "raylib-cpp.hpp"
#include <iostream>

Bullet::Bullet() : SpriteObject()
{
	name = "Bullet";
	size = 25;
	velocity = { 0, 0 };
	animationTimer = Timer(0.25f);
}

void Bullet::Update()
{
	position.x += velocity.x;
	position.y -= velocity.y;
	collider->SetBounds({ size, size, size, size });

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