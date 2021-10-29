cmake_minimum_required(VERSION 3.16)

project(firstLib)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/firstLib/include)

add_executable(firstLibCall ${CMAKE_SOURCE_DIR}/firstLibCall/src/main.cpp)

target_link_libraries(firstLibCall firstLib)