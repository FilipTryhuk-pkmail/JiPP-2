cmake_minimum_required(VERSION 3.16)

project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 ${CMAKE_SOURCE_DIR}/lab2/src/main.cpp)

#add_subdirectory(include)
#target_link_libraries(lab2 lib2)
#target_include_directories(lab2 PUBLIC ${CMAKE_SOURCE_DIR}/lab2/include)