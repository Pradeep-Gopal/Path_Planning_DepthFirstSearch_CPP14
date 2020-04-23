//
// Created by prade on 4/22/2020.
//

#include "LandBasedRobot.h"

void rwa3::LandBasedRobot::GoUp(int x_, int y_) {
    std::cout <<"LandBasedRobot::GoUp function called\n" <<std::endl;
    std::cout <<x_, y_ <<std::endl
}

void rwa3::LandBasedRobot::GoDown(int x_, int y_) {
    std::cout <<"LandBasedRobot::GoDown function called\n" <<std::endl;
    std::cout <<x_, y_ <<std::endl
}

void rwa3::LandBasedRobot::TurnLeft(int x_, int y_) {
    std::cout <<"LandBasedRobot::TurnLeft function called\n" <<std::endl;
    std::cout <<x_, y_ <<std::endl
}

void rwa3::LandBasedRobot::TurnRight(int x_, int y_) {
    std::cout <<"LandBasedRobot::TurnRight function called\n" <<std::endl;
    std::cout <<x_, y_ <<std::endl
}

void rwa3::LandBasedRobot::PickUp(std::string& pick) {
    std::cout <<"LandBasedRobot::Pickup function called\n" <<std::endl;
    std::cout << pick <<std::endl
}

void rwa3::LandBasedRobot::Release(std::string& release) {
    std::cout <<"LandBasedRobot::Release function called\n" <<std::endl;
    std::cout << release <<std::endl
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
