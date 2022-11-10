#include "GameManager.h"

GameState gameState = PENDING;

TextScreen* GameManager::pendingScreen = new TextScreen("Play");
TextScreen* GameManager::winScreen = new TextScreen("Victory!");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!");

GameManager::GameManager()
{
	
}

void GameManager::Pending()
{
	gameState = PENDING;
	pendingScreen->text.text = "Play";
}

void GameManager::Pending(std::string text)
{
	gameState = PENDING;
	pendingScreen->text = text;
}

void GameManager::Play()
{
	gameState = ACTIVE;
}

void GameManager::Win()
{
	gameState = VICTORY;
	winScreen->text.text = "Victory!";
}

void GameManager::Win(std::string text)
{
	gameState = VICTORY;
	winScreen->text = text;
}

void GameManager::Lose()
{
	gameState = DEFEAT;
	loseScreen->text.text = "Defeat!";
}

void GameManager::Lose(std::string text)
{
	gameState = DEFEAT;
	loseScreen->text.text = text;
}

void GameManager::Draw()
{
	
}

TextScreen::TextScreen()
{
	position = { 300, 300 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	text = TextObject("");
}

TextScreen::TextScreen(std::string text)
{
	position = { 300, 300 };
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
	const int textSize = 25;
	DrawText(text.text.c_str(), (int)position.x - (text.text.length() * (textSize / 5)), (int)position.y - (text.text.length() * (textSize / 5)), textSize, RED);
}