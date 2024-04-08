#pragma once
#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
public:
	void Init();
	void Update();

	unsigned int GetFps();
	float GetDeltaTime();

private:
	unsigned long long frequency = 0;
	unsigned long long prevCount = 0;
	float deltaTime = 0.0f;

private:
	unsigned int frameCount = 0;
	float frameTime = 0.0f;
	unsigned int fps = 0;
};

