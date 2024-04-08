#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&prevCount));
}

void TimeManager::Update()
{
	unsigned long long currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	deltaTime = (currentCount - prevCount) / static_cast<float>(frequency);
	prevCount = currentCount;
	frameCount++;

	frameTime += deltaTime;

	if (frameTime >= 1.0f)
	{
		fps = static_cast<unsigned int>(frameCount / frameTime);
		frameCount = 0;
		frameTime = 0;
	}
}

unsigned int TimeManager::GetFps()
{
	return fps;
}

float TimeManager::GetDeltaTime()
{
	return deltaTime;
}
