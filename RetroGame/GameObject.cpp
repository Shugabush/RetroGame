#include "GameObject.h"
#include "Utility.h"

#include <typeinfo>

GameObject::GameObject()
{
	collider = new Collider();
	position = {0, 0};
	rotation = 0;
}
GameObject::~GameObject()
{
	delete collider;
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

Collider::Collider()
{
	this->bounds = Rectangle{0, 0, 0, 0};
}

Collider::Collider(Rectangle bounds)
{
	this->bounds = bounds;
}

void Collider::OnCollisionStay(Collider* other)
{

}
