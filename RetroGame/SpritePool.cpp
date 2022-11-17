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
	backgroundSprite = LoadTexture("Sprites/background.png");

	playerSprite = LoadTexture("Sprites/player.png");

	ufoSprite = LoadTexture("Sprites/Ufo.png");

	smallEnemySprites[0] = LoadTexture("Sprites/enemySmall.png");
	smallEnemySprites[1] = LoadTexture("Sprites/enemySmall2.png");

	normalEnemySprites[0] = LoadTexture("Sprites/enemyNormal.png");
	normalEnemySprites[1] = LoadTexture("Sprites/enemyNormal2.png");

	bigEnemySprites[0] = LoadTexture("Sprites/enemyBig.png");
	bigEnemySprites[1] = LoadTexture("Sprites/enemyBig2.png");

	barrierSprite = LoadTexture("Sprites/barrier.png");
	bulletSprite = LoadTexture("Sprites/bullet.png");
}