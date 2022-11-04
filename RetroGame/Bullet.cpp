#include "Bullet.h"
#include "Utility.h"
#include "raylib.h"
#include <iostream>

Bullet::Bullet() : SpriteObject()
{
	name = "Bullet";
	size = 5;
	velocity = { 0, 0 };
}

void Bullet::Update()
{
	position.x += velocity.x;
	position.y -= velocity.y;
	collider->SetBounds({ size, size, size, size });
	if (!InBounds(this))
	{
		collider->SetBounds({ size, size, size, size });
		std::cout << "destroying" << std::endl;
		Destroy(this);
	}
}

void Bullet::Draw()
{
	DrawCircle((int)position.x + (size / 4), (int)position.y + (size / 4), size, BLACK);
}