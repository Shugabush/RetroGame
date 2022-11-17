#include "Bullet.h"
#include "Utility.h"
#include "raylib-cpp.hpp"
#include <iostream>

Bullet::Bullet() : SpriteObject()
{
	name = "Bullet";
	size = 25;
	velocity = { 0, 0 };
	sprite = LoadTexture("bullet.png");
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