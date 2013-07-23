cmake_minimum_required(VERSION 2.8)

project(SOAR)

#############################
# Select Build Type
#############################
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

#############################
# Select Platform
#############################
# set(CFG_PLATFORM windows)
# set(CFG_PLATFORM mac)
set(CFG_PLATFORM linux)

#############################
# Set lots of variables
#############################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib/${CFG_PLATFORM}/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS_DEBUG "-DCFG_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-DCFG_RELEASE")

set(SOAR_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/soar/inc)
set(SOAR_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/soar/src)

set(COMMON_DIR common)
set(WINDOWS_DIR windows)
set(MAC_DIR mac)
set(LINUX_DIR linux)

find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)

include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/")
include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/db")
include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/input")
include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/math")
include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/time")
include_directories("${SOAR_PATH_TO_INC}/${COMMON_DIR}/util")

include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}")
include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}/db")
include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}/input")
include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}/math")
include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}/time")
include_directories("${SOAR_PATH_TO_INC}/${CFG_PLATFORM}/util")

set(COMMON_SRCS
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/util/Log.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/math/Rectangle.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/time/Timer.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/math/MD5.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/time/DateTime.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/time/FPSCounter.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/db/Database.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/input/Keyboard.cpp
    ${SOAR_PATH_TO_SRC}/${COMMON_DIR}/input/Mouse.cpp)

set(WINDOWS_SRCS )

set(MAC_SRCS )

set(LINUX_SRCS )

if (CFG_PLATFORM STREQUAL WINDOWS_DIR)
    add_definitions("-DWINDOWS")
    set(ALL_SRCS ${COMMON_SRCS} ${WINDOWS_SRCS})
elseif (CFG_PLATFORM STREQUAL MAC_DIR)
    add_definitions("-DMACOSX")
    set(ALL_SRCS ${COMMON_SRCS} ${MAC_SRCS})
elseif (CFG_PLATFORM STREQUAL LINUX_DIR)
    add_definitions("-DLINUX")
    set(ALL_SRCS ${COMMON_SRCS} ${LINUX_SRCS})
endif()

add_definitions("-Wall")                # Give ALL the warnings!
add_definitions("-Werror")              # Treat ALL The warnings as errors
add_definitions("-pedantic-errors")     # Only allow standard-compliant code
add_definitions("-std=c++11")           # Use the 2011 C++ Standard

add_library(SOAR STATIC ${ALL_SRCS})

target_link_libraries(SOAR 
                      ${SQLITE3_LIBRARY})