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

TextScreen::TextScreen()
{
	position = { 350, 400 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	text = "";
}

TextScreen::TextScreen(std::string text)
{
	position = { 350, 400 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	this->text = text;
}

void TextScreen::Update()
{
	if (IsMouseButtonDown(0))
	{
		GameManager::Play();
		StartGame();
	}
}

void TextScreen::LateDraw()
{
	const int textSize = 25;
	DrawText(text.c_str(), (int)position.x - (text.length() * (textSize / 5)), (int)position.y - (text.length() * (textSize / 5)), textSize, DARKBLUE);
}

// Hard-coded layout of text and images to draw
void ScoreAdvanceTable::LateDraw()
{
	if (gameState == PENDING)
	{
		int posX = screenWidth / 2;
		int posY = screenHeight / 2;
		
		posY -= 200;
		DrawText("PLAY", posX, posY, 25, WHITE);

		posX -= 150;

		DrawText("*Score Advance Table*", posX, posY, 25, WHITE);
		posX += 15;
		posY += 25;
		DrawText("= ? Mystery", posX, posY, 25, WHITE);
	}
}