cmake_minimum_required(VERSION 2.6)

project(log4test)

set(Liblog4_directory "/home/resse/work")

SET(CMAKE_EXE_LINKER_FLAGS "-g -fpermissive")
SET(CMAKE_CXX_FLAGS "-g -fpermissive")

include_directories("${Liblog4_directory}/libLog4/include")
link_directories("${Liblog4_directory}/libLog4/lib")

add_executable(log4Test main.cpp)
target_link_libraries(log4Test -lLog4 -lapr-1 -laprutil-1 -llog4cxx)