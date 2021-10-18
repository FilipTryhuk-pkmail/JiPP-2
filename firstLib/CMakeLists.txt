cmake_minimum_required(VERSION 3.16)

project(firstLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(firstLib ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_subdirectory(include)
target_link_libraries(firstLib include)
target_include_directories(firstLib PUBLIC ${CMAKE_SOURCE_DIR}/include)