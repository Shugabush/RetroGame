#pragma once
#include "GameObject.h"

class Background : public SpriteObject
{
public:
	// Rows and colums of tiles
	const int ROWS = 5;
	const int COLS = 5;

	void Draw() override;
};