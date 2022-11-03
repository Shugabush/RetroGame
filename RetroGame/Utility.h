#pragma once
#include "GameObject.h"
#include <vector>

int GetInput();

extern std::vector<GameObject*> objects;
extern std::vector<GameObject*> pendingObjects;
extern std::vector<GameObject*> objectsToDestroy;

void Instantiate(GameObject* obj);
void Destroy(GameObject* obj);

void Update();

void Draw();

void ProcessPendingObjects();
void DestroyObjects();
void Quit();

bool InBounds(GameObject* obj);

float Clamp(float value, float min, float max);
Vector2 Clamp(Vector2 value, Vector2 min, Vector2 max);