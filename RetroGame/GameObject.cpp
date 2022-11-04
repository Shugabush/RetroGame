#include "GameObject.h"

GameObject::GameObject()
{
	position = {0, 0};
	rotation = 0;
}

void GameObject::Start()
{

}

void GameObject::Update()
{

}

void GameObject::Draw()
{

}

void SpriteObject::Draw()
{
	if (sprite != nullptr)
	{
		DrawTexture(*sprite, (int)position.x, (int)position.y, WHITE);
	}
}

Collider::Collider(Rectangle bounds)
{
	this->bounds = bounds;
}

void Collider::Update()
{

}

void Collider::OnCollisionStay(Collider* other)
{

}
