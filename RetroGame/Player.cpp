#include "Player.h"
#include "raylib.h"

Player::Player()
{
	health = 3;
}

void Player::Start()
{
	
}

void Player::Update()
{
	
}

void Player::Draw()
{
	DrawRectangle((int)position.x, (int)position.y, 25, 25, RED);
}

void Player::Shoot()
{

}