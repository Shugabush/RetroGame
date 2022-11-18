#include "TextObject.h"
#include "GameManager.h"

TextObject::TextObject()
{
	this->text = "";
	color = BLACK;
	textSize = 25;
}

TextObject::TextObject(std::string text)
{
	this->text = text;
	color = BLACK;
	textSize = 25;
}

void TextObject::Update()
{
	
}

void TextObject::LateDraw()
{
	DrawText(text.c_str(), (int)position.x - (text.length() * (textSize / 5)), (int)position.y - (text.length() * (textSize / 5)), textSize, color);
}