#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <ctime>

#include "../inc/Log.h"
#include "../inc/DateTime.h"

using namespace std;
using namespace SOAR;

const char* const Log::LOG_FILENAME = "messages.log";

const char* const Log::MSG_LEVEL_STR[] = 
{
	"FATAL ERROR",
	"RECOVERABLE ERROR",
	"WARNING",
	"NOTICE",
	"MESSAGE"
};

Log::Log()
{
	formatStr = "%x %X";

	filterLevel = DEFAULT_FILTER_LEVEL;

	output.clear();
	trash.clear();
}

Log::~Log()
{
	Flush();
}

Log* Log::GetInstance() 
{
	static Log instance;

	return &instance;
}

stringstream& Log::Message(MessageLevel priorityLevel)
{
	// Check if need to flush
	if (output.str().size() > MAX_LENGTH_BEFORE_FLUSH)
		Flush();

	trash.clear();
	if (priorityLevel > filterLevel)
		return trash;

	newLine(priorityLevel);

	return output;
}

void Log::SetFilterLevel(MessageLevel newFilter)
{
	filterLevel = newFilter;
}

void Log::SetDTFormat(const char* newFormatStr)
{
	formatStr = newFormatStr;
}

void Log::Flush()
{
	saveToFile();
}

void Log::newLine(MessageLevel priorityLevel)
{
	if (priorityLevel == NO_LOGGING)
		return;

	output << endl;
	output << "[" << DateTime::GetInstance()->GetFormatted(formatStr.c_str()) << "]";
	output << "[" << MSG_LEVEL_STR[priorityLevel] << "]";
}

void Log::saveToFile()
{
	ofstream outputFile(LOG_FILENAME, ios_base::app);
	if (outputFile.good()) 
	{
		outputFile << output.str();

		outputFile.flush();
		outputFile.close();

		output.str(""); // Empty the output stream
	}
}
