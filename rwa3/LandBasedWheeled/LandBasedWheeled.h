//
// Created by prade on 4/22/2020.
//

#pragma once

#include <string>
#include <memory>
#include "../LandBasedRobot/LandBasedRobot.h"
#include <iostream>


namespace rwa3 {
    class LandBasedWheeled : public LandBasedRobot {
    public:
        //--method prototypes
        virtual void GoUp(int x_, int y_) override;  //Move the robot up in the maze
        virtual void GoDown(int x_, int y_) override;  //Move the robot down in the maze
        virtual void TurnLeft(int x_, int y_) override;  //Move the robot left in the maze
        virtual void TurnRight(int x_, int y_) override;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick) override;  //Arm picks up an object
        virtual void Release(std::string& release) override;  //Arm releases an object
        virtual int get_x() const override;//--get the x coordinate of a robot
        virtual int get_y() const override;//--get the y coordinate of a robot
        virtual void set_x(int x) override; //--set the x coordinate of a robot
        virtual void set_y(int y) override ; //--set the y coordinate of a robot

        // Deep copy constructor
        LandBasedWheeled(const LandBasedWheeled &source):LandBasedWheeled(
                source.name_,
                source.x_,
                source.y_,
                source.wheel_number,
                *source.wheel_type
                ){}

        //--Constructor
        LandBasedWheeled(std::string name, int x, int y) : LandBasedWheeled(name, x, y, 2, "round"){
        }

        LandBasedWheeled(std::string name, int x, int y, int w_number, std::string w_type) : LandBasedRobot(name, x , y), wheel_number{w_number}, wheel_type{nullptr}{
            //auto* wheel_type = new std::string;
            //*wheel_type = w_type;
            std::shared_ptr<std::string> wheel_type {new std::string {w_type}};
        }

//--Destructor
        virtual ~LandBasedWheeled(){
        }

    protected:
        // --attributes
        int wheel_number;  //Number of wheels mounted on the robot
        std::shared_ptr<std::string> wheel_type;  //Type of wheels mounted on the robot.

    };//--class LandBasedWheeled
}//--namespace rwa3

