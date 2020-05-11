//
// Created by prachu on 5/9/20.
//

#pragma once
#include <array>
#include "../LandBasedTracked/landbasedtracked.h"
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp {
    class maze {


    public:
        // Attributes
        std::array<std::array<int, 16>, 16> maze_array;

        //Method prototypes
        void update_maze();
        int find_pos(landbasedtracked robot);
        void move_in_maze(landbasedtracked robot);
        bool check_walls(int x, int y);
        void set_wall(int x, int y);
    };
}