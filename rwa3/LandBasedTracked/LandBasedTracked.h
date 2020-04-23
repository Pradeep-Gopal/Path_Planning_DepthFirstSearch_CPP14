//
// Created by prade on 4/22/2020.
//

#pragma once
#include <string>
#include <memory>
#include "../LandBasedRobot/LandBasedRobot.h"

namespace rwa3 {
    class LandBasedTracked : public LandBasedRobot {
    public:
        //--method prototypes
        virtual void GoUp(int x_, int y_) override;  //Move the robot up in the maze
        virtual void GoDown(int x_, int y_) override;  //Move the robot down in the maze
        virtual void TurnLeft(int x_, int y_) override;  //Move the robot left in the maze
        virtual void TurnRight(int x_, int y_) override;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick) override;  //Arm picks up an object
        virtual void Release(std::string& release) override;  //Arm releases an object.
        virtual int get_x() const override;//--get the x coordinate of a robot
        virtual int get_y() const override;//--get the y coordinate of a robot
        virtual void set_x(int x) override; //--set the x coordinate of a robot
        virtual void set_y(int y) override ; //--set the y coordinate of a robot


        // Deep copy constructor
        LandBasedTracked(const LandBasedTracked &source):LandBasedTracked(
                source.name_,
                source.x_,
                source.y_,
                *source.track_type){}

        //--Constructor

        LandBasedTracked(std::string name, int x, int y) : LandBasedTracked(name, x, y, "flat"){
        }
        LandBasedTracked(std::string name, int x, int y, std::string t_type) : LandBasedRobot(name, x, y), track_type{nullptr} {
            //auto* track_type = new std::string;
            //*track_type = t_type;
            std::shared_ptr<std::string> track_type {new std::string {t_type}};
        }

        //--Destructor
        virtual ~LandBasedTracked(){}
    protected:
        // --attributes
        std::shared_ptr<std::string> track_type;  //Type of track mounted on the robot.

    };//--class LandBasedTracked
}//--namespace rwa3

