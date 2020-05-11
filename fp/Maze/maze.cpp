//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "maze.h"

void fp::maze::update_maze(){
    for (int i=15;i>=0;i--) {
        for (int j=0; j < 16; j++) {
            maze_array[i][j] = (16 * i) + j;
            {
                std::cout << maze_array[i][j];
                if (maze_array[i][j]/100)
                    std::cout<<"  ";
                else if (maze_array[i][j]/10)
                    std::cout<<"   ";
                else
                    std::cout<<"    ";
            }
        }
        std::cout<<'\n';
    }
}

int fp::maze::find_pos(landbasedtracked robot){
    int x = robot.get_x();
    int y = robot.get_y();
    int c = (16*x) + y;
    return c;
}

void fp::maze::move_in_maze(landbasedtracked robot) {
    robot.GoDown(robot.x_, robot.y_);
    std::cout<<"x: "<<find_pos(robot)/16<<", y: "<<find_pos(robot)%16<<", point: "<<find_pos(robot)<<std::endl;
    robot.GoRight(robot.x_,robot.y_);
    std::cout<<"x: "<<find_pos(robot)/16<<", y: "<<find_pos(robot)%16<<", point: "<<find_pos(robot)<<std::endl;
    robot.GoUp(robot.x_,robot.y_);
    std::cout<<"x: "<<find_pos(robot)/16<<", y: "<<find_pos(robot)%16<<", point: "<<find_pos(robot)<<std::endl;
    robot.GoLeft(robot.x_,robot.y_);
    std::cout<<"x: "<<find_pos(robot)/16<<", y: "<<find_pos(robot)%16<<", point: "<<find_pos(robot)<<std::endl;
}

bool fp::maze::check_walls(int x, int y) {
    std::cout<< "check walls called" << std::endl;
    return false;
}
void fp::maze::set_wall(int x, int y) {
    std::cout<< "set walls called" << std::endl;
}