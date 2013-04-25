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
	public:

		/**
		 * Levels of messages that can be logged
		 */
		enum MessageLevel
		{
			NO_LOGGING = -1,
			FATAL_ERROR = 0,
			RECOVERABLE_ERROR,
			WARNING,
			NOTICE,
			MESSAGE
		};

	private:
		/**
		 * Constant for log filename
		 */
		static const char* const		LOG_FILENAME;

		/**
		 * String represenatations of each message level
		 */
		static const char* const		MSG_LEVEL_STR[];
	
		/** 
		 * Message level filter. Messages with a priority level greater than
		 * this level will not be logged.
		 */
		MessageLevel					filterLevel;

		static const MessageLevel		DEFAULT_FILTER_LEVEL = WARNING;

		/**
		 * Format String to use for date/time in the logfile
		 */
		string							formatStr;

		/**
		 * Output stream
		 */
		stringstream					output;

		const static int				MAX_LENGTH_BEFORE_FLUSH = 1000;

		/**
		 * Trash stream for messages that won't be logged.
		 */
		stringstream					trash;

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
		stringstream& Message(MessageLevel priorityLevel=MESSAGE);

		/**
		 * This method will change the filter level for log messages.
		 */
		void SetFilterLevel(MessageLevel newFilter);

		/**
		 * Sets the format string used to format date and time values for
		 * the log. 
		 * 
		 * See here for valid format string values:
		 * http://www.cplusplus.com/reference/ctime/strftime/
		 */
		void SetDTFormat(const char* newFormatStr);

		/**
		 * This method forces the log contents to be written to file immediately.
		 */
		void Flush();

	private:

		/** 
		 * This method starts a new line in the log file. The beginning 
		 * of the line will contain a Date/Time stamp as well as an 
		 * indicator of the message level.
		 */
		void newLine(MessageLevel priorityLevel);

		/**
		 * This method will write the current output stream to file and then clear it.
		 */
		void saveToFile();
	};

}

#endif
