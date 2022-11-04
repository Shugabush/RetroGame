#include "Enemy.h"

Enemy::Enemy()
{
	health = 1;
}

void Enemy::Update()
{

}

void Enemy::Draw()
{

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
	enemies = new Enemy[ROWS, COLS];
}

EnemyManager::~EnemyManager()
{
	delete[] enemies;
}