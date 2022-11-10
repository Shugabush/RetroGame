#include "Player.h"
#include "raylib.h"
#include "Utility.h"
#include "Bullet.h"

Player::Player(int health)
{
	this->health = 3;
	movementSpeed = 1;
	rectWidth = 25;
	rectHeight = 25;
	shootCooldown = 0.25f;
	timeElapsed = 0;
}

void Player::Start()
{
	
}

void Player::Update()
{
	timeElapsed += GetFrameTime();

	position.x += GetInput() * movementSpeed;
	position = Clamp(position, { 0, 0 }, { (float)GetScreenWidth(), (float)GetScreenHeight() });

	if (timeElapsed >= shootCooldown && IsKeyPressed(KEY_SPACE))
	{
		timeElapsed = 0;

		// Fire a bullet
		Shoot({0, 5});
	}

	collider->SetBounds({ position.x, position.y, (float)rectWidth, (float)rectHeight });
}

void Player::Draw()
{
	int posX = (int)position.x - (rectWidth / 2);
	int posY = (int)position.y - (rectHeight / 2);
	DrawRectangle(posX, posY, rectWidth, rectHeight, RED);
	DrawCollider();
}

void Player::Shoot(Vector2 vel)
{
	Bullet* bullet = new Bullet();
	bullet->position = position;
	bullet->velocity = vel;
	Instantiate(bullet);
}

void Player::TakeDamage()
{
	health--;
	std::cout << health << std::endl;
}

void Player::OnCollisionStay(Collider* other)
{
	if (other->gameObject->name == "Enemy Bullet")
	{
		Destroy(other->gameObject);
		TakeDamage();
	}
}