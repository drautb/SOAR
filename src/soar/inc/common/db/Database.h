#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

namespace SOAR
{
	namespace DB
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
			 *	@param dbFilename	The database file
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
			 *	@param	query	The query string to prepare.
			 *	@return	true if statement was prepared succesfully, false otherwise.
			 */
			bool QueryData(const char* query);

			/**
			 * Executes a query that is not expected to return a data set. (i.e. Insert, Update, Delete)
			 * 
			 *	@param	query	The query string to execute
			 *	@return The number of rows affected, -1 on error.
			 */
			int Query(const char* query);

			/**
			 * Returns the row id of the last row that was inserted.
			 * @return The id of the last inserted row.
			 */
			int GetIdOfLastInsert();

			/**
			 * Advances the current row of the given statement
			 *
			 *	@return	true if a valid row was found and data can be extracted.
			 */
			bool NextRow();

			/**
			 * Extract an integer from the current data row.
			 *
			 *	@param	columnIndex	The index of the column in the table to extract the data from.
			 *	@return The value requested, or -1 on error.
			 */
			int GetInt(int columnIndex=0);

			/**
			 * Extract a long from the current data row.
			 * 
			 * @param  columnIndex The index of the column in the table to extract the data from.
			 * @return             The value requested, or -1 on error.
			 */
			long GetLong(int columnIndex=0);

			/**
			 * Extract a boolean from the current data row.
			 * @param  columnIndex The index of the table column containing the desired data.
			 * @return             The value requested.
			 */
			bool GetBool(int columnIndex=0);

			/**
			 * Extract raw text from the current data row.
			 *
			 *	@param	columnIndex			The index of the data column in the table.
			 *	@return	The string of data requested
			 */
			const unsigned char* GetText(int columnIndex=0);

			/**
			 * Extract raw text from the current data row as a std::string.
			 * @param  columnIndex The index of the data column in the table
			 * @return             A std::string containing the data requested
			 */
			std::string GetString(int columnIndex=0);

			/**
			 * Cleanup following the preparation and execution of a statement.
			 */
			void Done();

			/**
			 * Executes all statements in a .sql file on the current database
			 * 
			 * @param  filename The .sql file to import
			 * @return          True if all queries in filename were succesfully executed, false otherwise.
			 */
			bool ImportFile(const char *filename);

			/**
			 * Determine the internal status of this database.
			 * @return sqlite3 result code. SQLITE_OK (0), or an error code.
			 */	
			int Status()const;

		private:

			/**
			 * Attempts to connect to a sqlite3 database.
			 *
			 *	@param	dbFilename	The database file
			 *	@param	flags		Additional flags for the connection.
			 *	@return	True if the connection succeeded, false otherwise
			 *	
			 *	@see	http://www.sqlite.org/c3ref/open.html
			 */
			bool connect(const char* dbFilename, int flags=SQLITE_OPEN_READWRITE);

			/**
			 * Attempts to close an existing connection to a database.
			 *
			 *	@return	True if a connection did not exist, or the connection existed and 
			 *			was successfully closed.
			 */
			bool close();

		};
	}
}

#endif