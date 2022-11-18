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

class TextScreen : public GameObject
{
public:
	std::string text;

	TextScreen();
	TextScreen(std::string text);

	void Update() override;
	void LateDraw() override;
};

class PendingScreen : public GameObject
{
public:
	TextScreen* text;

	void Update() override;
	void LateDraw() override;
};