#include "Utility.h"
#include "GameManager.h"
#include "Player.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Background.h"

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
	for (int i = 0; i < objectsToDestroy.size(); i++)
	{
		if (objectsToDestroy[i] == obj)
		{
			return;
		}
	}
	if (obj != nullptr)
	{
		objectsToDestroy.push_back(obj);
	}
}

void StartGame()
{
	objects.clear();
	objectsToDestroy.clear();
	pendingObjects.clear();

	// Create and add the background
	Background* background = new Background();
	objects.push_back(background);

	// Create and add the player
	Player* player = new Player(3);
	player->movementSpeed = 5;
	player->position = { screenWidth / 2, 500 };
	objects.push_back(player);

	// Create and add barriers
	Barrier* barrier1 = new Barrier(5);
	barrier1->name = "Barrier1";
	barrier1->position = { 125, 400 };
	barrier1->width = 50;
	barrier1->height = 25;
	Barrier* barrier2 = new Barrier(5);
	barrier2->name = "Barrier2";
	barrier2->position = { screenWidth / 2, 400 };
	barrier2->width = 50;
	barrier2->height = 25;
	Barrier* barrier3 = new Barrier(5);
	barrier3->name = "Barrier3";
	barrier3->position = { 475, 400 };
	barrier3->width = 50;
	barrier3->height = 25;
	objects.push_back(barrier1);
	objects.push_back(barrier2);
	objects.push_back(barrier3);

	EnemyManager* enemyManager = new EnemyManager();
	objects.push_back(enemyManager);

	GameManager* gameManager = new GameManager();
	objects.push_back(gameManager);
}

void Start()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] != nullptr)
		{
			objects[i]->Start();
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

// Late draw for if we want some game objects
// to draw on top of all others
void LateDraw()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->LateDraw();
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
		std::cout << objectsToDestroy[i]->name << std::endl;
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

bool Inbounds(GameObject* obj, Vector2 size, Vector2 center)
{
	if (obj == nullptr)
	{
		return false;
	}

	if (obj->position.x < center.x - size.x)
	{
		return false;
	}
	if (obj->position.x > center.x + size.x)
	{
		return false;
	}
	if (obj->position.y < center.y - size.y)
	{
		return false;
	}
	if (obj->position.y > center.y + size.y)
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