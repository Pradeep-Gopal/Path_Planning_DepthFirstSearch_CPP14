//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "landbasedtracked.h"

void fp::landbasedtracked::GoUp(int x, int y) {
    std::cout <<"landbasedtracked::GoUp is called\n";
}

void fp::landbasedtracked::GoDown(int x, int y) {
    std::cout <<"landbasedtracked::GoDown is called\n";
}

void fp::landbasedtracked::GoLeft(int x, int y) {
    std::cout <<"landbasedtracked::TurnLeft is called\n";
}

void fp::landbasedtracked::GoRight(int x, int y) {
    std::cout <<"landbasedtracked::TurnRight is called\n";
}

void fp::landbasedtracked::PickUp(std::string &pick) {
    std::cout <<"landbasedtracked::PickUp is called\n";
}

void fp::landbasedtracked::Release(std::string &release) {
    std::cout <<"landbasedtracked::Release is called\n";
}

int fp::landbasedtracked::get_x() const {
    return x_;
}

int fp::landbasedtracked::get_y() const {
    return y_;
}

char fp::landbasedtracked::get_direction() const{
    return directions_;
}

void fp::landbasedtracked::set_x(int x) {
    x_ = x;
}

void fp::landbasedtracked::set_y(int y) {
    y_ = y;
}


