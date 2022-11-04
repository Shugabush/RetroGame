#include "Enemy.h"
#include "Utility.h"

Enemy::Enemy()
{
	health = 1;
	rectWidth = 10;
	rectHeight = 10;
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	int posX = (int)position.x - (rectWidth / 2);
	int posY = (int)position.y - (rectHeight / 2);
	DrawRectangle(posX, posY, rectWidth, rectHeight, RED);
}

void Enemy::Shoot(Vector2 vel)
{
	Bullet* bullet = new Bullet();
	bullet->position = position;
	bullet->velocity = vel;
	Instantiate(bullet);
}

EnemyManager::EnemyManager()
{
	name = "Enemy";
	enemies = new Enemy[ROWS, COLS];
	spawnRange = { 25, 25, 550, 300 };
	for (int r = 0; r < ROWS; r++)
	{
		float posX = spawnRange.x + (spawnRange.width * ((float)r / ROWS));
		for (int c = 0; c < COLS; c++)
		{
			float posY = spawnRange.y + (spawnRange.height * ((float)c / COLS));
			enemies[r, c].position = { posX, posY };
		}
	}
}

EnemyManager::~EnemyManager()
{
	delete[] enemies;
}

void EnemyManager::Update()
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			enemies[r, c].OnUpdate();
		}
	}
}

void EnemyManager::Draw()
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			enemies[r, c].OnDraw();
		}
	}
}

void EnemyManager::DrawCollider()
{
	DrawRectangleLines((int)spawnRange.x, (int)spawnRange.y, (int)spawnRange.width, (int)spawnRange.height, GREEN);
}