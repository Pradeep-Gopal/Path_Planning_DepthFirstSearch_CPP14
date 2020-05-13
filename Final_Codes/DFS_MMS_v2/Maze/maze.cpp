//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "maze.h"

int fp::maze::GetDimension() {
    std::cout<< "get dimensions called" << std::endl;
    int rows =  sizeof WallArray / sizeof WallArray[0];
    int cols = sizeof WallArray[0] / sizeof(int);
    return SetCoordinates(rows, cols);
}

int fp::maze::SetCoordinates(int x, int y) {
    coordinate = (x) + 256*y; // Transforming x and y value to a single coordinate
    return coordinate;
}

bool fp::maze::CheckWalls(int x, int y) {
    std::cout<< "check walls called" << std::endl;
    return WallArray[x][y] == 1; // Returns true if there is a wall between two indices in the maze
}

std::array<std::array<int, 256>, 256> fp::maze::SetWall(int x, int y) {
    std::cout << "SetWall called";
    WallArray[x][y] = 1; // Sets the index to one
    WallArray[y][x] = 1; // Sets the index to one
    return WallArray;
}

std::array<std::array<int, 256>, 256> fp::maze::InitializeMaze() {
    std::cout << "Initialised wall array with all zeroes" <<std::endl;
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            WallArray[i][j] = 0; // Initialising th array indices with zero
        }
    }
    return WallArray;
}


