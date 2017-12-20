cmake_minimum_required(VERSION 3.3)
project(PinaHW3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PinaHW3 ${SOURCE_FILES})