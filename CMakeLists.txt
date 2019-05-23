cmake_minimum_required(VERSION 3.12)
project(Drib)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest-master/googletest)
include_directories(googletest-master/googletest/include)

set(SOURCE_FILES main.cpp ratio.h)
add_executable(Drib ${SOURCE_FILES})
target_link_libraries(Drib gtest gtest_main)