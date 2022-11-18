#pragma once
#include "GameObject.h"

class Barrier : public SpriteObject
{
	int durability;

public:
	Barrier(int durability);

	void Update() override;
	void LateDraw() override;

	void OnCollisionStay(Collider* other) override;

	void Damage();
};