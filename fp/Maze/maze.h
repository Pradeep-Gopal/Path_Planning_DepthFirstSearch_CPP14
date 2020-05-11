//
// Created by prachu on 5/9/20.
//

#pragma once


#include <array>
#include "../api/api.h"

namespace fp {
    class maze {

    public:
        // Attributes
        std::array<std::array<int, 16>, 16> maze_array;
        std::array<int, 2> maze_dimension;


        //Method prototypes
        int get_dimension() const;

        bool check_walls(int x, int y);

        void set_wall(int x, int y);

        // Maze creation
     void initialize_maze();
     void erect_walls(int x, int y, char dir);

     //get walls discovers wall for the cell
        bool get_wall_north(int x, int y);
        bool get_wall_south(int x, int y);
        bool get_wall_east(int x, int y);
        bool get_wall_west(int x, int y);

      //set walls sets the wall in the maze
        bool set_wall_north(int x, int y);
        bool set_wall_south(int x, int y);
        bool set_wall_east(int x, int y);
        bool set_wall_west(int x, int y);


    };
}


