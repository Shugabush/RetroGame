#include "Barrier.h"
#include "Utility.h"
#include "raylib-cpp.hpp"
#include "Bullet.h"

Barrier::Barrier(int durability)
{
	name = "Barrier";
	this->durability = durability;
	width = 25;
	height = 25;
	currentSprite = 0;
	sprites.push_back(barrierSprite);
}

void Barrier::Update()
{
	int posX = (int)position.x - (width / 2);
	int posY = (int)position.y - (height / 2);
	collider->SetBounds({ (float)posX, (float)posY, (float)width, (float)height });
}

void Barrier::LateDraw()
{
	DrawText(std::to_string(durability).c_str(), (int)position.x, (int)position.y, 25, RED);
}

void Barrier::OnCollisionStay(Collider* other)
{
	if (typeid(*other->gameObject) == typeid(Bullet))
	{
		Destroy(other->gameObject);
		Damage();
	}
}

// Damage the barrier
void Barrier::Damage()
{
	durability--;
	if (durability <= 0)
	{
		Destroy(this);
	}
}