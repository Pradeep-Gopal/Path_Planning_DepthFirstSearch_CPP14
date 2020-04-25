cmake_minimum_required(VERSION 3.15)
project(rwa3)

set(CMAKE_CXX_STANDARD 14)

add_executable(rwa3 main.cpp LandBasedWheeled/landbasedwheeled.cpp LandBasedWheeled/landbasedwheeled.h LandBasedTracked/landbasedtracked.cpp LandBasedTracked/landbasedtracked.h LandBasedRobot/landbasedrobot.cpp LandBasedRobot/landbasedrobot.h)