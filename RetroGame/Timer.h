#pragma once
#include "raylib-cpp.hpp"

struct Timer
{
	Timer();
	Timer(float timer);

	void Update(); // Update time elapsed
	void Reset(); // Reset time elapsed
	void Delay(float delay); // Add a delay to the timer (subtract the value from time elapsed)

	bool PastTimer(); // Has time elapsed passed the timer?

private:
	float timer; // How much time until time elapsed gets reset?
	float timeElapsed; // Time elapsed since the last time we hit the timer
};