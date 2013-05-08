#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3\sqlite3.h"

namespace SOAR
{

	/**
	 * Provides an abstraction layer and methods for interacting
	 * with a sqlite3 Database.
	 *
	 *	@see	http://www.sqlite.org/cintro.html
	 */
	class Database
	{
	private:

		/**
		 * Connection handle to the database file
		 */
		sqlite3*				db;

		/**
		 * Statement object used to evaluate queries
		 */
		sqlite3_stmt*			stmt;

		/**
		 * The most recently returned status code.
		 */
		int						lastReturnCode;

	public:

		/**
		 * Initiates a connection to a sqlite3 database
		 *
		 *	@param const char*	dbFilename	The database file
		 */
		Database(const char* dbFilename, int flags=SQLITE_OPEN_READWRITE);

		/**
		 * Shuts down the connection to the database, if such a connection exists
		 */
		~Database();

		/**
		 * Prepares a query to be executed that will return some data set. If succesful,
		 * data should be accessed using NextRow() and Get*() methods.
		 *
		 *	@param	const char*	query	The query string to prepare.
		 *	@return	bool		true if statement was prepared succesfully, false otherwise.
		 */
		bool QueryData(const char* query);

		/**
		 * Executes a query that is not expected to return a data set. (i.e. Insert, Update, Delete)
		 * 
		 *	@param	const char* query	The query string to execute
		 *	@return int 				The number of rows affected, -1 on error.
		 */
		int Query(const char* query);

		/**
		 * Advances the current row of the given statement
		 *
		 *	@return	bool	true if a valid row was found and data can be extracted.
		 */
		bool NextRow();

		/**
		 * Extract an integer from the current data row.
		 *
		 *	@param	int	columnIndex	The index of the column in the table to extract the data from.
		 *	@return int	The value requested, or -1 on error.
		 */
		int GetInt(int columnIndex=0);

		/**
		 * Extract raw text from the current data row.
		 *
		 *	@param	int columnIndex			The index of the data column in the table.
		 *	@return	const unsigned char*	The string of data requested
		 */
		const unsigned char* GetText(int columnIndex=0);

		/**
		 * Cleanup following the preparation and execution of a statement.
		 */
		void Done();

	private:

		/**
		 * Attempts to connect to a sqlite3 database.
		 *
		 *	@param	const char*	dbFilename	The database file
		 *	@param	int			flags		Additional flags for the connection.
		 *	@return	bool					True if the connection succeeded, false otherwise
		 *	
		 *	@see	http://www.sqlite.org/c3ref/open.html
		 */
		bool connect(const char* dbFilename, int flags=SQLITE_OPEN_READWRITE);

		/**
		 * Attempts to close an existing connection to a database.
		 *
		 *	@return	bool	True if a connection did not exist, or the connection existed and 
		 *					was successfully closed.
		 */
		bool close();

	};

}

#endif