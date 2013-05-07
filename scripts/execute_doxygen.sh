#!/bin/sh

readonly ROOT_DIR="C:\Dev\SOAR"

readonly DOXYFILE="$ROOT_DIR\doc\doxygen\doxyfile"
readonly LOG_FILE="$ROOT_DIR\doc\doxygen.log.txt"
readonly ERROR_FILE="$ROOT_DIR\doc\doxygen.errors.txt"

:>$LOG_FILE
:>$ERROR_FILE

doxygen $DOXYFILE > $LOG_FILE 2>$ERROR_FILE