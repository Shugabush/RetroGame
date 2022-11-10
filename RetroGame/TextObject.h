#pragma once
#include "Utility.h"

class TextObject : public GameObject
{

public:
	std::string text;

	TextObject();
	TextObject(std::string text);
};