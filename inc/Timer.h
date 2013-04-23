#ifndef TIMER_H
#define TIMER_H

#include <ctime>
 
namespace SOAR
{

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
		time_t started;

		/**
		 * The interval in seconds between each signal from this timer.
		 */
		time_t interval;

		/**
		 * Time when this timer last expired, 0 if it hasn't expired yet.
		 */
		time_t lastExpired;

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
		Timer(time_t intervalInSeconds=0);

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
		time_t totalElapsed();

		/**
		 * Get the time elapsed since this time last expired
		 */
		time_t elapsed();

		/**
		 * Set an interval for this timer. Resets expired flag.
		 */
		void setInterval(time_t newInterval);
	};

}

#endif
