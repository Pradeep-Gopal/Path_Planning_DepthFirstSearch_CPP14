//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "maze.h"

int fp::maze::get_dimension() const {
    std::cout<< "get dimensions called" << std::endl;
    return 0;
}
/*not required
bool fp::maze::check_walls(int x, int y) {
    std::cout<< "check walls called" << std::endl;
    return false;
}

void fp::maze::set_wall(int x, int y) {
    std::cout<< "set walls called" << std::endl;
}
 not required*/

/* implement these methods to interact with maze_array
//get walls find walls in the maze
bool get_wall_north(int x, int y){};
bool get_wall_south(int x, int y){};
bool get_wall_east(int x, int y){};
bool get_wall_west(int x, int y){};

//set walls sets the wall in the maze
bool set_wall_north(int x, int y){};
bool set_wall_south(int x, int y){};
bool set_wall_east(int x, int y){};
bool set_wall_west(int x, int y){};
*/

void fp::maze::initialize_maze() {
      maze_array={};
    for (int x=0; x<16; x++){
        for (int y=0; y<16; y++){
            if (x==0) {
                set_wall_west(x, y);
                fp::api::setWall(x, y, 'W');
            }

            if (y == 0) {
                set_wall_south(x, y);
                fp::api::setWall(x, y, 's');
            }
            if (x == 15) {
                set_wall_east(x, y);
                fp::api::setWall(x, y, 'e');
            }
            if (y == 15) {
                set_wall_north(x, y);
                fp::api::setWall(x, y, 'n');

            }
        }
    }
}

void fp::maze::erect_walls(int x, int y, char dir) {
    //set wall for robot facing north
    if(dir == 'N'){
        if (fp::api::wallFront()){
            fp::api::setWall(x, y, 'N');
            set_wall_north(x, y);
        }
        if (fp::api::wallRight()){
            fp::api::setWall(x, y, 'E');
            set_wall_east(x, y);
        }
        if (fp::api::wallLeft()){
            fp::api::setWall(x, y, 'W');
            set_wall_west(x, y);
        }

    }
    //set wall fo robot facing east
    if(dir == 'E'){ if (fp::api::wallFront()){
            fp::api::setWall(x, y, 'E');
            set_wall_east(x, y);
        }
        if (fp::api::wallRight()){
            fp::api::setWall(x, y, 'S');
            set_wall_south(x, y);
        }
        if (fp::api::wallLeft()){
            fp::api::setWall(x, y, 'N');
            set_wall_north(x, y);
        }

    }
    //set wall for robot facing south
    if(dir == 'S'){ if (fp::api::wallFront()){
            fp::api::setWall(x, y, 'S');
            set_wall_east(x, y);
        }
        if (fp::api::wallRight()){
            fp::api::setWall(x, y, 'W');
            set_wall_west(x, y);
        }
        if (fp::api::wallLeft()){
            fp::api::setWall(x, y, 'E');
            set_wall_east(x, y);
        }

    }

    //set wall for robot facing west
    if(dir == 'W'){ if (fp::api::wallFront()){
            fp::api::setWall(x, y, 'W');
            set_wall_west(x, y);
        }
        if (fp::api::wallRight()){
            fp::api::setWall(x, y, 'N');
            set_wall_north(x, y);
        }
        if (fp::api::wallLeft()){
            fp::api::setWall(x, y, 'S');
            set_wall_south(x, y);
        }

    }
}


