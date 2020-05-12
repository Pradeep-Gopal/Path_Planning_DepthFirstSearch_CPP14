//
// Created by prachu on 5/9/20.
//

#pragma once
#include <array>
#include <stack>          // std::stack
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"
#include "../Maze/maze.h"


namespace fp {
    class algorithm : public maze {
    public:
        //Attributes
        int Start;
        int Start_x;
        int Start_y;
        int width;
        int height;
        char dir;
        char direc;
        int m;
        int n;
        std::array<std::array<int, 256>, 256> WallArray;
        std::array<std::array<int, 16>, 16> VisitedNodes;
        std::stack<int> Stack;

        algorithm(){
            dir = 'n';
//            fp::maze maze;
            WallArray =  InitializeMaze();
        }

        //Methods
        void Clear_Visited_Nodes();
        void Print_Visited_Nodes();
        void Solve(std::shared_ptr<fp::landbasedrobot> robot);
        std::array<int, 2> Get_Coordinates(int coordinates);
        static bool CheckGoal(int x, int y);
        int Set_Coordinates(int x, int y);
        void log(const std::string& text);
        void displayNumber(int num);
        void SetUp();
        void PrintStack(std::stack <int> s);
        std::stack<int> ClearStack(std::stack <int> stack);
        void MoveRobot(std::stack<int> path, std::shared_ptr<fp::landbasedrobot> ptr);
        std::stack<int> ReverseStack(std::stack <int> stack);

    };
}


