#include "GameObject.h"
#include "Utility.h"

#include <typeinfo>
#include <iostream>

GameObject::GameObject()
{
	collider = new Collider(this);
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

void GameObject::DrawCollider()
{
	int width = (int)(collider->GetBounds().max.x - collider->GetBounds().min.x) / 2;
	int height = (int)(collider->GetBounds().max.y - collider->GetBounds().min.y) / 2;
	DrawRectangleLines((int)position.x - (width / 2), (int)position.y - (height / 2), width, height, WHITE);
}

void GameObject::OnCollisionEnter(Collider* other)
{

}

void GameObject::OnCollisionStay(Collider* other)
{
	std::cout << collider << " " << other << std::endl;
}

void GameObject::OnCollisionExit(Collider* other)
{

}

void SpriteObject::Draw()
{
	if (sprite != nullptr)
	{
		DrawTexture(*sprite, (int)position.x, (int)position.y, WHITE);
	}
}

Collider::Collider(GameObject* obj)
{
	gameObject = obj;
	this->bounds = new BoundingBox();
	SetBounds(Rectangle());
}

Collider::Collider(GameObject* obj, BoundingBox bounds)
{
	gameObject = obj;
	this->bounds = &bounds;
}

BoundingBox Collider::GetBounds()
{
	return *bounds;
}

void Collider::SetBounds(Rectangle rect)
{
	bounds->min.x = gameObject->position.x - rect.width;
	bounds->min.y = gameObject->position.y - rect.height;
	bounds->max.x = gameObject->position.x + rect.width;
	bounds->max.y = gameObject->position.y + rect.height;
}
