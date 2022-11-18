#include "TextObject.h"
#include "GameManager.h"

TextObject::TextObject()
{
	this->text = "";
	color = BLACK;
	textSize = 25;
}

TextObject::TextObject(std::string text)
{
	this->text = text;
	color = BLACK;
	textSize = 25;
}

void TextObject::Update()
{
	
}

void TextObject::LateDraw()
{
	DrawText(text.c_str(), (int)position.x - (text.length() * (textSize / 5)), (int)position.y - (text.length() * (textSize / 5)), textSize, color);
}

TextScreen::TextScreen()
{
	position = { 350, 400 };
	collider->SetBounds({ 1000, 1000, 1000, 1000 });
	text = "";
}

TextScreen::TextScreen(std::string text)
{
	position = { 350, 400 };
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

void PendingScreen::Update()
{
	if (IsMouseButtonDown(0))
	{
		GameManager::Play();
		StartGame();
	}
}

// Hard-coded layout of text and images to draw
void PendingScreen::LateDraw()
{
	DrawText("Play", 265, 150, 25, WHITE);
	DrawText("Space Invaders", 200, 200, 25, WHITE);

	DrawText("*Score Advance Table*", 150, 260, 25, WHITE);

	// Draw ufo sprite and text
	//DrawTexturePro(sprites[currentSprite], {0, 0, (float)sprites[currentSprite].width, (float)sprites[currentSprite].height}, {position.x, position.y, size.x, size.y}, {extents.x, extents.y}, rotation, color);
	DrawTexturePro(ufoSprite, { 0, 0, (float)ufoSprite.width, (float)ufoSprite.height }, { 215, 305, 25, 15 }, { 0, 0 }, 0, WHITE);
	DrawText("= ? Mystery", 250, 300, 25, WHITE);

	// Draw small enemy sprite and text
	DrawTexturePro(smallEnemySprites[0], { 0, 0, (float)smallEnemySprites[0].width, (float)smallEnemySprites[0].height}, {218, 350, 20, 20}, {0, 0}, 0, WHITE);
	DrawText("= 30 Points", 250, 350, 25, WHITE);

	// Draw normal enemy sprite and text
	DrawTexturePro(normalEnemySprites[0], { 0, 0, (float)normalEnemySprites[0].width, (float)normalEnemySprites[0].height }, { 215, 400, 25, 20 }, { 0, 0 }, 0, WHITE);
	DrawText("= 20 Points", 250, 400, 25, WHITE);

	// Draw big enemy sprite and text
	DrawTexturePro(bigEnemySprites[0], { 0, 0, (float)bigEnemySprites[0].width, (float)bigEnemySprites[0].height }, { 215, 450, 25, 20 }, { 0, 0 }, 0, WHITE);
	DrawText("= 10 Points", 250, 450, 25, WHITE);
}