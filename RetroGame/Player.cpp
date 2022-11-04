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
}

void Player::Start()
{
	
}

void Player::Update()
{
	position.x += GetInput() * movementSpeed;
	position = Clamp(position, { 0, 0 }, { (float)GetScreenWidth(), (float)GetScreenHeight() });
	if (IsKeyPressed(KEY_SPACE))
	{
		// Fire a bullet
		Shoot({0, 5});
	}
}

void Player::Draw()
{
	//DrawTexturePro(*sprite, {50, 50}, {position.x, position.y}, {(float)(sprite->width) / 2,(float)(sprite->width) / 2}, rotation, WHITE);
	int posX = (int)position.x - (rectWidth / 2);
	int posY = (int)position.y - (rectHeight / 2);
	DrawRectangle(posX, posY, rectWidth, rectHeight, RED);
}

void Player::Shoot(Vector2 vel)
{
	Bullet* bullet = new Bullet();
	bullet->position = position;
	bullet->velocity = vel;
	Instantiate(bullet);
}