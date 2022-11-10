#include "Enemy.h"
#include "Utility.h"

Enemy::Enemy(float delay = 0)
{
	health = 1;
	rectWidth = 10;
	rectHeight = 10;
	moveTimer = 1;
	timeElapsed = -delay;
	UpdateStartingPosition();
}

void Enemy::UpdateStartingPosition()
{
	startingPosition = position;
}

void Enemy::Update()
{
	timeElapsed += GetFrameTime();
	if (timeElapsed >= moveTimer)
	{
		// Time to shift the enemy over
		position.x += 5;
		timeElapsed = 0;
	}
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

void Enemy::ShiftDown(float yShift)
{
	startingPosition.y += yShift;
	position = startingPosition;
}

EnemyManager::EnemyManager()
{
	name = "Enemy Manager";
	enemies = new Enemy*[COLS];
	spawnRange = { 25, 25, 550, 300 };
	for (int c = 0; c < COLS; c++)
	{
		enemies[c] = new Enemy[ROWS];
		float posX = spawnRange.x + (spawnRange.width * ((float)(c + 0.5f) / COLS));
		for (int r = 0; r < ROWS; r++)
		{
			enemies[c][r].timeElapsed = (float)-r / ROWS;
			float posY = spawnRange.y + (spawnRange.height * ((float)(r + 0.5f) / ROWS));
			enemies[c][r].position = {posX, posY};
			enemies[c][r].UpdateStartingPosition();
		}
	}
}

EnemyManager::~EnemyManager()
{
	delete[] enemies;
}

void EnemyManager::ShiftDown()
{
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			enemies[c][r].ShiftDown(spawnRange.height / ROWS);
		}
	}
}

void EnemyManager::Update()
{
	if (!InBounds(&enemies[0][0], spawnRange.width + 40, spawnRange.height + 40) || !InBounds(&enemies[COLS - 1][0], spawnRange.width + 40, spawnRange.height + 40))
	{
		std::cout << "Time to shift down!" << std::endl;
		ShiftDown();
	}
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			enemies[c][r].OnUpdate();
		}
	}
}

void EnemyManager::Draw()
{
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			enemies[c][r].OnDraw();
		}
	}
}

void EnemyManager::DrawCollider()
{
	DrawRectangleLines((int)spawnRange.x, (int)spawnRange.y, (int)spawnRange.width, (int)spawnRange.height, GREEN);
}

void EnemyManager::OnCollisionStay(Collider* other)
{

}