cmake_minimum_required(VERSION 3.16)

project(FirstClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstClass ${CMAKE_SOURCE_DIR}/FirstClass/src/main.cpp src/FirstClass.cpp src/FirstClass.h)