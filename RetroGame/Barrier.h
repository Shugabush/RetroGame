#pragma once
#include "GameObject.h"

class Barrier : public SpriteObject
{
	int durability;

public:
	Barrier(int durability);
	int width, height;

	void Update() override;
	void LateDraw() override;

	void OnCollisionStay(Collider* other) override;

	void Damage();
};