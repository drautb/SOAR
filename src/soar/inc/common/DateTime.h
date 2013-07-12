#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <ctime>
#include <string>

namespace SOAR
{

	class DateTime
	{
	private:

		const static int		MAX_STR_LENGTH = 64;

		time_t					timeSeconds;
		struct tm*				timeInfo;

		char					formattedTime[MAX_STR_LENGTH];

	private:

		/**
		 * Private constructor for Singleton
		 */
		DateTime();

	public:

		~DateTime();

		static DateTime* GetInstance();

		/**
		 * GetFormatted
		 * Returns a char* containing the current date/time formatted
		 * in a string, as specified by the format string.
		 * 
		 * See here for available format options:
		 * http://www.cplusplus.com/reference/ctime/strftime/
		 */
		char* GetFormatted(const char* formatStr="%x %X");

	private:

		void refresh();
	};

}

#endif

