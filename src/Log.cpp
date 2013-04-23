#include <fstream>
#include <sstream>
#include <exception>
#include <ctime>

#include "../inc/Log.h"
#include "../inc/DateTime.h"

using namespace std;
using namespace SOAR;

const char* const Log::LOG_FILENAME = "messages.log";

Log::Log()
{
	formatStr = "%x %X";

	output.clear();
}

Log::~Log()
{
	ofstream outputFile(LOG_FILENAME, ios_base::app);
	if (outputFile.good()) 
	{
		newLine();
		outputFile << output.str();
	}
}

Log* Log::GetInstance() 
{
	static Log instance;

	return &instance;
}

stringstream& Log::Output()
{
	return output;
}

void Log::SetDTFormat(const char* newFormatStr)
{
	formatStr = newFormatStr;
}

void Log::newLine()
{
	output << endl << "[" << DateTime::GetInstance()->GetFormatted(formatStr) << "]";
}
