//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "algorithm.h"
#include "../Maze/maze.h"

void fp::algorithm::Clear_Visited_Nodes()
{
    std::cout << "Initializing Visited_Nodes with zero" <<std::endl;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            VisitedNodes[i][j] = 0;
        }
    }
}

void fp::algorithm::Print_Visited_Nodes()
{
    std::cout << "Printing Visited_Nodes array" <<std::endl;
    for (int i = 15; i >= 0; i--)
    {
        for (int j = 0; j < 16; j++)
        {
            std::cout << VisitedNodes[j][i];
            std::cout << " ";
        }
        std::cout<<"\n";
    }
}

void PrintStack(std::stack <int> s)
{
//    std::cout << "Print stack called" <<std::endl;
    // If stack is empty then return
    if (s.empty())
        return;

    int x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    std::cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

void fp::algorithm::Solve(std::shared_ptr<fp::landbasedrobot> robot)
{
    std::cout << "Solve function called" << std::endl;
    int x{robot->get_x()};
    int y{robot->get_y()};
    std::cout << "current robot location" <<std::endl;
    std::cout << x;
    std::cout << ",";
    std::cout << y <<std::endl;
    Print_Visited_Nodes();

    fp::maze maze;
    maze.InitializeMaze();
    const std::array<std::array<int, 256>, 256> &WallArray = maze.SetWall(15,31);

        // Move Down
        while(!CheckGoal(x,y)) {
            std::cout << " " ;
            std::cout << "\n";
            x = robot->get_x();
            y = robot->get_y();

            // Going Down
            if ( y-1 >= 0 && (!VisitedNodes[x][y-1]) && (!WallArray[x][y-1])){
                std::cout << "Going down" <<std::endl;
                robot->GoDown(x, y);
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "Current robot location" << std::endl;
                std::cout << x;
                std::cout <<",";
                std::cout << y << std::endl;
                VisitedNodes[x][y+1] = 1;
                Print_Visited_Nodes();
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "pushed coordinates in stack = ";
                std::cout <<x;
                std::cout << ",";
                std::cout <<y <<std::endl;
                std::cout << "Final value pushed in stack = ";
                std::cout << Set_Coordinates(x,y) << std::endl;
                Stack.push(Set_Coordinates(x,y));
                std::cout << "Printing Stack" <<std::endl;
                PrintStack(Stack);
                std::cout << "\n";
            }

            // Going Right

            else if ((x+1 >= 0) && (x+1 < 16) && (!VisitedNodes[x+1][y]) && (!WallArray[x+1][y])){
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "cannot go down, went right" << std::endl;
                robot->GoRight(x, y);
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "Current robot location" << std::endl;
                std::cout << x;
                std::cout <<",";
                std::cout <<y  <<std::endl;
                VisitedNodes[x-1][y] = 1;
                Print_Visited_Nodes();
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "pushed coordinates in stack = ";
                std::cout <<x;
                std::cout << ",";
                std::cout <<y <<std::endl;
                std::cout << "Final value pushed in stack = ";
                std::cout << Set_Coordinates(x,y) << std::endl;
                Stack.push(Set_Coordinates(x,y));
                std::cout << "Printing Stack" <<std::endl;
                PrintStack(Stack);
                std::cout << "\n";
            }

            // Going up

            else if ( y+1 < 16 && (!VisitedNodes[x][y+1]) && (!WallArray[Set_Coordinates(x,y)][Set_Coordinates(x,y+1)]) )
            {
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "cannot go down, right, went up" << std::endl;
                robot->GoUp(x, y);
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "Current robot location" << std::endl;
                std::cout << x;
                std::cout <<",";
                std::cout <<y  <<std::endl;
                VisitedNodes[x][y-1] = 1;
                Print_Visited_Nodes();
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "pushed coordinates in stack = ";
                std::cout <<x;
                std::cout << ",";
                std::cout <<y <<std::endl;
                std::cout << "Final value pushed in stack = ";
                std::cout << Set_Coordinates(x,y) << std::endl;
                Stack.push(Set_Coordinates(x,y));
                std::cout << "Printing Stack" <<std::endl;
                PrintStack(Stack);
                std::cout << "\n";
            }

            // Going Left
            else if ((x-1 >= 0) && (!VisitedNodes[x-1][y]) && (!WallArray[x-1][y])){
                std::cout << "Moving Left" << std::endl;
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "cannot go down, left, up, right, went left" << std::endl;
                robot->GoLeft(x, y);
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "Current robot location" << std::endl;
                std::cout << x;
                std::cout <<",";
                std::cout <<y  <<std::endl;
                VisitedNodes[x+1][y] = 1;
                Print_Visited_Nodes();
                x = robot->get_x();
                y = robot->get_y();
                std::cout << "pushed coordinates in stack = ";
                std::cout <<x;
                std::cout << ",";
                std::cout <<y <<std::endl;
                std::cout << "Final value pushed in stack = ";
                std::cout << Set_Coordinates(x,y) << std::endl;
                Stack.push(Set_Coordinates(x,y));
                std::cout << "Printing Stack" <<std::endl;
                PrintStack(Stack);
                std::cout << "\n";
            }

            else{
                std::cout << "Popping off from stack" <<std::endl;
                int NewCoordinate = Stack.top();
                std::array<int, 2> point = Get_Coordinates(NewCoordinate);
                VisitedNodes[point[0]][point[1]] = 1;
                Stack.pop();
                NewCoordinate = Stack.top();
                std::cout << "New Robot Location after popping" << std::endl;
                point = Get_Coordinates(NewCoordinate);
                std::cout << "x = " <<point[0] <<std::endl;
                std::cout << "y = " << point[1] <<std::endl;
                robot->set_x(point[0]);
                robot->set_y(point[1]);
                std::cout << "\n";
            }
        }

    PrintStack(Stack);
    std::cout << "\n" ;
    while(CheckGoal(x,y)){
        x = robot->get_x();
        y = robot->get_y();
        std::cout << "current robot coordinate at goal "<<x <<"," <<y <<std::endl;
        std::cout << "Goal Reached" <<std::endl;
        Print_Visited_Nodes();
        break;
    }


}

std::array<int, 2> fp::algorithm::Get_Coordinates(int coordinates) {
    std::array <int,2> coordinate;
    coordinate[1] = coordinates/16;
    coordinate[0] = coordinates%16;
    return coordinate;
}

bool fp::algorithm::CheckGoal(int x, int y)
{
    if((x == 7 && y == 7) || (x == 8 && y == 8) || (x == 7 && y == 8) || (x == 8 && y == 7))
        return true;
    return false;
}

int fp::algorithm::Set_Coordinates(int x, int y) {
    int coordinate = (x) + 16*y;
    return coordinate;
}







