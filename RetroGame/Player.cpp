#include "Player.h"
#include "Utility.h"
#include "Bullet.h"
#include "GameManager.h"
#include "SoundPool.h"

Player::Player(int health)
{
	this->health = 3;
	movementSpeed = 1;
	rectWidth = 25;
	rectHeight = 25;
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

	collider->SetBounds({ position.x, position.y, (float)rectWidth, (float)rectHeight });
}

void Player::Draw()
{
	if (health > 0)
	{
		// Cache the extents and size so we don't have to call the functions more than once
		Vector3 extents = collider->Extents();
		Vector3 size = collider->Size();

		float widthToHeight = WidthToHeight();

		if (widthToHeight < 1)
		{
			size.x *= widthToHeight;
		}

		DrawTexturePro(sprites[currentSprite], { 0, 0, (float)sprites[currentSprite].width, (float)sprites[currentSprite].height }, { position.x, position.y, size.x, size.y }, { extents.x, extents.y }, rotation, WHITE);
	}
}

void Player::LateDraw()
{
	std::string healthString = "Health: ";
	healthString += std::to_string(health);
	DrawText(healthString.c_str(), 25, 25, 25, BLACK);
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