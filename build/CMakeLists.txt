cmake_minimum_required(VERSION 2.8)

project(SOAR)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib)

add_definitions("-Wall")
add_definitions("-std=c++0x")

find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)

include_directories("${CMAKE_SOURCE_DIR}/../inc")

add_library(SOAR STATIC
	${CMAKE_SOURCE_DIR}/../src/Log.cpp
	${CMAKE_SOURCE_DIR}/../src/Rectangle.cpp
	${CMAKE_SOURCE_DIR}/../src/Timer.cpp
	${CMAKE_SOURCE_DIR}/../src/MD5.cpp
	${CMAKE_SOURCE_DIR}/../src/DateTime.cpp
	${CMAKE_SOURCE_DIR}/../src/FPSCounter.cpp
	${CMAKE_SOURCE_DIR}/../src/Database.cpp
)

target_link_libraries(SOAR ${SQLITE3_LIBRARY})
