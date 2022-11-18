#pragma once
#include "raylib-cpp.hpp"

extern Texture2D backgroundSprite;

extern Texture2D playerSprite;
extern Texture2D playerExplosionSprites[2];

extern Texture2D smallEnemySprites[2];
extern Texture2D normalEnemySprites[2];
extern Texture2D bigEnemySprites[2];
extern Texture2D enemyExplosionSprite;

extern Texture2D ufoSprite;
extern Texture2D ufoExplosionSprite;

extern Texture2D barrierSprite;
extern Texture2D playerBulletSprites[4];
extern Texture2D enemyBulletSprites[4];

extern void LoadTextures(); // Load textures
