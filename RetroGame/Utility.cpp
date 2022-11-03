#include "Utility.h"
#include "raylib.h"
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

// Only use gameobjects that you called new on
// or else the program will likely break
void Instantiate(GameObject* obj)
{
	pendingObjects.push_back(obj);
}
void Destroy(GameObject* obj)
{
	objectsToDestroy.push_back(obj);
}

void Update()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (InBounds(objects[i]))
		{
			objects[i]->Update();
		}
		else
		{
			std::cout << "destroying" << std::endl;
			Destroy(objects[i]);
		}
	}
}

void Draw()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw();
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