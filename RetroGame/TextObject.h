#pragma once
#include "Utility.h"
#include "raylib-cpp.hpp"

class TextObject : public GameObject
{

public:
	int textSize;
	std::string text;
	Color color;

	void Update() override;
	void LateDraw() override;

	TextObject();
	TextObject(std::string text);
};