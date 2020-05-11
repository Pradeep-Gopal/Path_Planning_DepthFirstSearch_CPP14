//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "landbasedwheeled.h"

void fp::landbasedwheeled::GoUp(int &x_, int &y_) {
    std::cout <<"landbasedwheeled::GoUp is called\n";
}

void fp::landbasedwheeled::GoDown(int &x_, int &y_) {
    std::cout <<"landbasedwheeled::GoDown is called\n";
}

void fp::landbasedwheeled::GoLeft(int &x_, int &y_) {
    std::cout <<"landbasedwheeled::TurnLeft is called\n";
}

void fp::landbasedwheeled::GoRight(int &x_, int &y_) {
    std::cout <<"landbasedwheeled::TurnRight is called\n";
}

void fp::landbasedwheeled::PickUp(std::string &pick) {
    std::cout <<"landbasedwheeled::Pickup is called\n";
}

void fp::landbasedwheeled::Release(std::string &release) {
    std::cout <<"landbasedwheeled::Release is called\n";
}

int fp::landbasedwheeled::get_x() const {
    return x_;
}

int fp::landbasedwheeled::get_y() const {
    return y_;
}

char fp::landbasedwheeled::get_direction() const{
    return directions_;
}

void fp::landbasedwheeled::set_x(int x) {
    x_ = x;
}

void fp::landbasedwheeled::set_y(int y) {
    y_ = y;
}

