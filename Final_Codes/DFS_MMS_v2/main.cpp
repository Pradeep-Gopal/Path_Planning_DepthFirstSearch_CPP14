#include "LandBasedWheeled/landbasedwheeled.h"
#include "LandBasedTracked/landbasedtracked.h"
#include "LandBasedRobot/landbasedrobot.h"
#include "Algorithm/algorithm.h"
#include <memory>



int main(){
    std::shared_ptr<fp::landbasedrobot> wheeled = std::make_shared<fp::landbasedtracked>("Husky");
    fp::algorithm algo;
    algo.ClearVisitedArray();
    algo.ClearStack(algo.Solution);
    algo.SetUp();
    algo.Solve(wheeled);
    return 0;
}