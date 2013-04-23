#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace SOAR
{

	/**
	 * A log class implemented as a singleton. 
	 * The class internally maintains a stringstream 
	 * object which is what is actually 'written' to by the class. In this
	 * class's destructor it appends/writes the stringstream to the log file.
	 */
	class Log
	{
	private:
		/**
		 * Constant for log filename
		 */
		static const char* const		LOG_FILENAME;
	
		/**
		 * Format String to use for date/time in the logfile
		 */
		string							formatStr;

		/**
		 * Output stream
		 */
		stringstream					output;

		/**
		 * Initializes the LOG_FILENAME constant and clears the 
		 * output in preparation for writing.
		 */ 
		Log();

		/**
		 * 
		 */
		~Log();

	public:

		/**
		 * Returns a pointer to the single instance of this class.
		 */
		static Log* GetInstance();

		/**
		 * Returns a reference to the output stream for writing.
		 */
		stringstream& Output();

		/**
		 * Sets the format string used to format date and time values for
		 * the log. 
		 * 
		 * See here for valid format string values:
		 * http://www.cplusplus.com/reference/ctime/strftime/
		 */
		void SetDTFormat(const char* newFormatStr);

	private:

		/** 
		 * Starts a new line in log file.
		 * Inserts current date and time string.
		 */
		void newLine();
	};

}

#endif
