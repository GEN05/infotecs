cmake_minimum_required(VERSION 3.15)
project(infotecs)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(infotecs main.cpp)

target_link_libraries(infotecs gtest gtest_main)