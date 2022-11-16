#pragma once
#include "GameObject.h"

#include "raylib-cpp.hpp"

#include <typeinfo>
#include <vector>
#include <iostream>

int GetInput();

extern std::vector<GameObject*> objects;
extern std::vector<GameObject*> pendingObjects;
extern std::vector<GameObject*> objectsToDestroy;

const int screenWidth = 600;
const int screenHeight = 600;

void Instantiate(GameObject* obj);
void Destroy(GameObject* obj);

void StartGame();

void Start();
void Update();

void Draw();
void LateDraw();

void ProcessPendingObjects();
void DestroyObjects();
void Quit();

bool InBounds(GameObject* obj);
bool InBounds(GameObject* obj, float width, float height);
bool Inbounds(GameObject* obj, Vector2 size, Vector2 center);

bool ObjectsOverlap(GameObject* a, GameObject* b);

Vector2 Clamp(Vector2 value, Vector2 min, Vector2 max);