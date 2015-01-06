cmake_minimum_required(VERSION 2.8.4)
project(D01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex00/main.cpp)
add_executable(D01 ${SOURCE_FILES})