#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Some helpful Macros
#define LOG_SPACE               << " "
#define LOG_FATAL               SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::FATAL_ERROR) LOG_SPACE
#define LOG_RECOVERABLE         SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::RECOVERABLE_ERROR) LOG_SPACE
#define LOG_WARNING             SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::WARNING) LOG_SPACE
#define LOG_NOTICE              SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::NOTICE) LOG_SPACE
#define LOG_MESSAGE             SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::MESSAGE) LOG_SPACE

#define SOAR_HEADER             "[SOAR:" << __FILE__ << ":" << __LINE__ << "] "
#define SOAR_LOG_FATAL          SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::FATAL_ERROR) << SOAR_HEADER
#define SOAR_LOG_RECOVERABLE    SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::RECOVERABLE_ERROR) << SOAR_HEADER
#define SOAR_LOG_WARNING        SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::WARNING) << SOAR_HEADER
#define SOAR_LOG_NOTICE         SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::NOTICE) << SOAR_HEADER
#define SOAR_LOG_MESSAGE        SOAR::Util::Log::GetInstance()->Message(SOAR::Util::Log::MessageLevel::MESSAGE) << SOAR_HEADER

namespace SOAR
{
    namespace Util
    {
        /**
         * Used to log errors, warnings, or messages to file.
         *
         *  @author Ben Draut
         *  @date   April 2013
         *
         */
        class Log
        {
        public:
    
            /**
             * Levels Priority Levels
             */
            enum MessageLevel
            {
                NO_LOGGING = -1,
                FATAL_ERROR = 0,
                RECOVERABLE_ERROR = 1,
                WARNING = 2,
                NOTICE = 3,
                MESSAGE = 4,
                LOG_ALL = 4
            };
    
        private:
            
            static const char* const        LOG_FILENAME;
            static const char* const        MSG_LEVEL_STR[];
        
            static const MessageLevel       DEFAULT_FILTER_LEVEL = WARNING;
    
            const static unsigned int       MAX_LENGTH_BEFORE_FLUSH = 1000;
    
            /** 
             * Message level filter. Messages with a priority level greater than
             * this level will not be logged.
             */
            MessageLevel                    filterLevel;
    
            /**
             * Format String to use for date/time in the logfile
             */
            string                          formatStr;
    
            /**
             * Output stream
             */
            stringstream                    output;
    
            /**
             * Trash stream for messages that won't be logged.
             */
            stringstream                    trash;
    
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
             * Ends the current line in the file inserts [Date/Time][Priority Leve].
             * 
             *  @param  priorityLevel   The priority level of this line.
             *  @return none
             *
             */
            void newLine(MessageLevel priorityLevel);
    
            /**
             * Saves output to LOG_FILENAME
             *
             *  @return none
             */
            void saveToFile();
        };
    }
}

#endif
