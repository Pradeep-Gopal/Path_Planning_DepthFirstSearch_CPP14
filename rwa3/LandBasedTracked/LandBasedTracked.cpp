//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "LandBasedTracked.h"

void rwa3::LandBasedTracked::GoUp(int x_, int y_) {
    std::cout <<"LandBasedTracked::GoUp is called\n" <<std::endl;
}

void rwa3::LandBasedTracked::GoDown(int x_, int y_) {
    std::cout <<"LandBasedTracked::GoDown is called\n" <<std::endl;
}

void rwa3::LandBasedTracked::TurnLeft(int x_, int y_) {
    std::cout <<"LandBasedTracked::TurnLeft is called\n" <<std::endl;
}

void rwa3::LandBasedTracked::TurnRight(int x_, int y_) {
    std::cout <<"LandBasedTracked::TurnRight is called\n" <<std::endl;
}

void rwa3::LandBasedTracked::PickUp(std::string &pick) {
    std::cout <<"LandBasedTracked::PickUp is called\n" <<std::endl;
}

void rwa3::LandBasedTracked::Release(std::string &release) {
    std::cout <<"LandBasedRobot::Release is called\n" <<std::endl;
}


