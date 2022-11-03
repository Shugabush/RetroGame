#include "Player.h"
#include "raylib.h"
#include "Utility.h"
#include "Bullet.h"

Player::Player()
{
	health = 3;
	movementSpeed = 1;
}

void Player::Start()
{
	
}

void Player::Update()
{
	position.x += GetInput() * movementSpeed;
	if (IsKeyPressed(KEY_SPACE))
	{
		// Fire a bullet
		Shoot({0, 5});
	}
}

void Player::Draw()
{
	//DrawTexturePro(*sprite, {50, 50}, {position.x, position.y}, {(float)(sprite->width) / 2,(float)(sprite->width) / 2}, rotation, WHITE);
	DrawRectangle((int)position.x, (int)position.y, 25, 25, RED);
}

void Player::Shoot(Vector2 vel)
{
	Bullet bullet;
	bullet.position = position;
	bullet.velocity = vel;
	Instantiate(&bullet);
}