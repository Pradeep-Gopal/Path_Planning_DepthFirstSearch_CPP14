#pragma once

#include <string>

namespace fp
{
    struct Direction { //Struct to store the current direction faced by the robot while traversing the maze
        char NORTH = 'n';
        char EAST = 'e';
        char SOUTH = 's';
        char WEST = 'w';
    };
}