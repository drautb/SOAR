#!/bin/sh

readonly DOC_DIR="C:\Dev\SOAR\doc"

readonly DOXYFILE="$DOC_DIR\doxygen\doxyfile"
readonly LOG_FILE="$DOC_DIR\doxygen.log.txt"
readonly ERROR_FILE="$DOC_DIR\doxygen.errors.txt"

rm -rf $DOC_DIR/doxygen/html

:>$LOG_FILE
:>$ERROR_FILE

doxygen $DOXYFILE > $LOG_FILE 2>$ERROR_FILE