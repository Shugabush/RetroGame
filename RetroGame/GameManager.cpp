#include "GameManager.h"

GameState gameState = ACTIVE;

GameManager::GameManager()
{
	winScreen = nullptr;
	loseScreen = nullptr;
}

void Play()
{
	gameState = ACTIVE;
}

void Win()
{
	gameState = VICTORY;
}

void Lose()
{
	gameState = DEFEAT;
}

TextScreen::TextScreen()
{
	text = TextObject("");
}

TextScreen::TextScreen(std::string text)
{
	this->text = text;
}

void TextScreen::Draw()
{
	DrawText(text.text.c_str(), (int)position.x, (int)position.y, 25, RED);
}