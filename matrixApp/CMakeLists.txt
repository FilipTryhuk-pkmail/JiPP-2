cmake_minimum_required(VERSION 3.16)

project(matrixApp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/matrixLib)

add_executable(matrixApp ${CMAKE_SOURCE_DIR}/matrixApp/src/main.cpp)

target_link_libraries(matrixApp matrixLib)