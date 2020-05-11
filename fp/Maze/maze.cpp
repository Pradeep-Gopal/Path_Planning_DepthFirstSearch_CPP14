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


std::array<std::array<int, 256>, 256> fp::maze::SetWall(int x, int y) {
    std::cout << "SetWall called";
    WallArray[x][y] = 1;
    return WallArray;
}

std::array<std::array<int, 256>, 256> fp::maze::InitializeMaze() {
    std::cout << "Initialised wall array with all zeroes" <<std::endl;
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            WallArray[i][j] = 0;
        }
    }

    return WallArray;
}


