#include "../inc/FPSCounter.h"
#include "../inc/Timer.h"

using namespace SOAR;

FPSCounter::FPSCounter()
{
	currentFrameCount = 0;
	lastFrameCount = 0;
	fpsTimer.setInterval(1); // Set the timer interval to 1 second
}

FPSCounter *FPSCounter::getInstance()
{
	static FPSCounter instance;

	return &instance;
}

void FPSCounter::countFrame()
{
	fpsTimer.update();

	if (fpsTimer.hasExpired())
	{
		lastFrameCount = currentFrameCount;
		currentFrameCount = 0;
	}

	currentFrameCount++;
}
