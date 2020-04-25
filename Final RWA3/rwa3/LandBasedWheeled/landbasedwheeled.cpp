#include <iostream>
#include "landbasedwheeled.h"

void rwa3::LandBasedWheeled::GoUp(int x, int y) {
    std::cout <<"LandBasedWheeled::GoUp is called\n";
}

void rwa3::LandBasedWheeled::GoDown(int x, int y) {
    std::cout <<"LandBasedWheeled::GoDown is called\n";
}

void rwa3::LandBasedWheeled::TurnLeft(int x, int y) {
    std::cout <<"LandBasedWheeled::TurnLeft is called\n";
}

void rwa3::LandBasedWheeled::TurnRight(int x, int y) {
    std::cout <<"LandBasedWheeled::TurnRight is called\n";
}

void rwa3::LandBasedWheeled::PickUp(std::string &pick) {
    std::cout <<"LandBasedWheeled::Pickup is called\n";
}

void rwa3::LandBasedWheeled::Release(std::string &release) {
    std::cout <<"LandBasedWheeled::Release is called\n";
}

int rwa3::LandBasedWheeled::get_x() const {
    return x_;
}

int rwa3::LandBasedWheeled::get_y() const {
    return y_;
}

void rwa3::LandBasedWheeled::set_x(int x) {
    x_ = x;
}

void rwa3::LandBasedWheeled::set_y(int y) {
    y_ = y;
}

