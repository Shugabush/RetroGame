#include "GameManager.h"

GameState gameState = PENDING;

TextScreen* GameManager::pendingScreen = new TextScreen("Click to play\nPress Escape to quit");
TextScreen* GameManager::winScreen = new TextScreen("Victory!\nClick to replay");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!\nClick to try again");
TextObject* GameManager::scoreText = new TextObject("0");
int GameManager::score = 0;

GameManager::GameManager()
{
	scoreText->position = { 250, 30 };
}

void GameManager::UpdateScore(int value)
{
	score += value;
	scoreText->text = std::to_string(score);
}

void GameManager::Pending()
{
	gameState = PENDING;
	pendingScreen->text = "Play";
}

void GameManager::Pending(std::string text)
{
	gameState = PENDING;
	pendingScreen->text = text;
}

void GameManager::Play()
{
	gameState = ACTIVE;
	scoreText->text = std::to_string(score);
}

void GameManager::Win()
{
	gameState = VICTORY;
	winScreen->text = "Victory!\nClick to replay";
}

void GameManager::Win(std::string text)
{
	gameState = VICTORY;
	winScreen->text = text;
}

void GameManager::Lose()
{
	gameState = DEFEAT;
	loseScreen->text = "Defeat!\nClick to try again";
	score = 0;
}

void GameManager::Lose(std::string text)
{
	gameState = DEFEAT;
	loseScreen->text = text;
}

void GameManager::Update()
{
	scoreText->Update();
}

void GameManager::LateDraw()
{
	scoreText->LateDraw();
}

TextScreen::TextScreen()
{
	position = { 300, 300 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	text = "";
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
		GameManager::Play();
		StartGame();
	}
}

void TextScreen::LateDraw()
{
	const int textSize = 25;
	DrawText(text.c_str(), (int)position.x - (text.length() * (textSize / 5)), (int)position.y - (text.length() * (textSize / 5)), textSize, DARKBLUE);
}