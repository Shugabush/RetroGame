#include "Utility.h"

#include <iostream>

std::vector<GameObject*> objects;
std::vector<GameObject*> pendingObjects;
std::vector<GameObject*> objectsToDestroy;

int GetInput()
{
	int input = 0;
	if (IsKeyDown(KEY_LEFT))
	{
		input--;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		input++;
	}
	return input;
}

// Only use these methods with
// GameObjects that you called new on
// or else the program will likely break
void Instantiate(GameObject* obj)
{
	pendingObjects.push_back(obj);
}
void Destroy(GameObject* obj)
{
	objectsToDestroy.push_back(obj);
}

void Start()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] != nullptr)
		{
			objects[i]->OnUpdate();
		}
	}
}

void Update()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] != nullptr)
		{
			objects[i]->OnUpdate();

			// Check for collision
			for (int c = 0; c < objects.size(); c++)
			{
				// If we're not comparing the same collider to itself
				if (objects[c] != objects[i])
				{
					if (CheckCollisionBoxes(objects[i]->collider->GetBounds(), objects[c]->collider->GetBounds()))
					{
						objects[i]->OnCollisionStay(objects[c]->collider);
					}
				}
			}
		}
	}
}

void Draw()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->OnDraw();
	}
}

void ProcessPendingObjects()
{
	for (int i = 0; i < pendingObjects.size(); i++)
	{
		objects.push_back(pendingObjects[i]);
	}
	pendingObjects.clear();
}

void DestroyObjects()
{
	for (int i = 0; i < objectsToDestroy.size(); i++)
	{
		delete objectsToDestroy[i];
		objects.erase(std::remove(objects.begin(), objects.end(), objectsToDestroy[i]), objects.end());
	}
	objectsToDestroy.clear();
}

void Quit()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
	objects.clear();
}

bool InBounds(GameObject* obj)
{
	if (obj->position.x > GetScreenWidth())
	{
		return false;
	}
	if (obj->position.x < 0)
	{
		return false;
	}
	if (obj->position.y > GetScreenHeight())
	{
		return false;
	}
	if (obj->position.y < 0)
	{
		return false;
	}

	return true;
}

bool InBounds(GameObject* obj, float width, float height)
{
	if (obj == nullptr)
	{
		return false;
	}
	if (obj->position.x > width)
	{
		return false;
	}
	if (obj->position.x < 0)
	{
		return false;
	}
	if (obj->position.y > height)
	{
		return false;
	}
	if (obj->position.y < 0)
	{
		return false;
	}

	return true;
}

bool ObjectsOverlap(GameObject* a, GameObject* b)
{
	return false;
}

Vector2 Clamp(Vector2 value, Vector2 min, Vector2 max)
{
	value.x = Clamp(value.x, min.x, max.x);
	value.y = Clamp(value.y, min.y, max.y);
	return value;
}