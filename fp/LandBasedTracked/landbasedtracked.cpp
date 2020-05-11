//
// Created by prade on 4/22/2020.
//

#include <iostream>
#include "landbasedtracked.h"

void fp::landbasedtracked::GoUp(int &x_, int &y_) {
    std::cout <<"landbasedtracked::GoUp is called\n";
    if (x_!=15)
        x_+=1;
    else
        std::cout<<"Up operation not possible";
}

void fp::landbasedtracked::GoDown(int &x_, int &y_) {
    std::cout <<"landbasedtracked::GoDown is called\n";
    if (x_!=0)
        x_-=1;
    else
        std::cout<<"Down operation not possible";
}

void fp::landbasedtracked::GoLeft(int &x_, int &y_) {
    std::cout <<"landbasedtracked::GoLeft is called\n";
    if (y_!=0)
        y_-=1;
    else
        std::cout<<"Left operation not possible";
}

void fp::landbasedtracked::GoRight(int &x_, int &y_) {
    std::cout <<"landbasedtracked::GoRight is called\n";
    if (y_!=15)
        y_+=1;
    else
        std::cout<<"Right operation not possible";
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