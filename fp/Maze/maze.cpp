//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "maze.h"

int fp::maze::get_dimension() const {
    std::cout<< "get dimensions called" << std::endl;
    return 0;
}

bool fp::maze::check_walls(int x, int y) {
    std::cout<< "check walls called" << std::endl;
    return false;
}

void fp::maze::set_wall(int x, int y) {
    std::cout<< "set walls called" << std::endl;
}
