#pragma once
#include "GameObject.h"

class Barrier : public SpriteObject
{
	int durability;
public:
	Barrier(int durability);
	int width, height;

	void Draw() override;

	void Damage();
};