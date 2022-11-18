#pragma once
#include "Utility.h"

class Explosion : public SpriteObject
{
public:
	Explosion();

	void UpdateAnimation() override;
};