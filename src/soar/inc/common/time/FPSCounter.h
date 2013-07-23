#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <ctime>

#include "Timer.h"

namespace SOAR
{
	namespace Time
	{
		/**
		 * Keeps track of the number of frames per second (FPS) of 
		 * the application that is running. This depends on this 
		 * class being used properly...
		 * - Implemented as a singleton.
		 */
		class FPSCounter
		{
		private: 
	
			/**
			 * Frame counter, keeps track of the number of frames that
			 * have elapsed during this second.
			 */
			int currentFrameCount;
	
			/**
			 * Stores the number of frames executed during the 
			 * last cycle.
			 */
			int lastFrameCount;
	
			/**
			 * Timer to keep track of seconds.
			 */
			Timer fpsTimer;
	
			/**
			 * Private Constructor
			 */
			FPSCounter();
	
		public: 
	
			/**
			 * Get the single instance of this class
			 */
			static FPSCounter *getInstance();
	
			/**
			 * Call this method once each frame. It updates the counts
			 * and the timer appropriately.
			 */
			void countFrame();
	
			/**
			 * Get the number of frames that were counted during the last second.
			 */
			int getFrameRate()const{return lastFrameCount;}
		};
	}
}

#endif
