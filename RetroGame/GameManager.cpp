#include <fstream>
#include "GameManager.h"
#include "SoundPool.h"

GameState gameState = PENDING;

TextScreen* GameManager::winScreen = new TextScreen("Victory!\nClick to replay");
TextScreen* GameManager::loseScreen = new TextScreen("Defeat!\nClick to try again");
TextObject* GameManager::scoreText = new TextObject("0");
TextObject* GameManager::highScoreText = new TextObject("0");

PendingScreen* GameManager::pendingScreen = new PendingScreen();

int GameManager::score = 0;
int GameManager::highScore = 0;
int GameManager::roundsCompleted = 0;

GameManager::GameManager()
{
	scoreText->position = { 250, 20 };
	highScoreText->position = { 300, 20 };
}

void GameManager::SaveHighScore()
{
	std::fstream saveFile;
	saveFile.open("save.dat", std::ios::out | std::ios::binary);

	saveFile.write((const char*)&highScore, sizeof(int));
	saveFile.close();
}

void GameManager::LoadHighScore()
{
	std::fstream loadFile;
	loadFile.open("save.dat", std::ios::in | std::ios::binary);
	loadFile.read((char*)&highScore, sizeof(int));
	loadFile.close();
}

void GameManager::UpdateScore(int value)
{
	score += value;
	if (score > highScore)
	{
		highScore = score;
	}
	scoreText->text = std::to_string(score);
	highScoreText->text = std::to_string(highScore);
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
	highScoreText->text = std::to_string(highScore);
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
	scoreText->color = WHITE;
	highScoreText->color = WHITE;
	scoreText->Update();
	highScoreText->Update();
}

void GameManager::LateDraw()
{
	// Draw score and high score labels
	DrawText("Score", 250, 5, 25, WHITE);

	// Draw score and high score text
	scoreText->LateDraw();
	highScoreText->LateDraw();
}