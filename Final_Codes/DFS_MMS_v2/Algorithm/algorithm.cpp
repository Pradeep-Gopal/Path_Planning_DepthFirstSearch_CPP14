//
// Created by prachu on 5/9/20.
//

#include <iostream>
#include "algorithm.h"
#include "../API/api.h"

fp::Direction dirc; //Object dirc created for the Direction class
fp::maze Maze; //Object Maze created for the maze class

void fp::algorithm::log(const std::string& text)
{
    std::cerr << "\n" << text;
}


void fp::algorithm::displayNumber(const int num)
{
    std::cerr << num << std::endl;
}

void fp::algorithm::ClearVisitedNodes()
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

void fp::algorithm::ClearVisitedArray()
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

void fp::algorithm::PrintVisitedNodes()
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
    ClearVisitedNodes(); // Initialising the Visited Node with zeroes for every Solve function call
    Stack = ClearStack(Stack); //Emptying the stack for every new start point
    int x{robot->get_x()}; //Getting the current robot x coordinate
    int y{robot->get_y()}; //Getting the current robot y coordinate
    Start = SetCoordinates(x,y); //Transforming x and y coordinates to a single integer value
    Stack.push(Start); //Pushing the Start node into the stack

    while(!CheckGoal(x,y)) //Iterates till the goal is converged
    {
        x = robot->get_x(); //Getting the current robot x coordinate
        y = robot->get_y(); //Getting the current robot y coordinate

        //Priority 1 -  If not restricted, going South
        if ( y-1 >= 0 && (!VisitedNodes[x][y-1]) && (!Maze.WallArray[SetCoordinates(x, y)][SetCoordinates(x, y - 1)]) && (!VisitedArray[x][y-1]))
        {
            robot->GoDown(x, y); //Moving the robot South
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            VisitedNodes[x][y+1] = 1; //Marking the previous node as visited
            Stack.push(SetCoordinates(x,y)); // Pushing the current x,,y coordinates into the stack
        }

        //Priority 2 -  If robot cannot go south, going East if not restricted
        else if ((x+1 >= 0) && (x+1 < 16) && (!VisitedNodes[x+1][y]) && (!VisitedArray[x+1][y]) && (!Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x + 1, y)])){
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            robot->GoRight(x, y); //Moving the robot Right
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            VisitedNodes[x-1][y] = 1; //Marking the previous node as visited
            Stack.push(SetCoordinates(x,y)); //Pushing the current x,,y coordinates into the stack
        }

        //Priority 3 -  If robot cannot go south or east, going North if not restricted
        else if ( y+1 < 16 && (!VisitedNodes[x][y+1]) && (!VisitedArray[x][y+1]) &&(!Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y + 1)]))
        {
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            robot->GoUp(x, y); //Moving the Robot up
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            VisitedNodes[x][y-1] = 1; //Marking the previous node as visited
            Stack.push(SetCoordinates(x,y)); //Pushing the current x,,y coordinates into the stack
        }

        //Priority 4 -  If robot cannot go south or east or north, going West if not restricted
        else if ((x-1 >= 0) && (!VisitedNodes[x-1][y]) && (!VisitedArray[x-1][y]) && (!Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x - 1, y)])){
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            robot->GoLeft(x, y); //Moving the Left Up
            x = robot->get_x(); //Getting the current robot x coordinate
            y = robot->get_y(); //Getting the current robot y coordinate
            VisitedNodes[x+1][y] = 1; //Marking the previous node as visited
            Stack.push(SetCoordinates(x,y)); //Pushing the current x,,y coordinates into the stack
        }

        // If the robot cannot go in either of the direction, popping the current coordinate from the stack
        else{
            if(Stack.size() == 1) //If the Stack has only the Start coordinate
            {
                p = Solution.top(); //Getting the top most element from the stack
                point = GetCoordinates(p); //Converting the x and y coordinates into a single integer
                robot->set_x(point[0]); //Setting the popped off x coordinate as the current robot x coordinate
                robot->set_y(point[1]); //Setting the popped off y coordinate as the current robot y coordinate
                temp.push(p); //Pushing the popped off coordinate into the temporary stack
                Solution.pop(); //Popping from the solution stack only
            }
            else{
                NewCoordinate = Stack.top(); //Getting the topmost coordinate from stack
                point = GetCoordinates(NewCoordinate); //Converting the coordinates into x and y coordinates
                VisitedNodes[point[0]][point[1]] = 1; //Setting the coordinate popped as visited
                Stack.pop(); //Popping from the stack
                NewCoordinate = Stack.top(); //Getting the new topmost coordinate from the stack after popping
                point = GetCoordinates(NewCoordinate); //Converting the x and y coordinates into a single integer
                robot->set_x(point[0]); //Setting the x coordinate for the robot
                robot->set_y(point[1]); //Setting the y coordinate for the robot
            }
    }
    }

    if(temp.size()> 0 ) //Executes only when temp stack is not empty
    {
        Stack = ReverseStack(Stack); //Reversing the Stack
        Stack.pop(); //Popping off the first element
        while(!temp.empty()) //Executes as long as temp stack is not empty
        {
            Stack.push(temp.top()); //Pushing the temp stack elements into the stack
            temp.pop(); //Deleting the temp elements for every iteration
        }
        Stack = ReverseStack(Stack); // Reversing the stack after all the temp stack elements are added to the stack
    }

    while(CheckGoal(x,y)) //Executes when the current x and y coordinates is one of the goal location
    {
        MoveRobot(Stack, robot); //Moving the robot in the MMS
        return;
    }
}


std::array<int, 2> fp::algorithm::GetCoordinates(int coordinates)
{
    point[1] = coordinates/16;
    point[0] = coordinates%16;
    return point;
}

bool fp::algorithm::CheckGoal(int x, int y)
{
    if((x == 7 && y == 7) || (x == 8 && y == 8) || (x == 7 && y == 8) || (x == 8 && y == 7))
        return true;
    return false;
}

int fp::algorithm::SetCoordinates(int x, int y) {
    coordinate = (x) + 16*y;
    return coordinate;
}

void fp::algorithm::SetUp()
{
    width = fp::API::mazeWidth(); //Getting the width of the maze from the MMS
    height = fp::API::mazeHeight(); //Getting the height of the maze from the MMS

    // Printing on Simulator screen
    fp::algorithm::log("running");
    fp::algorithm::log("Width is :");
    fp::algorithm::displayNumber(width);
    fp::algorithm::log("height is :");
    fp::algorithm::displayNumber(height);

    // Highlighting the Goal and Start coordinates in the simulator
    fp::API::setColor(0,0,'y');
    fp::API::setText(0, 0, "Start");
    fp::API::setColor(7,7,'y');
    fp::API::setText(7, 7, "A");
    fp::API::setColor(8,8,'y');
    fp::API::setText(8, 8, "O");
    fp::API::setColor(7,8,'y');
    fp::API::setText(7, 8, "G");
    fp::API::setColor(8,7,'y');
    fp::API::setText(8, 7, "L");

    // Highlighting the boundary walls in the simulator
    for (int i = 0; i<width; i += 1)
    {
        for (int j = 0; j<height; j += 1)
        {
            if(i==0)
            {
                fp::API::setWall(i,j,'w'); //Highlighting the wall on the west side of the node
            }
            if(j==0)
            {
                fp::API::setWall(i,j,'s'); //Highlighting the wall on the south side of the node
            }
            if(i==width-1)
            {
                fp::API::setWall(i,j,'e'); //Highlighting the wall on the east side of the node
            }
            if(j==width-1)
            {
                fp::API::setWall(i,j,'n'); //Highlighting the wall on the north side of the node
            }
        }
    }
}

void fp::algorithm::MoveRobot(std::stack<int> path, std::shared_ptr<fp::landbasedrobot> robot) {

    path = ReverseStack(path); // Reversing the stack sent from the Solve function
//    HighlightPath(path); // Highlighting the maze in the robot

    while (!path.empty()) // Iterates till the robot moves and reaches the goal following the path
    {
        coordinate = path.top(); //Getting the first for the robot to move to from the path
        point = GetCoordinates(coordinate); //Converting the coordinates into x and y coordinates
        x = point[0];
        y = point[1];

        path.pop(); //Popping off the path stack to get the next coordinate the robot to move to
        coordinate = path.top(); //Getting the first for the robot to move to from the path
        point = GetCoordinates(coordinate); //Converting the coordinates into x and y coordinates
        m = point[0];
        n = point[1];

        //Checking for wall on Left Side of the Robot
        if (fp::API::wallLeft())
        {
            //Setting the direc value based on the current direction the robot is facing
            if (dir == dirc.NORTH) {
                direc = 'w';
            } else if (dir == dirc.WEST) {
                direc = 's';
            } else if (dir == dirc.SOUTH) {
                direc = 'e';
            } else if (dir == dirc.EAST) {
                direc = 'n';
            }
            fp::API::setWall(x, y, direc); //Highlighting the wall in the maze

            // Setting the Walls in the Maze array when a wall is detected
            if (dir == dirc.NORTH && x != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x-1, y)] = 1;
            }
            if (dir == dirc.EAST && y != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y + 1)] = 1;
            }
            if (dir == dirc.WEST && y != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y - 1)] = 1;
            }
            if (dir == dirc.SOUTH && x != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x+1, y)] = 1;
            }
        }

        //Checking for wall on Front of the Robot
        if (fp::API::wallFront())
        {
            //Setting the direc value based on the current direction the robot is facing
            if (dir == dirc.NORTH) {
                direc = 'n';
            } else if (dir == dirc.WEST) {
                direc = 'w';
            } else if (dir == dirc.SOUTH) {
                direc = 's';
            } else if (dir == dirc.EAST) {
                direc = 'e';
            }
            fp::API::setWall(x, y, direc); //Highlighting the wall in the maze

            // Setting the Walls in the Maze array when a wall is detected
            if (dir == dirc.NORTH && y != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y + 1)] = 1;
            }
            if (dir == dirc.EAST && x != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x+1, y)] = 1;
            }
            if (dir == dirc.WEST && x != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x-1, y)] = 1;
            }
            if (dir == dirc.SOUTH && y != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y - 1)] = 1;
            }
        }

        //Checking for wall on Right side of the Robot
        if (fp::API::wallRight())
        {
            //Setting the direc value based on the current direction the robot is facing
            if (dir == dirc.NORTH) {
                direc = 'e';
            } else if (dir == dirc.WEST) {
                direc = 'n';
            } else if (dir == dirc.SOUTH) {
                direc = 'w';
            } else if (dir == dirc.EAST) {
                direc = 's';
            }
            fp::API::setWall(x, y, direc); //Highlighting the wall in the maze

            // Setting the Walls in the Maze array when a wall is detected
            if (dir == dirc.NORTH && x != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x+1, y)] = 1;
            }
            if (dir == dirc.EAST && y != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y - 1)] = 1;
            }
            if (dir == dirc.WEST && y != 15) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x, y + 1)] = 1;
            }
            if (dir == dirc.SOUTH && x != 0) {
                Maze.WallArray [SetCoordinates(x, y)][SetCoordinates(x-1, y)] = 1;
            }
        }

        // Checking if the current robot direction is North
        if (dir == dirc.NORTH) {

            //Moving Right
            if (m > x)
            {
                if (fp::API::wallRight()) //Check if there is a wall on the right
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.EAST; //Setting the robot direction to east
                fp::API::turnRight(); // Robot turns 90 degrees in the right side
            }

            //Moving Left
            else if (m < x)
            {
                if (fp::API::wallLeft()) //Check if there is a wall on the left
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.WEST; //Setting the robot direction to west
                fp::API::turnLeft(); // Robot turns 90 degrees in the left side
            }

            // Moving Forward
            else if (n > y)
            {
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.NORTH; //Setting the robot direction to north
            }

            // Moving Down
            else if (n < y)
            {
                fp::API::turnRight(); //Robot turns 90 degrees in the right side
                fp::API::turnRight(); //Robot turns another 90 degrees in the right side
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.SOUTH; //Setting the robot direction to south
            }
        }

        // Checking if the current robot direction is South
        else if (dir == dirc.SOUTH) {

            //Moving Right
            if (m < x) {
                if (fp::API::wallRight()) //Check if there is a wall on the right
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.WEST; //Setting the robot direction to west
                fp::API::turnRight(); // Robot turns 90 degrees in the right side
            }

            //Moving Left
            else if (m > x) {
                if (fp::API::wallLeft()) //Check if there is a wall on the left
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.EAST; //Setting the robot direction to east
                fp::API::turnLeft(); // Robot turns 90 degrees in the left side
            }

            // Moving Forward
            else if (n < y) {
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.SOUTH; //Setting the robot direction to south
            }

            // Moving Down
            else if (n > y)
            {
                fp::API::turnRight(); //Robot turns 90 degrees in the right side
                fp::API::turnRight(); //Robot turns another 90 degrees in the right side
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.NORTH; //Setting the robot direction to north

            }

        }

        // If the current direction is East
        else if (dir == dirc.EAST)
        {
            //Moving Right
            if (n < y) {
                if (fp::API::wallRight()) //Check if there is a wall on the right
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.SOUTH; //Setting the robot direction to south
                fp::API::turnRight(); // Robot turns 90 degrees in the right side
            }

            //Moving Left
            else if (n > y) {
                if (fp::API::wallLeft()) //Check if there is a wall on the left
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.NORTH; //Setting the robot direction to North
                fp::API::turnLeft(); // Robot turns 90 degrees in the left side
            }

            // Moving Forward
            else if (m > x) {
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.EAST; //Setting the robot direction to east
            }

            // Moving Down
            else if (m < x)
            {
                fp::API::turnRight(); //Robot turns 90 degrees in the right side
                fp::API::turnRight(); //Robot turns another 90 degrees in the right side
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.WEST; //Setting the robot direction to west
            }
        }

        // If the current direction is west
        else if (dir == dirc.WEST) {

            //Moving right
            if (n > y) {
                if (fp::API::wallRight()) //Check if there is a wall on the right
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.NORTH; //Setting the robot direction to north
                fp::API::turnRight(); // Robot turns 90 degrees in the right side
            }

            //Moving Left
            else if (n < y) {
                if (fp::API::wallLeft()) //Check if there is a wall on the left
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.SOUTH; //Setting the robot direction to south
                fp::API::turnLeft(); // Robot turns 90 degrees in the left side
            }

            // Moving Forward
            else if (m < x) {
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.WEST; //Setting the robot direction to west
            }

            // Moving Down
            else if (m > x)
            {
                fp::API::turnRight(); //Robot turns 90 degrees in the right side
                fp::API::turnRight(); //Robot turns another 90 degrees in the right side
                if (fp::API::wallFront()) //Check if there is a wall on the front
                {
                    robot->set_x(x); //Getting the current x coordinate of the robot
                    robot->set_y(y); //Getting the current y coordinate of the robot
                    //ClearPath(path); //Clears the path highlighted in the maze
                    Solve(robot); //Solve function called to give a new path from the current robot location
                }
                dir = dirc.EAST; //Setting the robot direction to east
            }
        }
        Solution.push(SetCoordinates(m,n)); //Solution the traversed coordinates onto the solution stack
        VisitedArray[x][y]=1; //Marking the previous node as visited
        VisitedArray[m][n]=1; //Marking the current node as visited
        fp::API::moveForward(); //Moving the robot forward
        if (!CheckGoal(m,n))
            fp::API::setColor(m,n,'g'); //highlighting the path traced by the robot
        if (CheckGoal(m,n)){ //Checking if the current coordinates is the goal
            std::cerr << "Goal Reached by the Robot in the MMS" <<std::endl;
            exit(0);
        }
}
}

void fp::algorithm::HighlightPath(std::stack<int> s) {

    int x;
    while (!s.empty())
    {
        x = s.top();
        point = GetCoordinates(x);
        fp::API::setColor(point[0], point[1], 'g');
        s.pop();
    }
}

void fp::algorithm::ClearPath(std::stack<int> s) {

    int x;
    while (!s.empty())
    {
        x = s.top();
        point = GetCoordinates(x);
        fp::API::clearColor(point[0], point[1]);
        s.pop();
    }
}

void fp::algorithm::PrintStack(std::stack <int> s)
{
    int coord;
    while(!s.empty())
    {
        coord = s.top();
        point = GetCoordinates(coord);
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





