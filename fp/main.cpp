#include "LandBasedWheeled/landbasedwheeled.h"
#include "LandBasedTracked/landbasedtracked.h"
#include "LandBasedRobot/landbasedrobot.h"
#include "Maze/maze.h"
#include "Algorithm/algorithm.h"
#include <vector>
#include <memory>
#include <iostream>


int main(){
//    std::shared_ptr<fp::landbasedrobot> tracked = std::make_shared<fp::landbasedtracked>("LT2-F",6,0);
    fp::landbasedtracked tracked("LT2-F",6,10);
    fp::maze maze1;
    maze1.update_maze();
    maze1.move_in_maze(tracked);
    fp::algorithm algo;
//    algo.Solve(wheeled);
    return 0;
}