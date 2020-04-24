//
// Created by prade on 4/22/2020.
//

#pragma once

#include <string>

namespace rwa3 {
    class LandBasedRobot {

    public:
        //--method prototypes
        virtual void GoUp(int x_, int y_)=0;  //Move the robot up in the maze
        virtual void GoDown(int x_, int y_)=0;  //Move the robot down in the maze
        virtual void TurnLeft(int x_, int y_)=0;  //Move the robot left in the maze
        virtual void TurnRight(int x_, int y_)=0;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick)=0;  //Arm picks up an object
        virtual void Release(std::string& release)=0;  //Arm releases an object.
        virtual int get_x() const=0;//--get the x coordinate of a robot
        virtual int get_y() const=0;//--get the y coordinate of a robot
        virtual void set_x(int x)=0; //--set the x coordinate of a robot
        virtual void set_y(int y)=0; //--set the y coordinate of a robot

        //--Constructor
        LandBasedRobot(std::string name="none", int x=0, int y=0): name_{name}, x_{x}, y_{y}{

        }

        //-- destructor
        virtual ~LandBasedRobot(){}

    protected:
        //--attributes
        std::string name_;  //Name of the robot
        double speed_;  //Driving speed of the robot
        double width_; //Width of the base of the robot
        double length_;  //Length of the base of the robot
        double height_;  //Height of the base of the robot
        double capacity_;  //Payload of the arm
        int x_;  //X coordinate of the robot in the maze
        int y_;  //Y coordinate of the robot in the maze

    };//--class LandBasedRobot
}//--namespace rwa3
