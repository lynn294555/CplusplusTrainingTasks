project(ex01)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "g++") 

SET( CMAKE_BUILD_TYPE debug )
SET( CMAKE_CXX_FLAGS "-O3 -std=c++11" )

SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)#设定二进制文件输出目录

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)#增加子目录。进入源码文件夹继续构建

add_subdirectory(${PROJECT_SOURCE_DIR}/lib)
