#include <cstdlib>
#include <fstream>
#include <cstring>

#include <sqlite3.h>

#include "Database.h"
#include "Log.h"

using namespace std;

using namespace SOAR;

// Apparently sqlite3_errstr is pretty new.
//#define SQLITE3_ERROR_STR(code)	"sqlite3 error: " << sqlite3_errstr(code) << "(" << code << "):"
#define SQLITE3_ERROR_STR(code)		"sqlite3 error: " << sqlite3_errmsg(db) << "(" << sqlite3_errcode(db) << "):"

Database::Database(const char* dbFilename, int flags)
{
	if (!connect(dbFilename, flags))
		SOAR_LOG_FATAL << "failed to connect to '" << dbFilename << "'";
}

Database::~Database()
{
	if (!close())
		SOAR_LOG_WARNING << "close() call failed.";
}

bool Database::QueryData(const char* query)
{
	lastReturnCode = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

	if (lastReturnCode == SQLITE_OK)
		return true;

	SOAR_LOG_RECOVERABLE << SQLITE3_ERROR_STR(lastReturnCode) << "failed to prepare statement from query: '" << query << "'";

	return false;
}

int Database::Query(const char* query)
{
	if (!QueryData(query))
		return -1;

	if (!NextRow())
		return -1;

	return sqlite3_changes(db);
}

bool Database::NextRow()
{
	lastReturnCode = sqlite3_step(stmt);

	if (lastReturnCode == SQLITE_ROW)
		return true;

	if (lastReturnCode != SQLITE_DONE)
		SOAR_LOG_RECOVERABLE << SQLITE3_ERROR_STR(lastReturnCode) << "failed to retrieve the next row, but the end of the data set has not been reached.";

	return false;
}

int Database::GetInt(int columnIndex)
{
	if (lastReturnCode != SQLITE_ROW)
	{
		SOAR_LOG_RECOVERABLE << "a valid data row has not been retrieved.";
		return -1;
	}

	return sqlite3_column_int(stmt, columnIndex);
}

bool Database::GetBool(int columnIndex)
{
	return GetInt(columnIndex) > 0;
}

const unsigned char* Database::GetText(int columnIndex)
{
	if (lastReturnCode != SQLITE_ROW)
	{
		SOAR_LOG_RECOVERABLE << "a valid data row has not been retrieved.";
		return 0;
	}

	return sqlite3_column_text(stmt, columnIndex);
}

void Database::Done()
{
	sqlite3_finalize(stmt);
}

bool Database::ImportFile(const char* filename)
{
	ifstream file(filename);
	
	if (!file)
	{
		SOAR_LOG_WARNING << "Failed to open " << filename;
		return false;
	}

	stringstream fileContents;
	fileContents << file.rdbuf();
	file.close();

	lastReturnCode = sqlite3_exec(db, fileContents.str().c_str(), NULL, NULL, NULL);

	if (lastReturnCode == SQLITE_OK)
		return true;
	
	SOAR_LOG_WARNING << "Failed to import " << filename;

	return false;
}

int Database::Status()const
{
	return lastReturnCode;
}

bool Database::connect(const char* dbFilename, int flags)
{
	lastReturnCode = sqlite3_open_v2(dbFilename, &db, flags, NULL);

	if (lastReturnCode == SQLITE_OK)
		return true;

	SOAR_LOG_FATAL << SQLITE3_ERROR_STR(lastReturnCode) << "failed connect to database.";

	return false;
}

bool Database::close()
{
	if (db == NULL)
	{
		SOAR_LOG_NOTICE << "attempted to close an uninitialized connection.";
		return true;
	}

	return sqlite3_close_v2(db) == SQLITE_OK;
}
