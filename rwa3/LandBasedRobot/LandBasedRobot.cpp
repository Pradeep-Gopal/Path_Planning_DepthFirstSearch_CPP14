//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "LandBasedRobot.h"

void rwa3::LandBasedRobot::GoUp(int x_, int y_) {
    std::cout <<"LandBasedRobot::GoUp is called\n" <<std::endl;
}

void rwa3::LandBasedRobot::GoDown(int x_, int y_) {
    std::cout <<"LandBasedRobot::GoDown is called\n" <<std::endl;
}

void rwa3::LandBasedRobot::TurnLeft(int x_, int y_) {
    std::cout <<"LandBasedRobot::TurnLeft is called\n" <<std::endl;
}

void rwa3::LandBasedRobot::TurnRight(int x_, int y_) {
    std::cout <<"LandBasedRobot::TurnRight is called\n" <<std::endl;
}

void rwa3::LandBasedRobot::PickUp(std::string& pick) {
    std::cout <<"LandBasedRobot::Pickup is called\n" <<std::endl;
}

void rwa3::LandBasedRobot::Release(std::string& release) {
    std::cout <<"LandBasedRobot::Release is called\n" <<std::endl;
}

//--accessors
int rwa3::LandBasedRobot::get_x() const {
        return x_;
}

int rwa3::LandBasedRobot::get_y() const{
    return y_;
}

void rwa3::LandBasedRobot::set_x(int x) {
    x_ = x;
}

void rwa3::LandBasedRobot::set_y(int y) {
    y_ = y;
}
