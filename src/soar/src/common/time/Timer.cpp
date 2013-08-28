#include <GLFW/glfw3.h>

#include "Timer.h"

using namespace SOAR;
using namespace Time;

double GetTime()
{
	return glfwGetTime();
}

Timer::Timer(double intervalInSeconds)
{
	started = GetTime();
	lastExpired = 0;
	setInterval(intervalInSeconds);
}

void Timer::update()
{
	double currentTime = GetTime();
	double lastTime = lastExpired == 0 ? started : lastExpired;

	if (currentTime - lastTime >= interval)
	{
		lastExpired = currentTime;
		expired = true;
	}
}

bool Timer::hasExpired()
{
	bool hasExpired = expired;
	expired = false;
	
	return hasExpired;
}

double Timer::totalElapsed()
{
	return GetTime() - started;
}

double Timer::elapsed()
{
	return GetTime() - lastExpired;
}

void Timer::setInterval(double newInterval)
{
	interval = newInterval;
	expired = false;
}