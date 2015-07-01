cmake_minimum_required(VERSION 3.2)
project(CornerBlockList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

find_package(Boost REQUIRED)
find_package(OpenCV REQUIRED)
set(OpenCV_INCLUDE_DIRS "${OpenCV_CONFIG_PATH}/include" "${OpenCV_CONFIG_PATH}/include/opencv")
include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(src SOURCE_FILES)
aux_source_directory(test TEST_FILES)
add_executable(CornerBlockList ${SOURCE_FILES})
target_link_libraries(CornerBlockList ${OpenCV_LIBS})