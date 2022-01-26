cmake_minimum_required(VERSION 3.16)

project(lab10)
include_directories(include)

add_executable(lab10 src/main.cpp include/CsvException.h src/CsvException.cpp)