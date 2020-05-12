//
// Created by prade on 4/22/2020.
//

#pragma once

#include <string>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"
#include "../LandBasedRobot/landbasedrobot.h"
#include <iostream>


namespace fp {
    class landbasedwheeled : public landbasedrobot {
    public:
        //--method prototypes
        virtual void GoUp(int x_, int y_) override;  //Move the robot up in the maze
        virtual void GoDown(int x_, int y_) override;  //Move the robot down in the maze
        virtual void GoLeft(int x_, int y_) override;  //Move the robot left in the maze
        virtual void GoRight(int x_, int y_) override;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick) override;  //Arm picks up an object
        virtual void Release(std::string& release) override;  //Arm releases an object
        virtual int get_x() const override;//--get the x coordinate of a robot
        virtual int get_y() const override;//--get the y coordinate of a robot
        virtual char get_direction() const override ;//--get the current direction of the robot
        virtual void set_x(int x) override; //--set the x coordinate of a robot
        virtual void set_y(int y) override ; //--set the y coordinate of a robot


        // Deep copy constructor
        landbasedwheeled(const landbasedwheeled &source):landbasedwheeled(
                source.name_,
                source.x_,
                source.y_,
                source.speed_,
                source.width_,
                source.length_,
                source.height_,
                source.capacity_,
                source.directions_,
                source.wheel_number,
                *source.wheel_type
                ){}

        //--Constructor



        landbasedwheeled(std::string name="None", int x=0, int y=0, double speed = 0, double width = 0, double length = 0, double height = 0, double capacity = 0, char directions = 'N', int w_number=2, std::string w_type="round") : landbasedrobot(name, x, y, speed, width, length, height, capacity, directions), wheel_number{w_number},wheel_type{nullptr} {
            std::shared_ptr<std::string> wheel_type {new std::string {w_type}};
        }

//--Destructor
        virtual ~landbasedwheeled(){
        }

    protected:
        // --attributes
        int wheel_number;  //Number of wheels mounted on the robot
        std::shared_ptr<std::string> wheel_type;  //Type of wheels mounted on the robot.
    };//--class landbasedwheeled
}//--namespace fp

