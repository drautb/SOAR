cmake_minimum_required(VERSION 2.8)

project(SOAR)

#############################
# Select Build Type
#############################
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib/${CMAKE_BUILD_TYPE})

add_definitions("-Wall")                # Give ALL the warnings!
add_definitions("-Werror")              # Treat ALL The warnings as errors
add_definitions("-pedantic-errors")     # Only allow standard-compliant code
add_definitions("-std=c++11")           # Use the 2011 C++ Standard

#############################
# Select Platform
#############################
# set(CFG_PLATFORM Windows)
# set(CFG_PLATFORM Mac)
set(CFG_PLATFORM Linux)


add_definitions("-DWINDOWS")
add_definitions("-DMACOSX")
add_definitions("-DLINUX")


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

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

target_link_libraries(SOAR 
                      ${SQLITE3_LIBRARY})