#ifndef TIMER_H
#define TIMER_H

#include <ctime>
 
namespace SOAR
{
	namespace Time
	{
		/**
		 * This is a function used to get the current
		 * time since the program started.
		 * @return The number of seconds since glfwInit was called
		 */
		double GetTime();

		/**
		 * Keeps track of time and how often it should signal that it's limit has
		 * been hit. When it's created, it takes the current time as it's starting 
		 * point, and then will flip a flag each time it's interval has elapsed, 
		 * meaning it has 'expired'. 
		 */
		class Timer 
		{
		private: 
	
			/**
			 * Time that this timer was initialized
			 */
			double started;
	
			/**
			 * The interval in seconds between each signal from this timer.
			 */
			double interval;
	
			/**
			 * Time when this timer last expired, 0 if it hasn't expired yet.
			 */
			double lastExpired;
	
			/**
			 * Expired flag, will remain true once the timer has expired
			 * until the expired() method is called. This ensures that 
			 * expirations do not pass unnoticed.
			 */
			bool expired;
	
		public:
	
			/**
			 * Constructor, notice that an interval value is optional.
			 * If no interval is set, it may be set later. If not, then
			 * this timer will never expire
			 */
			Timer(double intervalInSeconds=0);
	
			/**
			 * Destructor
			 */ 
			~Timer()
			{}

			/**
			 * Updates the timer given the current time
			 */
			void update();
	
			/**
			 * See if this timer has expired
			 */
			bool hasExpired();
	
			/**
			 * Get the total time elapsed since this timer began
			 */
			double totalElapsed();
	
			/**
			 * Get the time elapsed since this time last expired
			 */
			double elapsed();
	
			/**
			 * Set an interval for this timer. Resets expired flag.
			 */
			void setInterval(double newInterval);
		};
	}
}

#endif
