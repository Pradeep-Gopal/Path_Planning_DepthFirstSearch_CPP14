//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "LandBasedWheeled.h"

void rwa3::LandBasedWheeled::GoUp(int x_, int y_) {
    std::cout <<"LandBasedWheeled::GoUp is called\n" <<std::endl;
}

void rwa3::LandBasedWheeled::GoDown(int x_, int y_) {
    std::cout <<"LandBasedWheeled::GoDown is called\n" <<std::endl;
}

void rwa3::LandBasedWheeled::TurnLeft(int x_, int y_) {
    std::cout <<"LandBasedWheeled::TurnLeft is called\n" <<std::endl;
}

void rwa3::LandBasedWheeled::TurnRight(int x_, int y_) {
    std::cout <<"LandBasedWheeled::TurnRight is called\n" <<std::endl;
}

void rwa3::LandBasedWheeled::PickUp(std::string &pick) {
    std::cout <<"LandBasedWheeled::Pickup is called\n" <<std::endl;
}

void rwa3::LandBasedWheeled::Release(std::string &release) {
    std::cout <<"LandBasedWheeled::Release is called\n" <<std::endl;
}

