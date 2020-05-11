#pragma once


#include <array>

namespace fp {
    class maze {


    public:
        // Attributes
        std::array<std::array<int, 16>, 16> maze_array;

        //Method prototypes
        int get_dimension() const;

        bool check_walls(int x, int y);

        void set_wall(int x, int y);

//        int height_;
//        int width_;
//maze(int height=16, int width=16)
    };
}