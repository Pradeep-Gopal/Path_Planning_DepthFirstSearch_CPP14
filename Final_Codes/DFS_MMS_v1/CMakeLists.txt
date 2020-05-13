cmake_minimum_required(VERSION 3.15)
project(pradeep)

set(CMAKE_CXX_STANDARD 14)

add_executable(pradeep main.cpp LandBasedRobot/landbasedrobot.cpp LandBasedRobot/landbasedrobot.h LandBasedTracked/landbasedtracked.cpp LandBasedTracked/landbasedtracked.h LandBasedWheeled/landbasedwheeled.cpp LandBasedWheeled/landbasedwheeled.h Maze/maze.cpp Maze/maze.h Algorithm/algorithm.cpp Algorithm/algorithm.h API/api.cpp API/api.h Direction/direction.h)
