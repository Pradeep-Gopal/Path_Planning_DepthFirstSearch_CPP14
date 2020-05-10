#include "LandBasedWheeled/landbasedwheeled.h"
#include "LandBasedTracked/landbasedtracked.h"
#include "LandBasedRobot/landbasedrobot.h"
#include "Algorithm/algorithm.h"
#include <vector>
#include <memory>
#include <iostream>


int main(){
    std::shared_ptr<fp::landbasedrobot> wheeled = std::make_shared<fp::landbasedwheeled>("Husky");
    fp::algorithm algo;
    algo.Clear_Visited_Nodes();
    //algo.Print_Visited_Nodes();
    algo.Solve(wheeled);

//    std::array<int, 2> p = algo.Get_Coordinates(119);
//    std::cout << p[0] <<std::endl;
//    std::cout <<p[1];

    return 0;
}