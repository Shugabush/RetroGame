#include "Background.h"
#include "Utility.h"

Background::Background()
{
	sprites.push_back(backgroundSprite);
}

void Background::Draw()
{
	float tileWidth = (float)screenWidth / COLS;
	float tileHeight = (float)screenHeight / ROWS;
	for (int c = 0; c < COLS; c++)
	{
		float posX = screenWidth * ((float)c / COLS);
		for (int r = 0; r < ROWS; r++)
		{
			float posY = screenHeight * ((float)r / ROWS);
			DrawTexturePro(sprites[currentSprite], {0, 0, (float)sprites[currentSprite].width, (float)sprites[currentSprite].height}, {posX, posY, tileWidth, tileHeight}, {0, 0}, 0, WHITE);
		}
	}
}