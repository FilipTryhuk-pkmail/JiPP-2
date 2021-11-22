cmake_minimum_required(VERSION 3.16)

project(lab7)
include_directories(include)

add_executable(lab7 src/main.cpp src/Scheduler.cpp include/Scheduler.h src/Task.cpp include/Task.h)