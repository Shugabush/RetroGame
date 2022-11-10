#include "GameObject.h"
#include "Utility.h"

#include <typeinfo>
#include <iostream>

GameObject::GameObject()
{
	name = "New Game Object";
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
	OnUpdate();
}

void GameObject::OnUpdate()
{
	collider->SetBounds({ 0, 0, 0, 0 });
	Update();
	
}

void GameObject::Update()
{
	
}

void GameObject::OnDraw()
{
	Draw();
	DrawCollider();
}

void GameObject::Draw()
{

}

void GameObject::DrawCollider()
{
	int width = (int)(collider->GetBounds().max.x - collider->GetBounds().min.x);
	int height = (int)(collider->GetBounds().max.y - collider->GetBounds().min.y);
	DrawRectangleLines((int)position.x - (width / 2), (int)position.y - (height / 2), width, height, BLACK);
}

void GameObject::OnCollisionEnter(Collider* other)
{

}

void GameObject::OnCollisionStay(Collider* other)
{
	std::cout << collider->gameObject->name << " colliding with " << other->gameObject->name << std::endl;
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
	this->bounds = new raylib::BoundingBox();
	SetBounds(Rectangle());
}

Collider::Collider(GameObject* obj, raylib::BoundingBox bounds)
{
	gameObject = obj;
	this->bounds = &bounds;
}

raylib::BoundingBox Collider::GetBounds()
{
	return *bounds;
}

void Collider::SetBounds(Rectangle rect)
{
	bounds->min.x = gameObject->position.x - (rect.width / 2);
	bounds->min.y = gameObject->position.y - (rect.height / 2);
	bounds->min.z = -1;
	bounds->max.x = gameObject->position.x + (rect.width / 2);
	bounds->max.y = gameObject->position.y + (rect.height / 2);
	bounds->max.z = 1;
}
