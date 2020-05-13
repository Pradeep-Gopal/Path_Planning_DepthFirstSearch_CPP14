//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "algorithm.h"
#include "../Maze/maze.h"
#include "../API/api.h"
#include "../Direction/direction.h"
fp::Direction dirc;
//char dir = dirc.NORTH;

void fp::algorithm::log(const std::string& text)
{
    std::cerr << "\n" << text;
}

void fp::algorithm::Boollog(const bool& text)
{
    std::cerr << "\n" << text;
}

void fp::algorithm::displayNumber(const int num)
{
    std::cerr << num << std::endl;
}

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
void fp::algorithm::Clear_Visited_Array()
{
    std::cout << "Initializing Visited_Array with zero" <<std::endl;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            VisitedArray[i][j] = 0;
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



void fp::algorithm::Solve(std::shared_ptr<fp::landbasedrobot> robot)
{
    std::cout << "Solve function called" << std::endl;
    std::cerr <<"\n";
    std::cerr << "Solve function called" <<std::endl;
    Clear_Visited_Nodes();
    Stack = ClearStack(Stack);
    int x{robot->get_x()};
    int y{robot->get_y()};
    int Start = Set_Coordinates(x,y);
    Stack.push(Start);
    std::cout << "current robot location" <<std::endl;
    std::cout << x;
    std::cout << ",";
    std::cout << y <<std::endl;
    std::cerr << "current robot location" <<std::endl;
    std::cerr << x;
    std::cerr << ",";
    std::cerr << y <<std::endl;

    Print_Visited_Nodes();

    while(!CheckGoal(x,y))
    {
        std::cout << " " ;
        std::cout << "\n";
        x = robot->get_x();
        y = robot->get_y();
//        std::cerr << "New robot x and y " << x << "," << y <<std::endl;

        // Going Down
        if ( y-1 >= 0 && (!VisitedNodes[x][y-1]) && (!WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y - 1)]) && (!VisitedArray[x][y-1])){
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
            std::cout << "pushed coordinates in stack = ";
            std::cout <<x;
            std::cout << ",";
            std::cout <<y <<std::endl;
            std::cout << "Final value pushed in stack = ";
            std::cout << Set_Coordinates(x,y) << std::endl;
            Stack.push(Set_Coordinates(x,y));
            std::cerr << "Printing Stack Solve Down" <<std::endl;
            PrintStack(Stack);
            std::cout << "\n";
        }

        // Going Right
        else if ((x+1 >= 0) && (x+1 < 16) && (!VisitedNodes[x+1][y]) && (!VisitedArray[x+1][y]) && (!WallArray[Set_Coordinates(x, y)][Set_Coordinates(x + 1, y)])){
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
            std::cerr << "Printing Stack Solve Right" <<std::endl;
            PrintStack(Stack);
            std::cout << "\n";
        }

        // Going up
        else if ( y+1 < 16 && (!VisitedNodes[x][y+1]) && (!VisitedArray[x][y+1]) &&(!WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y + 1)]))
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
            std::cerr << "Printing Stack Solve Up" <<std::endl;
            PrintStack(Stack);
            std::cout << "\n";
        }

        // Going Left
        else if ((x-1 >= 0) && (!VisitedNodes[x-1][y]) && (!VisitedArray[x-1][y]) && (!WallArray[Set_Coordinates(x, y)][Set_Coordinates(x - 1, y)])){
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
            std::cerr << "Printing Stack Solve Left" <<std::endl;
            PrintStack(Stack);
            std::cout << "\n";
        }

        else{
            if(Stack.size() == 1){
                int x = Solution.top();
                std::cerr << "New Robot Location now after popping" << std::endl;
                std::array <int,2> point;
                point = Get_Coordinates(x);
                std::cerr << "x = " << point[0] << std::endl;
                std::cerr << "y = " << point[1] << std::endl;
                robot->set_x(point[0]);
                robot->set_y(point[1]);
                temp.push(x);
                Solution.pop();
            }
            else{
                int NewCoordinate = Stack.top();
                std::array <int,2> point;
                point = Get_Coordinates(NewCoordinate);

                VisitedNodes[point[0]][point[1]] = 1;
                Stack.pop();
                NewCoordinate = Stack.top();
                std::cerr << "New Robot Location then after popping" << std::endl;
                point = Get_Coordinates(NewCoordinate);
                std::cerr << "x = " << point[0] << std::endl;
                std::cerr << "y = " << point[1] << std::endl;
                robot->set_x(point[0]);
                robot->set_y(point[1]);
                std::cout << "\n";
            }
    }

//        else{
//            std::cerr << "inside else daww" <<std::endl;
//            if (!Stack.empty()){
//                std::cout << "Popping off from stack" <<std::endl;
//                std::cerr << "Popping off from stack" <<std::endl;
//                int NewCoordinate = Stack.top();
//                std::array<int, 2> point = Get_Coordinates(NewCoordinate);
//                VisitedNodes[point[0]][point[1]] = 1;
//                std::cerr << "popped off point = " << point[0] <<"," << point[1] <<std::endl;
//                if (Stack.size() == 1)
//                {
//                    if (Start == NewCoordinate)
//                    {
//                        Solution.pop();
//                        Stack.push(Solution.top());
//                        int NewCoordinate1 = Stack.top();
//                        std::array<int, 2> point1 = Get_Coordinates(NewCoordinate1);
//                        VisitedNodes[point1[0]][point1[1]] = 1;
//                        std::cerr << "popped off point1 = " << point1[0] <<"," << point1[1] <<std::endl;
//                        robot->set_x(point1[0]);
//                        robot->set_y(point1[1]);
//                    }
//                }
//                else {
//                    Stack.pop();
//                    NewCoordinate = Stack.top();
//                    std::cerr << "New Robot Location after popping" << std::endl;
//                    point = Get_Coordinates(NewCoordinate);
//                    std::cerr << "x = " << point[0] << std::endl;
//                    std::cerr << "y = " << point[1] << std::endl;
//                    robot->set_x(point[0]);
//                    robot->set_y(point[1]);
//                    std::cout << "\n";
//                }
//            }
//        }






    }
    std::cerr << "Upgraded dawwww " <<std::endl;
    PrintStack(Stack);
    std::cerr << "Printin temp"<<std::endl;
    PrintStack(temp);

    if(temp.size()> 0 ){
        Stack = ReverseStack(Stack);
        Stack.pop();
        while(!temp.empty()){
            Stack.push(temp.top());
            temp.pop();
        }
        Stack = ReverseStack(Stack);
    }

    std::cerr << "Upgraded 2.0" <<std::endl;
    PrintStack(Stack);

    std::cout << "\n" ;
    while(CheckGoal(x,y)){
        x = robot->get_x();
        y = robot->get_y();
        std::cout << "current robot coordinate at goal "<<x <<"," <<y <<std::endl;
        std::cout << "Goal Reached" <<std::endl;
        std::cerr << "goal reached" <<std::endl;

//        Print_Visited_Nodes();
        MoveRobot(Stack, robot);
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

void fp::algorithm::SetUp() {
    width = fp::API::mazeWidth();
    height = fp::API::mazeHeight();
    // Printing on Simulator screen
    fp::algorithm::log("running");
    fp::algorithm::log("Width is :");
    fp::algorithm::displayNumber(width);
    fp::algorithm::log("height is :");
    fp::algorithm::displayNumber(height);

    // Highlighting the Goal and Start coordinates in the simulator
    fp::API::setColor(0,0,'G');
    fp::API::setText(0, 0, "S");
    fp::API::setColor(7,7,'Y');
    fp::API::setText(7, 7, "G");
    fp::API::setColor(8,8,'Y');
    fp::API::setText(8, 8, "G");
    fp::API::setColor(7,8,'Y');
    fp::API::setText(7, 8, "G");
    fp::API::setColor(8,7,'Y');
    fp::API::setText(8, 7, "G");

    // Highlighting the boundary walls in the simulator
    for (int i = 0; i<width; i += 1){
        for (int j = 0; j<height; j += 1){
            if(i==0)
            {
                fp::API::setWall(i,j,'w');
            }
            if(j==0)
            {
                fp::API::setWall(i,j,'s');
            }
            if(i==width-1)
            {
                fp::API::setWall(i,j,'e');
            }
            if(j==width-1)
            {
                fp::API::setWall(i,j,'n');
            }
        }
    }
}

void fp::algorithm::MoveRobot(std::stack<int> path, std::shared_ptr<fp::landbasedrobot> robot) {

    std::cout << "Moving  Robot" <<std::endl;
    std::cout << "Current robot start coordinates " << m <<"," << n <<std::endl;
    std::cout << "Current Robot direction = " << dir <<std::endl;
    path = ReverseStack(path);
    std::cout << "Printing reversed stack" <<std::endl;
    std::cerr << "Printing reversed stack" <<std::endl;
    PrintStack(path);
    std::cout << "\n";

    // Creating an object from the Direction class
    direc = 'w';

    int coordinate,x,y,m,n;
    std::array<int, 2> point;


    while (!path.empty()) {
        std::cerr <<"\n"<<std::endl;
        std::cout << "path not empty, following path" <<std::endl;
        std::cerr << "path not empty, following path" <<std::endl;
        coordinate = path.top();
        point = Get_Coordinates(coordinate);
        x = point[0];
        y = point[1];

        path.pop();
        coordinate = path.top();
        point = Get_Coordinates(coordinate);
        m = point[0];
        n = point[1];


        //Checking for wall on Left
        std::cerr << "outside left value = " << fp::API::wallLeft() <<std::endl;
        if (fp::API::wallLeft()) {
            std::cerr << "inside wall left = " << fp::API::wallLeft() <<std::endl;
            if (dir == dirc.NORTH) {
                direc = 'w';
            } else if (dir == dirc.WEST) {
                direc = 's';
            } else if (dir == dirc.SOUTH) {
                direc = 'e';
            } else if (dir == dirc.EAST) {
                direc = 'n';
            }
            fp::API::setWall(x, y, direc);

            if (dir == dirc.NORTH && x != 0) {
//                WallArray = SetWall(Set_Coordinates(x, y), Set_Coordinates(x - 1, y));
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x-1, y)] = 1;
            }

            if (dir == dirc.EAST && y != 15) {
                std::cerr << "inside wall left east= " << fp::API::wallLeft() <<std::endl;
                std::cerr << x << "," << y << "    "<< x <<","<< y+1 <<std::endl;
                std::cerr << Set_Coordinates(x, y) <<std::endl;
                std::cerr << Set_Coordinates(x, y + 1) <<std::endl;
                std::cerr << WallArray[33][49] <<std::endl;
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y + 1)] = 1;
                std::cerr << "exiting wall left east= " << fp::API::wallLeft() <<std::endl;
            }
            if (dir == dirc.WEST && y != 0) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y - 1)] = 1;
            }
            if (dir == dirc.SOUTH && x != 15) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x+1, y)] = 1;
            }
            std::cerr << "exiting wall left = " << fp::API::wallLeft() <<std::endl;

        }

        std::cerr << "outside front value = " << fp::API::wallFront() <<std::endl;
        if (fp::API::wallFront()) {
            std::cerr << "inside wall front = " << fp::API::wallFront() <<std::endl;

            if (dir == dirc.NORTH) {
                direc = 'n';
            } else if (dir == dirc.WEST) {
                direc = 'w';
            } else if (dir == dirc.SOUTH) {
                direc = 's';
            } else if (dir == dirc.EAST) {
                direc = 'e';
            }
            fp::API::setWall(x, y, direc);
            if (dir == dirc.NORTH && y != 15) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y + 1)] = 1;
            }

            if (dir == dirc.EAST && x != 15) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x+1, y)] = 1;
            }
            if (dir == dirc.WEST && x != 0) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x-1, y)] = 1;
            }
            if (dir == dirc.SOUTH && y != 0) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y - 1)] = 1;
            }
        }

        // Checking for wall on Right
        std::cerr << "outside right value = " << fp::API::wallRight() <<std::endl;
        if (fp::API::wallRight()) {
            std::cerr << "inside wall right = " << fp::API::wallRight() <<std::endl;
            if (dir == dirc.NORTH) {
                direc = 'e';
            } else if (dir == dirc.WEST) {
                direc = 'n';
            } else if (dir == dirc.SOUTH) {
                direc = 'w';
            } else if (dir == dirc.EAST) {
                direc = 's';
            }
            fp::API::setWall(x, y, direc);

            if (dir == dirc.NORTH && x != 15) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x+1, y)] = 1;
            }

            if (dir == dirc.EAST && y != 0) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y - 1)] = 1;
            }
            if (dir == dirc.WEST && y != 15) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x, y + 1)] = 1;
            }
            if (dir == dirc.SOUTH && x != 0) {
                WallArray[Set_Coordinates(x, y)][Set_Coordinates(x-1, y)] = 1;
            }

        }


        if (dir == dirc.NORTH) {
            // Moving Right
            std::cerr << "inside robot motion  - facing North" <<std::endl;
            std::cout << "prev coordinates = "<< x << y <<std::endl;
            std::cout << "next coordinates = "<< m << n <<std::endl;

            //Moving Right
            if (m > x) {
                if (fp::API::wallRight()) {
                    std::cerr << "North inside wall right = " ;
                    std::cerr << fp::API::wallRight() << std::endl;
                    std::cout << "Wall encountered when moving right, solve function called" << std::endl;
                    std::cerr << "Wall encountered when moving right, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving right" << std::endl;
                dir = dirc.EAST;
                fp::API::turnRight();
                std::cerr << "Moved right" << std::endl;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            //Moving Left
            else if (m < x) {
                if (fp::API::wallLeft()) {
                    std::cout << "Wall encountered when moving left, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Left" << std::endl;
                dir = dirc.WEST;
                fp::API::turnLeft();
                std::cerr << "Moved left" << std::endl;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            // Moving Forward
            else if (n > y) {
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving forward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Forward" << std::endl;
                dir = dirc.NORTH;
                std::cerr << "Have to move Forward" <<std::endl;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            // Moving Down
            else if (n < y)
            {
                fp::API::turnRight();
                fp::API::turnRight();
                std::cerr << "Rotated right twices" << std::endl;
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving backward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Have to move backward" << std::endl;
                dir = dirc.SOUTH;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }
        }

        // If the current direction is South
        else if (dir == dirc.SOUTH) {
            if (m < x) {
                if (fp::API::wallRight()) {
                    std::cout << "Wall encountered when moving right, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving right" << std::endl;
                dir = dirc.WEST;
                fp::API::turnRight();
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            //Moving Left
            else if (m > x) {
                if (fp::API::wallLeft()) {
                    std::cout << "Wall encountered when moving left, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Left" << std::endl;
                dir = dirc.EAST;
                fp::API::turnLeft();
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            // Moving Forward
            else if (n < y) {
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving forward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Forward" << std::endl;
                dir = dirc.SOUTH;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

            // Moving Down
            else if (n > y)
            {
                fp::API::turnRight();
                fp::API::turnRight();
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving backward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Backward" << std::endl;
                dir = dirc.NORTH;
                std::cerr << "Current Robot direction = " << dir <<std::endl;

            }

        }

        // If the current direction is East
        else if (dir == dirc.EAST) {
            if (n < y) {
                if (fp::API::wallRight()) {
                    std::cout << "Wall encountered when moving right, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving right" << std::endl;
                dir = dirc.SOUTH;
                fp::API::turnRight();
                std::cerr << "Current Robot direction = " << dir <<std::endl;

            }

                //Moving Left
            else if (n > y) {
                if (fp::API::wallLeft()) {
                    std::cout << "Wall encountered when moving left, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Left" << std::endl;
                dir = dirc.NORTH;
                fp::API::turnLeft();
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

                // Moving Forward
            else if (m > x) {
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving forward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Forward" << std::endl;
                dir = dirc.EAST;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

                // Moving Down
            else if (m < x)
            {
                fp::API::turnRight();
                fp::API::turnRight();
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving backward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Backward" << std::endl;
                dir = dirc.WEST;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }
        }

        // If the current direction is west
        else if (dir == dirc.WEST) {
            if (n > y) {
                if (fp::API::wallRight()) {
                    std::cout << "Wall encountered when moving right, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving right" << std::endl;
                dir = dirc.NORTH;
                fp::API::turnRight();
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

                //Moving Left
            else if (n < y) {
                if (fp::API::wallLeft()) {
                    std::cout << "Wall encountered when moving left, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Left" << std::endl;
                dir = dirc.SOUTH;
                fp::API::turnLeft();
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

                // Moving Forward
            else if (m < x) {
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving forward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Forward" << std::endl;
                dir = dirc.WEST;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }

                // Moving Down
            else if (m > x)
            {
                fp::API::turnRight();
                fp::API::turnRight();
                if (fp::API::wallFront()) {
                    std::cout << "Wall encountered when moving backward, solve function called" << std::endl;
                    robot->set_x(x);
                    robot->set_y(y);
                    Solve(robot);
                }
                std::cout << "Moving Backward" << std::endl;
                dir = dirc.EAST;
                std::cerr << "Current Robot direction = " << dir <<std::endl;
            }
        }
        Solution.push(Set_Coordinates(m,n));
        std::cerr << "Printing solution stack dawww" <<std::endl;
        PrintStack(Solution);
        VisitedArray[x][y]=1;
        VisitedArray[m][n]=1;
        fp::API::moveForward();
        std::cout << "Moving forward dawwwww" <<std::endl;
        std::cerr << "Robot moving forward executed" <<std::endl;
        std::cerr << "Current Robot coordinates = " << m <<" " << n <<std::endl;
}
}



void fp::algorithm::PrintStack(std::stack <int> s)
{
    std::cerr<<"Checking stack"<<std::endl;
    int coord;
    std::array<int, 2> point;
    while(!s.empty())
    {
        coord = s.top();
        point = Get_Coordinates(coord);
        std::cerr<<point[0]<<","<<point[1]<<std::endl;
        std::cout<<point[0]<<","<<point[1]<<std::endl;
        s.pop();
    }
}

std::stack<int> fp::algorithm::ReverseStack(std::stack<int> stack) {

    std::stack<int> temp;
    int item;
    while (!stack.empty())
    {
        item = stack.top();
        stack.pop();
        temp.push(item);
    }
    return temp;
}

std::stack<int> fp::algorithm::ClearStack(std::stack<int> stack) {

    while (!stack.empty())
    {
        stack.pop();
    }
    return stack;
}





