#include <ctime>
#include <string>

#include "..\inc\DateTime.h"

using namespace std;
using namespace SOAR;

DateTime::DateTime(void)
{
	refresh();

	memset(formattedTime, 0, MAX_STR_LENGTH);
}

DateTime::~DateTime(void)
{

}

DateTime* DateTime::GetInstance()
{
	static DateTime instance;

	return &instance;
}

char* DateTime::GetFormatted(const string& formatStr)
{
	strftime(formattedTime, MAX_STR_LENGTH, formatStr.c_str(), timeInfo);

	return formattedTime;
}

void DateTime::refresh()
{
	time(&timeSeconds);
	localtime_s(timeInfo, &timeSeconds);
}