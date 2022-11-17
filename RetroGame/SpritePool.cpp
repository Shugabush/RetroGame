#include "SpritePool.h"

Texture2D backgroundSprite;

Texture2D playerSprite;

Texture2D smallEnemySprites[2];
Texture2D normalEnemySprites[2];
Texture2D bigEnemySprites[2];
Texture2D ufoSprite;

Texture2D barrierSprite;
Texture2D bulletSprite;

void LoadTextures()
{
	backgroundSprite = LoadTexture("background.png");

	playerSprite = LoadTexture("player.png");

	ufoSprite = LoadTexture("Ufo.png");

	smallEnemySprites[0] = LoadTexture("enemySmall.png");
	smallEnemySprites[1] = LoadTexture("enemySmall2.png");

	normalEnemySprites[0] = LoadTexture("enemyNormal.png");
	normalEnemySprites[1] = LoadTexture("enemyNormal2.png");

	bigEnemySprites[0] = LoadTexture("enemyBig.png");
	bigEnemySprites[1] = LoadTexture("enemyBig2.png");

	barrierSprite = LoadTexture("barrier.png");
	bulletSprite = LoadTexture("bullet.png");
}