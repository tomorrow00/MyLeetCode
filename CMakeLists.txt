cmake_minimum_required(VERSION 3.12)
project(LeetCode_xcodeproj)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(Easy)
add_subdirectory(Medium)
add_subdirectory(Hard)
add_subdirectory(LeetCode)