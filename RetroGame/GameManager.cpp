#include "GameManager.h"

GameManager::GameManager()
{
	state = ACTIVE;
	winScreen = nullptr;
	loseScreen = nullptr;
}

void GameManager::Update()
{
	
}

void GameManager::Play()
{
	state = ACTIVE;
}

void GameManager::Win()
{
	state = VICTORY;
}

void GameManager::Lose()
{
	state = LOSS;
}

void WinScreen::Draw()
{

}

void LoseScreen::Draw()
{

}