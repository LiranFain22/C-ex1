cmake_minimum_required(VERSION 3.17)
project(Exercise1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exercise1 main.c PictureManipulation.c PictureManipulation.h NumberGame.c NumberGame.h main.h)