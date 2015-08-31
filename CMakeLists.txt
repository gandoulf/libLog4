project(libLog4)
cmake_minimum_required(VERSION 2.6)

set(Log4_PATH "/home/resse/work/libLog4")
set(Log4_include "${Log4_PATH}/include")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "./lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "./lib")

include_directories ("${Log4_include}")

SET(CMAKE_EXE_LINKER_FLAGS "-g -fpermissive")
SET(CMAKE_CXX_FLAGS "-g -fpermissive")

SET(SOURCES src/log4.cpp)

add_library (Log4 SHARED ${SOURCES})

target_link_libraries(Log4 -lapr-1 -laprutil-1 -llog4cxx)