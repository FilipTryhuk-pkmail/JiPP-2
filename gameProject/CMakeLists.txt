cmake_minimum_required(VERSION 3.16)

project(gameProject)
include_directories(include)

add_executable(gameProject src/main.cpp include/Card.h src/Card.cpp include/MeleeCard.h src/MeleeCard.cpp include/RangedCard.h src/RangedCard.cpp include/MagicCard.h src/MagicCard.cpp)