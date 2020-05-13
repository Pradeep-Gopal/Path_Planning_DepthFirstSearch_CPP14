//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "landbasedrobot.h"

void fp::landbasedrobot::GoUp(int x, int y) {
    std::cout <<"landbasedrobot::GoUp is called\n" <<std::endl;
    y_ = y_ + 1;
}

void fp::landbasedrobot::GoDown(int x, int y) {
    std::cout <<"landbasedrobot::GoDown is called\n" <<std::endl;
    y_ = y_ - 1;
}

void fp::landbasedrobot::GoLeft(int x, int y) {
    std::cout <<"landbasedrobot::TurnLeft is called\n" <<std::endl;
    x_ = x_ - 1;
}

void fp::landbasedrobot::GoRight(int x, int y) {
    std::cout <<"landbasedrobot::TurnRight is called\n" <<std::endl;
    x_ = x_ + 1;
}

void fp::landbasedrobot::PickUp(std::string& pick) {
    std::cout <<"landbasedrobot::Pickup is called\n" <<std::endl;
}

void fp::landbasedrobot::Release(std::string& release) {
    std::cout <<"landbasedrobot::Release is called\n" <<std::endl;
}

//--accessors
int fp::landbasedrobot::get_x() const {
    return x_;
}

int fp::landbasedrobot::get_y() const{
    return y_;
}

char fp::landbasedrobot::get_direction() const{
    return directions_;
}

void fp::landbasedrobot::set_x(int x) {
    x_ = x;
}

void fp::landbasedrobot::set_y(int y) {
    y_ = y;
}
