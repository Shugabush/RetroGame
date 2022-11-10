#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	instance = this;

	state = ACTIVE;
	winScreen = nullptr;
	loseScreen = nullptr;
}

GameManager* GameManager::Instance()
{
	return instance;
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

WinScreen::WinScreen()
{

}

void WinScreen::Draw()
{

}

LoseScreen::LoseScreen()
{

}

void LoseScreen::Draw()
{

}