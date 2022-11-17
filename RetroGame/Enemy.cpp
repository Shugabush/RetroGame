#include "Enemy.h"
#include "Utility.h"
#include "GameManager.h"

EnemyManager* EnemyManager::instance = nullptr;

Enemy::Enemy(float delay = 0, int dir = 1)
{
	name = "New Enemy";
	health = 1;
	rectWidth = 25;
	rectHeight = 20;
	moveTimer = 5;
	timeElapsed = -delay * 5;
	direction = dir;
	defeated = false;
	fastMode = false;
	UpdateStartingPosition();
}

bool Enemy::Defeated()
{
	return defeated;
}

void Enemy::FastMode()
{
	moveTimer = 0.2f;
}

void Enemy::UpdateStartingPosition()
{
	startingPosition = position;
}

void Enemy::Update()
{
	timeElapsed += GetFrameTime();
	collider->SetBounds({ position.x, position.y, (float)rectWidth, (float)rectHeight });

	if (timeElapsed >= moveTimer)
	{
		// Time to shift the enemy over
		position.x += 5 * direction;
		timeElapsed = 0;
	}
}

void Enemy::Shoot(Vector2 vel)
{
	Bullet* bullet = new Bullet();
	bullet->name = "Enemy Bullet";
	bullet->position = position;
	bullet->velocity = vel;
	bullet->rotation = 180;
	Instantiate(bullet);
}

void Enemy::ShiftDown(float yShift)
{
	
	UpdateStartingPosition();
	position.y += yShift;
	direction *= -1; // Change direction of enemy movement
}

EnemyManager::EnemyManager()
{
	direction = 1;
	instance = this;
	name = "Enemy Manager";
	enemies = new Enemy**[COLS];
	spawnRange = { 25, 25, 550, 300 };
	shootTimer = 1;
	timeElapsed = 0;
	yCross = 400;

	for (int c = 0; c < COLS; c++)
	{
		enemies[c] = new Enemy * [ROWS];
		float posX = spawnRange.x + (spawnRange.width * ((float)(c + 0.5f) / COLS));
		for (int r = 0; r < ROWS; r++)
		{
			enemies[c][r] = new Enemy((float)r / ROWS);
			enemies[c][r]->sprites.push_back(smallEnemySprites[0]);
			enemies[c][r]->sprites.push_back(smallEnemySprites[1]);

			float posY = spawnRange.y + (spawnRange.height * ((float)(r + 0.5f) / ROWS));
			enemies[c][r]->position = { posX, posY };
			enemies[c][r]->UpdateStartingPosition();
			undefeatedEnemies.push_back(enemies[c][r]);
		}
	}
}

bool EnemyManager::ShouldShift()
{
	switch (direction)
	{
		case 1:
			return !InBounds(enemies[LastColumn()][0], spawnRange.width + 40, spawnRange.height + 40);
		case -1:
			return !InBounds(enemies[0][0], spawnRange.width - 40, spawnRange.height - 40);
		default:
			return false;
	}
	return false;
}

void EnemyManager::ShiftDown()
{
	direction *= -1;
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			if (enemies[c][r] != nullptr)
			{
				enemies[c][r]->ShiftDown(spawnRange.height / ROWS);
			}
		}
	}
}

void Enemy::OnCollisionStay(Collider* other)
{
	if (other->gameObject->name == "Bullet")
	{
		Destroy(other->gameObject);
		defeated = true;
		EnemyManager::instance->reset = true;
	}
}

void EnemyManager::Update()
{
	timeElapsed += GetFrameTime();
	if (timeElapsed >= shootTimer && GetRandomEnemy() != nullptr)
	{
		timeElapsed = 0;
		GetRandomEnemy()->Shoot({ 0, -5 });
	}

	// Check if we should shift enemies down
	if (ShouldShift())
	{
		ShiftDown();
	}

	// Check if the any enemy has passed the yCross line
	if (enemies[LastColumn()][LastRow()]->position.y >= yCross)
	{
		GameManager::Lose("The enemies crossed the line!");
	}

	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			for (int i = 0; i < objects.size(); i++)
			{
				if (!enemies[c][r]->Defeated())
				{
					// Check for collision
					if (enemies[c][r]->collider->GetBounds().CheckCollision(objects[i]->collider->GetBounds()))
					{
						enemies[c][r]->OnCollisionStay(objects[i]->collider);
						objects[i]->OnCollisionStay(enemies[c][r]->collider);
					}
					enemies[c][r]->OnUpdate();
				}
			}
		}
	}
}

void EnemyManager::Draw()
{
	DrawLine(0, yCross, GetScreenWidth(), yCross, GREEN);
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			if (!enemies[c][r]->Defeated())
			{
				enemies[c][r]->OnDraw();
			}
		}
	}
	if (reset)
	{
		FixUndefeatedEnemies();
		reset = false;
	}
}

Enemy* EnemyManager::GetRandomEnemy()
{
	if (undefeatedEnemies.size() == 0)
	{
		return nullptr;
	}
	return undefeatedEnemies[GetRandomValue(0, undefeatedEnemies.size() - 1)];
}

void EnemyManager::FixUndefeatedEnemies()
{
	undefeatedEnemies.clear();
	for (int c = COLS - 1; c >= 0; c--)
	{
		for (int r = 0; r < ROWS; r++)
		{
			if (enemies[c][r] != nullptr && !enemies[c][r]->Defeated())
			{
				undefeatedEnemies.push_back(enemies[c][r]);
			}
		}
	}

	// Cache undefeated enemies size
	int enemiesLeft = undefeatedEnemies.size();

	switch (enemiesLeft)
	{
	case 0:
		// We won the game
		GameManager::Win();
		break;
	case 1:
		// Make the last enemy move faster
		undefeatedEnemies[0]->FastMode();
		break;
	}
}

int EnemyManager::LastColumn()
{
	for (int c = COLS - 1; c >= 0; c--)
	{
		for (int r = 0; r < ROWS; r++)
		{
			if (enemies[c][r] != nullptr && !enemies[c][r]->Defeated())
			{
				return c;
			}
		}
	}
	return 0;
}

int EnemyManager::LastRow()
{
	for (int r = ROWS - 1; r >= 0; r--)
	{
		for (int c = 0; c < COLS; c++)
		{
			if (enemies[c][r] != nullptr && !enemies[c][r]->Defeated())
			{
				return r;
			}
		}
	}
	return 0;
}