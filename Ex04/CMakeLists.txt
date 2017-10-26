project(Ex04)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "g++") 

SET( CMAKE_BUILD_TYPE debug )
SET( CMAKE_CXX_FLAGS "-O3 -std=c++11" )
add_executable(test test.cpp Polynomial.cpp)
