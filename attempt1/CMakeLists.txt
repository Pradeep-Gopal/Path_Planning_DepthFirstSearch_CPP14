cmake_minimum_required(VERSION 3.15)
project(attempt1)

set(CMAKE_CXX_STANDARD 14)

add_executable(attempt1 main.cpp Algorithm/algorithm.cpp Algorithm/algorithm.h API/api.cpp API/api.h Direction/direction.h Maze/maze.cpp Maze/maze.h)