#include <ctime>

#include "Timer.h"

using namespace SOAR;

Timer::Timer(time_t intervalInSeconds)
{
	started = time(NULL);
	lastExpired = 0;
	setInterval(intervalInSeconds);
}

void Timer::update()
{
	time_t currentTime = time(NULL);
	time_t lastTime = lastExpired == 0 ? started : lastExpired;

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

time_t Timer::totalElapsed()
{
	return time(NULL) - started;
}

time_t Timer::elapsed()
{
	return time(NULL) - lastExpired;
}

void Timer::setInterval(time_t newInterval)
{
	interval = newInterval;
	expired = false;
}