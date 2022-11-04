#include "Bullet.h"
#include "Utility.h"
#include "raylib.h"
#include <iostream>

Bullet::Bullet()
{
	size = 5;
}

void Bullet::Update()
{
	position.x += velocity.x;
	position.y -= velocity.y;
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