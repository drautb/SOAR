#!/bin/bash

echo "Removing CMake Generated Files..."

cd ../build/

rm -rf CMakeCache.txt
rm -rf CMakeFiles/
rm -rf Makefile
rm -rf cmake_install.cmake

cmake .

echo "Finished."

