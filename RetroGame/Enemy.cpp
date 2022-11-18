#include "Enemy.h"
#include "Utility.h"
#include "GameManager.h"
#include "SpritePool.h"
#include "SoundPool.h"
#include "Explosion.h"

EnemyManager* EnemyManager::instance = nullptr;

Enemy::Enemy(float delay = 0, int dir = 1)
{
	name = "New Enemy";
	health = 1;
	width = 25;
	height = 20;
	moveTimer = 1;
	moveTimer.Delay(delay);
	direction = dir;
	defeated = false;
	pointValue = 10;
	playInvaderSound = false;
	UpdateStartingPosition();
}

bool Enemy::Defeated()
{
	return defeated;
}

void Enemy::MoveFaster(float factor)
{
	moveTimer.Factor(1.0f / factor);
}

void Enemy::UpdateStartingPosition()
{
	startingPosition = position;
}

void Enemy::Update()
{
	moveTimer.Update();
	collider->SetBounds({ position.x, position.y, (float)width, (float)height });

	if (moveTimer.PastTimer())
	{
		// Time to shift the enemy over
		position.x += 5 * direction;
		moveTimer.Reset();

		if (playInvaderSound)
		{
			PlaySound(fastInvaderSounds[GetRandomValue(0, 3)]);
		}
	}
}

void Enemy::Shoot(Vector2 vel)
{
	Bullet* bullet = new Bullet();
	bullet->sprites.push_back(enemyBulletSprites[0]);
	bullet->sprites.push_back(enemyBulletSprites[1]);
	bullet->sprites.push_back(enemyBulletSprites[2]);
	bullet->sprites.push_back(enemyBulletSprites[3]);
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
	spawnRange = { 25, 50, 550, 300 };
	shootTimer = Timer(1);
	ufoTimer = Timer(10);
	yCross = 400;

	for (int c = 0; c < COLS; c++)
	{
		enemies[c] = new Enemy * [ROWS];
		float posX = spawnRange.x + (spawnRange.width * ((float)(c + 0.5f) / COLS));
		for (int r = 0; r < ROWS; r++)
		{
			float posY = spawnRange.y + (spawnRange.height * ((float)(r + 0.5f) / ROWS));
			enemies[c][r] = new Enemy((float)r * 5 / ROWS);

			Texture2D sprite;
			Texture2D sprite2;

			if (r < SMALLROWS)
			{
				enemies[c][r]->pointValue = 30;
				enemies[c][r]->width = 20;
				enemies[c][r]->height = 20;
				sprite = smallEnemySprites[0];
				sprite2 = smallEnemySprites[1];
			}
			else if (r < SMALLROWS + NORMALROWS)
			{
				enemies[c][r]->pointValue = 20;
				sprite = normalEnemySprites[0];
				sprite2 = normalEnemySprites[1];
			}
			else
			{
				enemies[c][r]->pointValue = 10;
				sprite = bigEnemySprites[0];
				sprite2 = bigEnemySprites[1];
			}
			
			enemies[c][r]->sprites.push_back(sprite);
			enemies[c][r]->sprites.push_back(sprite2);

			
			enemies[c][r]->position = { posX, posY };
			enemies[c][r]->UpdateStartingPosition();
			undefeatedEnemies.push_back(enemies[c][r]);
		}
	}
	enemies[0][0]->playInvaderSound = true; // Let the first enemy play the invader sound
}

bool EnemyManager::ShouldShift()
{
	switch (direction)
	{
		case 1:
			return enemies[LastColumn()][0]->position.x > screenWidth - 40;
		case -1:
			return enemies[FirstColumn()][0]->position.x < 40;
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
		// This enemy was defeated
		defeated = true;
		GameManager::UpdateScore(pointValue);
		EnemyManager::instance->reset = true;

		float speedFactor = 1.01f + (Clamp(GameManager::roundsCompleted, 0, 5) * 0.02f);
		songSpeed += 0.005f;
		SetMusicPitch(song, songSpeed);

		EnemyManager::instance->MoveFaster(speedFactor);

		PlaySound(invaderKilledSound);

		Explosion* explosion = new Explosion();
		explosion->sprites.push_back(enemyExplosionSprite);
		explosion->position = position;
		explosion->width = 25;
		explosion->height = 20;
		explosion->color = color;
		Instantiate(explosion);

		Destroy(other->gameObject);
	}
}

void EnemyManager::Update()
{
	shootTimer.Update();
	if (shootTimer.PastTimer() && GetRandomEnemy() != nullptr)
	{
		shootTimer.Reset();
		GetRandomEnemy()->Shoot({ 0, -5 });
	}

	ufoTimer.Update();
	if (ufoTimer.PastTimer())
	{
		// Instantiate a ufo
		Ufo* ufo = new Ufo();
		Instantiate(ufo);

		ufoTimer.Reset();
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
				}
			}
			enemies[c][r]->OnUpdate();
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

void EnemyManager::MoveFaster(float factor)
{
	for (int r = ROWS - 1; r >= 0; r--)
	{
		for (int c = 0; c < COLS; c++)
		{
			enemies[c][r]->MoveFaster(factor);
		}
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

	if (enemiesLeft == 0)
	{
		// We won the game
		GameManager::Win();
	}
}

int EnemyManager::FirstRow()
{
	for (int r = 0; r < ROWS; r++)
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

int EnemyManager::FirstColumn()
{
	for (int c = 0; c < COLS; c++)
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

Ufo::Ufo()
{
	pointValue = 100;
	sprites.push_back(ufoSprite);
	width = 25;
	height = 25;
	position = { 0, 25 };
}

void Ufo::Update()
{
	color = RED;
	collider->SetBounds({ position.x, position.y, (float)width, (float)height });
	position.x += 5;
	if (!InBounds(this))
	{
		// Destroy this object when it goes off screen
		Destroy(this);
	}
	else
	{
		if (!IsSoundPlaying(ufoSounds[1]))
		{
			PlaySound(ufoSounds[1]);
		}
	}
}

void Ufo::OnCollisionStay(Collider* other)
{
	if (other->gameObject->name == "Bullet")
	{
		GameManager::UpdateScore(pointValue);
		Destroy(other->gameObject);
		Destroy(this);
		PlaySound(ufoSounds[0]);

		// Create explosion
		Explosion* explosion = new Explosion();
		explosion->sprites.push_back(ufoExplosionSprite);
		explosion->position = position;
		explosion->width = 40;
		explosion->height = 20;
		explosion->color = color;
		Instantiate(explosion);
	}
}