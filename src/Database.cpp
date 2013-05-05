#include <cstdlib>

#include "..\inc\sqlite3\sqlite3.h"

#include "..\inc\Database.h"
#include "..\inc\Log.h"

using namespace SOAR;

#define SQLITE3_ERROR_STR(code)	"sqlite3 error: " << sqlite3_errstr(code) << "(" << code << "):"

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

bool Database::Prepare(const char* query)
{
	lastReturnCode = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

	if (lastReturnCode == SQLITE_OK)
		return true;

	SOAR_LOG_RECOVERABLE << SQLITE3_ERROR_STR(lastReturnCode) << "failed to prepare statement from query: '" << query << "'";

	return false;
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

void Database::Done()
{
	sqlite3_finalize(stmt);
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
