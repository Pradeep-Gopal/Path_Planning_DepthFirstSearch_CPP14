//
// Created by prachu on 5/9/20.
//

#pragma once
#include <array>
#include <stack>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"
#include "../Maze/maze.h"
#include "../Direction/direction.h"


namespace fp {
    class algorithm : public maze {
    public:

        //Methods
        void SetUp(); //Initializes the Micro mouse simulation with Perimeter, Start and Goal highlighted
        void ClearVisitedNodes(); //Initializes the Visited_Nodes array with bool zero
        void ClearVisitedArray(); //Initializes the Visited_Array array with bool zero
        void PrintVisitedNodes(); //USed to print the Visited_Nodes array
        void Solve(std::shared_ptr<fp::landbasedrobot> robot); //Function to find the path from current location to the goal location
        void MoveRobot(std::stack<int> path, std::shared_ptr<fp::landbasedrobot> ptr); //Function to move the micro mouse robot in the MMS
        void log(const std::string& text); //Function which is used to print text on the Simulator screen
        void displayNumber(int num); //Function which is used to print numbers on the Simulator screen
        void PrintStack(std::stack <int> s); //Function used to Print the contents of the stack
        static bool CheckGoal(int x, int y); //Function to check if the current location of the robot is the Goal
        int SetCoordinates(int x, int y); //Converts the x and y coordinates into a single integer
        std::array<int, 2> GetCoordinates(int coordinates); //Function to the get the x and y coordinates
        std::stack<int> ReverseStack(std::stack <int> stack); //Returns the reversed Stack
        std::stack<int> ClearStack(std::stack <int> stack); //Empties the Stack and returns the emptied stack
        void HighlightPath(std::stack<int> s); //Highlights the path in the maze from start to goal
        void ClearPath(std::stack<int> s); //Clears the path in the maze

        // Constructor for the Algorithm class
        algorithm()
        {
            width = 0;
            height = 0;
            dir = 'n';
            direc = 'w';
            m = 0;
            n = 0;
            Start = 0;
        }

        //Attributes
        int width; //Stores the width of the maze
        int height; //Stores the height of the maze
        char dir; //Stores the direction the robot is facing inside the maze
        char direc; //Temporary variable to store the direction
        int x; // Stores the current x coordinate of the robot in the maze
        int y; //Stores the current y coordinate of the robot in the maze
        int coordinate; //Stores the coordinate containing both x and y
        int Start; //Variable to store the start coordinate for the solve fucntion method
        int m; //Stores the future x coordinate of the robot in the maze
        int n; //Stores the future y coordinate of the robot in the maze
        int p; //Temp coordinate variable
        int NewCoordinate; //Variable used to store the popped off value from stack
        std::array<std::array<int, 16>, 16> VisitedNodes; //Boolean array that keeps track of x and y coordinates visited by the robot while planning
        std::stack<int> Stack; //Used to store the path from current node to the goal node
        std::stack<int> Solution; //Stores the Final path from start to goal node
        std::stack <int> temp; //Temporary stack used when stack size is 1
        std::array<std::array<int, 16>, 16> VisitedArray; //Boolean array that keeps track of x and y coordinates visited by the robot while moving through maze
        std::array <int,2> point; //Stores the x and y coordinate
        // Destructor for the Algorithm class
        ~algorithm(){}
    };
}


