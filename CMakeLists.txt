cmake_minimum_required(VERSION 3.2)
project(CornerBlockList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(src SOURCE_FILES)
add_executable(CornerBlockList ${SOURCE_FILES} src/Rectangle.cpp src/Rectangle.h src/CornerBlockList.cpp src/CornerBlockList.h)