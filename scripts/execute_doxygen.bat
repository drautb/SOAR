@ECHO OFF

SET DOXYFILE="../doc/doxygen/doxyfile"
SET LOG_FILE="../doc/doxygen.log.txt"
SET ERROR_FILE="../doc/doxygen.errors.txt"

ECHO. > %LOG_FILE%
ECHO. > %ERROR_FILE%

doxygen %DOXYFILE% >> %LOG_FILE% 2>>%ERROR_FILE%