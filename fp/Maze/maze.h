//
// Created by prachu on 5/9/20.
//

#pragma once


#include <array>

namespace fp {
    class maze {

    public:
        // Attributes
        std::array<std::array<int, 256>, 256> WallArray;

        //Method prototypes
        std::array<std::array<int, 256>, 256> InitializeMaze();

        std::array<std::array<int, 256>, 256> SetWall(int x, int y);

        int get_dimension() const;

        bool check_walls(int x, int y);

    };
}


