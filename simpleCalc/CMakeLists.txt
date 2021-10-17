cmake_minimum_required(VERSION 3.16)

project(simpleCalc)

set(CMAKE_CXX_STANDARD 20)

add_executable(simpleCalc ./src/main.cpp)

add_subdirectory(include)
target_link_libraries(simpleCalc include)
target_include_directories(simpleCalc PUBLIC ./include)