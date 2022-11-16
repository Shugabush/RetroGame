#include "GameObject.h"

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
	//collider->SetBounds({ 0, 0, 0, 0 });
	Update();
}

void GameObject::Update()
{
	
}

void GameObject::OnDraw()
{
	Draw();
}

void GameObject::Draw()
{

}

void GameObject::LateDraw()
{

}

void GameObject::OnCollisionEnter(Collider* other)
{

}

void GameObject::OnCollisionStay(Collider* other)
{
	
}

void GameObject::OnCollisionExit(Collider* other)
{

}

void SpriteObject::Draw()
{
	// Cache the extents and size so we don't have to call the functions more than once
	Vector3 extents = collider->Extents();
	Vector3 size = collider->Size();
	DrawTexturePro(sprite, { 0, 0, (float)sprite.width, (float)sprite.height }, { position.x - extents.x, position.y - extents.y, size.x, size.y }, { 0, 0 }, 0, WHITE);
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

Vector3 Collider::Size()
{
	return Vector3Subtract(bounds->max, bounds->min);
}

Vector3 Collider::Extents()
{
	return Vector3Divide(Size(), {2, 2, 2});
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
