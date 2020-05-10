//
// Created by prachu on 5/9/20.
//

#pragma once
#include <array>
#include <stack>          // std::stack
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"


namespace fp {
    class algorithm{
    public:
        //Attributes
        int Start;
        int Start_x;
        int Start_y;

        std::array<std::array<int, 16>, 16> VisitedNodes;
        std::stack<int> Stack;

        algorithm()
        {
            Start_x = 0; Start_y = 3; Start = 48;
            Stack.push(Start);
        }


//Methods

        void Clear_Visited_Nodes();
        void Print_Visited_Nodes();
        void Solve(std::shared_ptr<fp::landbasedrobot> robot);
        std::array<int, 2> Get_Coordinates(int coordinates);
        static bool CheckGoal(int x, int y);
        int Set_Coordinates(int x, int y);

    };
}


