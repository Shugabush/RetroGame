#include "TextObject.h"
#include "GameManager.h"

TextObject::TextObject()
{
	this->text = "";
	color = BLACK;
}

TextObject::TextObject(std::string text)
{
	this->text = text;
	color = BLACK;
}

void TextObject::Update()
{
	
}

void TextObject::LateDraw()
{
	const int textSize = 25;
	DrawText(text.c_str(), (int)position.x - (text.length() * (textSize / 5)), (int)position.y - (text.length() * (textSize / 5)), textSize, color);
}