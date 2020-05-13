//
// Created by prachu on 5/9/20.
//

#pragma once
#include <array>

namespace fp {
    class maze {

    public:
        //Method prototypes
        std::array<std::array<int, 256>, 256> InitializeMaze(); // Initializes the array with all values sent to 0
        std::array<std::array<int, 256>, 256> SetWall(int x, int y); //Sets a coordinate to true, if there is a wall between two coordinates
        int GetDimension(); //Returns the dimension of the WallArray array
        bool CheckWalls(int x, int y);  //Returns true if there is a wall between two coordinates
        int SetCoordinates(int x, int y); //Sets WallArray index to true if there is a wall between two coordinates in the maze

        // Constructor for the maze class
        maze()
        {
            InitializeMaze(); // Initializes the array with all values sent to 0
        }

        // Attributes
        int coordinate{}; //Variable which stores the coordinate value of the current x and y value
        std::array<std::array<int, 256>, 256> WallArray{}; // Array to store all the Wall information about the maze in MMS

        // Destructor for the maze class
        ~maze(){}

    };
}


