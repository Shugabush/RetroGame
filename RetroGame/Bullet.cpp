#include "Bullet.h"
#include "raylib.h"

void Bullet::Update()
{
	position.x += velocity.x;
	position.y += velocity.y;
}

void Bullet::Draw()
{
	DrawCircle((int)position.x, (int)position.y, 50, BLACK);
}