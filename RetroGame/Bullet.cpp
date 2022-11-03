#include "Bullet.h"
#include "raylib.h"

Bullet::Bullet()
{
	size = 5;
}

void Bullet::Update()
{
	position.x += velocity.x;
	position.y += velocity.y;
}

void Bullet::Draw()
{
	DrawCircle((int)position.x + (size / 4), (int)position.y + (size / 4), size, BLACK);
}