#include "Timer.h"

Timer::Timer()
{
	timer = 1;
	timeElapsed = 0;
}

Timer::Timer(float timer)
{
	this->timer = timer;
	timeElapsed = 0;
}

void Timer::Update()
{
	timeElapsed += GetFrameTime();
}

void Timer::Reset()
{
	timeElapsed = 0;
}

void Timer::Delay(float delay)
{
	timeElapsed -= delay;
}

bool Timer::PastTimer()
{
	return timeElapsed >= timer;
}