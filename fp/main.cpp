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
    algo.Solve(wheeled);
    return 0;
}