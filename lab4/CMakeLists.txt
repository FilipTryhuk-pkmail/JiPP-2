cmake_minimum_required(VERSION 3.16)

project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 ${CMAKE_SOURCE_DIR}/lab4/src/main.cpp src/Cuboid.cpp src/Cuboid.h src/Sphere.cpp src/Sphere.h)