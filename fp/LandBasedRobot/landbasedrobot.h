//
// Created by prade on 4/22/2020.
//

#pragma once

#include <string>

namespace fp {
    class landbasedrobot {

    public:
        //--method prototypes
        virtual void GoUp(int &x_, int &y_)=0;  //Move the robot up in the maze
        virtual void GoDown(int &x_, int &y_)=0;  //Move the robot down in the maze
        virtual void GoLeft(int &x_, int &y_)=0;  //Move the robot left in the maze
        virtual void GoRight(int &x_, int &y_)=0;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick)=0;  //Arm picks up an object
        virtual void Release(std::string& release)=0;  //Arm releases an object.
        virtual int get_x() const=0;//--get the x coordinate of a robot
        virtual int get_y() const=0;//--get the y coordinate of a robot
        virtual char get_direction() const=0;//--get the current direction of the robot
        virtual void set_x(int x)=0; //--set the x coordinate of a robot
        virtual void set_y(int y)=0; //--set the y coordinate of a robot

        //--Constructor
        landbasedrobot(std::string name="none", int x=0, int y=0, double speed = 0, double width = 0, double length = 0, double height = 0, double capacity = 0, char directions = 'N' ): name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, directions_{directions}
        {};

        //-- destructor
        virtual ~landbasedrobot(){}

    protected:
        //--attributes
        std::string name_;  //Name of the robot
        int x_;  //X coordinate of the robot in the maze
        int y_;  //Y coordinate of the robot in the maze
        double speed_;  //Driving speed of the robot
        double width_; //Width of the base of the robot
        double length_;  //Length of the base of the robot
        double height_;  //Height of the base of the robot
        double capacity_;  //Payload of the arm
        char directions_; //Direction the robot is facing

    };//--class landbasedrobot
}//--namespace fp
