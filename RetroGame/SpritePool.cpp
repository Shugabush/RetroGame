#include "SpritePool.h"

Texture2D backgroundSprite;

Texture2D playerSprite;
Texture2D playerExplosionSprites[2];

Texture2D smallEnemySprites[2];
Texture2D normalEnemySprites[2];
Texture2D bigEnemySprites[2];
Texture2D ufoSprite;

Texture2D barrierSprite;
Texture2D playerBulletSprites[4];
Texture2D enemyBulletSprites[4];

void LoadTextures()
{
	backgroundSprite = LoadTexture("Sprites/background.png");

	playerSprite = LoadTexture("Sprites/player.png");
	playerExplosionSprites[0] = LoadTexture("Sprites/playerexplosion.png");
	playerExplosionSprites[1] = LoadTexture("Sprites/playerexplosion2.png");

	ufoSprite = LoadTexture("Sprites/Ufo.png");

	smallEnemySprites[0] = LoadTexture("Sprites/enemySmall.png");
	smallEnemySprites[1] = LoadTexture("Sprites/enemySmall2.png");

	normalEnemySprites[0] = LoadTexture("Sprites/enemyNormal.png");
	normalEnemySprites[1] = LoadTexture("Sprites/enemyNormal2.png");

	bigEnemySprites[0] = LoadTexture("Sprites/enemyBig.png");
	bigEnemySprites[1] = LoadTexture("Sprites/enemyBig2.png");

	barrierSprite = LoadTexture("Sprites/barrier.png");

	playerBulletSprites[0] = LoadTexture("Sprites/playerbullet.png");
	playerBulletSprites[1] = LoadTexture("Sprites/playerbullet2.png");
	playerBulletSprites[2] = LoadTexture("Sprites/playerbullet3.png");
	playerBulletSprites[3] = LoadTexture("Sprites/playerbullet4.png");

	enemyBulletSprites[0] = LoadTexture("Sprites/enemybullet.png");
	enemyBulletSprites[1] = LoadTexture("Sprites/enemybullet2.png");
	enemyBulletSprites[2] = LoadTexture("Sprites/enemybullet3.png");
	enemyBulletSprites[3] = LoadTexture("Sprites/enemybullet4.png");
}