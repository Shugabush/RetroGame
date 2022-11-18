#include "GameManager.h"
#include "SoundPool.h"

GameState gameState = PENDING;

TextScreen* GameManager::winScreen = new TextScreen("Victory!\nClick to replay");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!\nClick to try again");
TextObject* GameManager::scoreText = new TextObject("0");

PendingScreen* GameManager::pendingScreen = new PendingScreen();

int GameManager::score = 0;
int GameManager::roundsCompleted = 0;

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
}

void GameManager::Pending(std::string text)
{
	gameState = PENDING;
}

void GameManager::Play()
{
	gameState = ACTIVE;
	scoreText->text = std::to_string(score);
	StopMusicStream(song);
	songSpeed = 1;
	SetMusicPitch(song, 1);
	PlayMusicStream(song);
}

void GameManager::Win()
{
	roundsCompleted++;
	gameState = VICTORY;
	winScreen->text = "Victory!\nClick to replay\nPress escape to exit";
}

void GameManager::Win(std::string text)
{
	gameState = VICTORY;
	winScreen->text = text;
}

void GameManager::Lose()
{
	gameState = DEFEAT;
	loseScreen->text = "Defeat!\nClick to try again\nPress escape to exit";
	score = 0;
	roundsCompleted = 0;
}

void GameManager::Lose(std::string text)
{
	gameState = DEFEAT;
	loseScreen->text = text;
}

void GameManager::Update()
{
	scoreText->color = GREEN;
	scoreText->Update();
}

void GameManager::LateDraw()
{
	scoreText->LateDraw();
}