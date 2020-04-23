cmake_minimum_required(VERSION 3.15)
project(rwa3)

set(CMAKE_CXX_STANDARD 14)

add_executable(rwa3 main.cpp LandBasedRobot/LandBasedRobot.cpp LandBasedRobot/LandBasedRobot.h LandBasedTracked/LandBasedTracked.cpp LandBasedTracked/LandBasedTracked.h LandBasedWheeled/LandBasedWheeled.cpp LandBasedWheeled/LandBasedWheeled.h)