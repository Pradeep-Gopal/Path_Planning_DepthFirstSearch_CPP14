#include <iostream>
#include "landbasedtracked.h"

void rwa3::LandBasedTracked::GoUp(int x, int y) {
    std::cout <<"LandBasedTracked::GoUp is called\n";
}

void rwa3::LandBasedTracked::GoDown(int x, int y) {
    std::cout <<"LandBasedTracked::GoDown is called\n";
}

void rwa3::LandBasedTracked::TurnLeft(int x, int y) {
    std::cout <<"LandBasedTracked::TurnLeft is called\n";
}

void rwa3::LandBasedTracked::TurnRight(int x, int y) {
    std::cout <<"LandBasedTracked::TurnRight is called\n";
}

void rwa3::LandBasedTracked::PickUp(std::string &pick) {
    std::cout <<"LandBasedTracked::PickUp is called\n";
}

void rwa3::LandBasedTracked::Release(std::string &release) {
    std::cout <<"LandBasedTracked::Release is called\n";
}

int rwa3::LandBasedTracked::get_x() const {
    return x_;
}

int rwa3::LandBasedTracked::get_y() const {
    return y_;
}

void rwa3::LandBasedTracked::set_x(int x) {
    x_ = x;
}

void rwa3::LandBasedTracked::set_y(int y) {
    y_ = y;
}

