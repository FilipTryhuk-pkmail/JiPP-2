cmake_minimum_required(VERSION 3.16)

project(lab6)
include_directories(include)

add_executable(lab6 src/main.cpp src/Vector.cpp include/Vector.h src/Imaginary.cpp include/Imaginary.h)