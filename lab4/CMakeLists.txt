cmake_minimum_required(VERSION 3.16)

project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 ${CMAKE_SOURCE_DIR}/lab4/src/main.cpp src/Cuboid.cpp src/Cuboid.h src/Sphere.cpp src/Sphere.h src/FunkcjaKwadratowa.cpp src/FunkcjaKwadratowa.h src/Student.cpp src/Student.h src/Punkt.cpp src/Punkt.h src/Figura.cpp src/Figura.h)