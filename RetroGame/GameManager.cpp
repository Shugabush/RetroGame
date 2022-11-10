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
}

void GameManager::Lose()
{
	gameState = DEFEAT;
}

void GameManager::Draw()
{
	switch (gameState)
	{
	case PENDING:
		break;
	case ACTIVE:
		break;
	case VICTORY:
		winScreen->Draw();
		break;
	case DEFEAT:
		loseScreen->Draw();
		break;
	}
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