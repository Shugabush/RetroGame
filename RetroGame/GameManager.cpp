#include "GameManager.h"

GameState gameState = ACTIVE;

TextScreen* GameManager::winScreen = new TextScreen("Victory!");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!");

GameManager::GameManager()
{
	
}

void GameManager::Play()
{
	gameState = ACTIVE;
}

void GameManager::Win()
{
	gameState = VICTORY;
	winScreen->Draw();
}

void GameManager::Lose()
{
	gameState = DEFEAT;
	loseScreen->Draw();
}

void GameManager::Draw()
{
	
}

TextScreen::TextScreen()
{
	position = { 300, 300 };
	text = TextObject("");
}

TextScreen::TextScreen(std::string text)
{
	position = { 300, 300 };
	this->text = text;
}

void TextScreen::Update()
{

}

void TextScreen::Draw()
{
	DrawText(text.text.c_str(), (int)position.x, (int)position.y, 25, RED);
}