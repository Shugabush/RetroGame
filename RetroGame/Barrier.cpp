#include "Barrier.h"
#include "Utility.h"
#include "raylib.h"

Barrier::Barrier(int durability)
{
	this->durability = durability;
	width = 25;
	height = 25;
}

void Barrier::Update()
{
	int posX = (int)position.x - (width / 2);
	int posY = (int)position.y - (height / 2);
	collider->SetBounds({ (float)posX, (float)posY, (float)width, (float)height});
}

void Barrier::Draw()
{
	int posX = (int)position.x - (width / 2);
	int posY = (int)position.y - (height / 2);
	DrawRectangle(posX, posY, width, height, BROWN);
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