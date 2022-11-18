#include "Player.h"
#include "Utility.h"
#include "Bullet.h"
#include "GameManager.h"
#include "SoundPool.h"
#include "Explosion.h"

Player::Player(int health)
{
	this->health = 3;
	movementSpeed = 1;
	width = 25;
	height = 25;
	shootTimer = Timer(0.25f);
	sprites.push_back(playerSprite);
}

void Player::Start()
{
	
}

void Player::Update()
{
	shootTimer.Update();

	position.x += GetInput() * movementSpeed;

	// Clamp player's position to the screen extents
	position = Clamp(position, { 0, 0 }, { (float)GetScreenWidth(), (float)GetScreenHeight() });

	if (shootTimer.PastTimer() && IsKeyPressed(KEY_SPACE))
	{
		shootTimer.Reset();

		// Fire a bullet
		Shoot({0, 5});
	}

	collider->SetBounds({ position.x, position.y, (float)width, (float)height });
}

void Player::Draw()
{
	if (health > 0)
	{
		// Cache the extents and size so we don't have to call the functions more than once
		Vector3 extents = collider->Extents();
		Vector3 size = collider->Size();

		DrawTexturePro(sprites[currentSprite], { 0, 0, (float)sprites[currentSprite].width, (float)sprites[currentSprite].height }, { position.x, position.y, size.x, size.y }, { extents.x, extents.y }, rotation, color);
	}
}

void Player::LateDraw()
{
	std::string healthString = "Health: ";
	healthString += std::to_string(health);
	DrawText(healthString.c_str(), 25, 550, 25, RED);
}

void Player::Shoot(Vector2 vel)
{
	PlaySound(shootSound);
	Bullet* bullet = new Bullet();
	bullet->sprites.push_back(playerBulletSprites[0]);
	bullet->sprites.push_back(playerBulletSprites[1]);
	bullet->sprites.push_back(playerBulletSprites[2]);
	bullet->sprites.push_back(playerBulletSprites[3]);
	bullet->position = position;
	bullet->velocity = vel;
	Instantiate(bullet);
}

void Player::TakeDamage()
{
	health--;
	PlaySound(playerKilledSound);
	if (health <= 0)
	{
		// Create explosion
		Explosion* explosion = new Explosion();
		explosion->sprites.push_back(playerExplosionSprites[0]);
		explosion->sprites.push_back(playerExplosionSprites[1]);
		explosion->position = position;
		explosion->width = 30;
		explosion->height = 20;
		explosion->color = color;

		explosion->collider->SetBounds({ position.x, position.y, (float)30, (float)20 });

		Instantiate(explosion);

		GameManager::Lose();
	}
}

void Player::OnCollisionStay(Collider* other)
{
	if (other->gameObject->name == "Enemy Bullet")
	{
		Destroy(other->gameObject);
		TakeDamage();
	}
}