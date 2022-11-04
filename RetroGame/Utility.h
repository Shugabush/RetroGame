#pragma once
#include "GameObject.h"
#include "raylib-cpp.hpp"

#include <typeinfo>
#include <vector>

int GetInput();

extern std::vector<GameObject*> objects;
extern std::vector<GameObject*> pendingObjects;
extern std::vector<GameObject*> objectsToDestroy;

void Instantiate(GameObject* obj);
void Destroy(GameObject* obj);

void Start();
void Update();

void Draw();

void ProcessPendingObjects();
void DestroyObjects();
void Quit();

bool InBounds(GameObject* obj);
bool InBounds(GameObject* obj, float width, float height);
bool ObjectsOverlap(GameObject* a, GameObject* b);

Vector2 Clamp(Vector2 value, Vector2 min, Vector2 max);