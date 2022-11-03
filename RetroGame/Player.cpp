#include "Player.h"
#include "raylib.h"
#include "Utility.h"

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
}

void Player::Draw()
{
	DrawRectangle((int)position.x, (int)position.y, 25, 25, RED);
}

void Player::Shoot()
{

}