#include "GameManager.h"

GameState gameState = ACTIVE;

TextScreen* GameManager::pendingScreen = new TextScreen("Play");
TextScreen* GameManager::winScreen = new TextScreen("Victory!");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!");

GameManager::GameManager()
{
	
}

void GameManager::Pending()
{
	gameState = PENDING;
}

void GameManager::Play()
{
	gameState = ACTIVE;
}

void GameManager::Win()
{
	gameState = VICTORY;
}

void GameManager::Lose()
{
	gameState = DEFEAT;
}

void GameManager::Draw()
{
	
}

TextScreen::TextScreen()
{
	position = { 260, 260 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	text = TextObject("");
}

TextScreen::TextScreen(std::string text)
{
	position = { 260, 260 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	this->text = text;
}

void TextScreen::Update()
{
	if (IsMouseButtonDown(0))
	{
		gameState = ACTIVE;
		StartGame();
	}
}

void TextScreen::Draw()
{
	DrawText(text.text.c_str(), (int)position.x, (int)position.y, 25, RED);
}