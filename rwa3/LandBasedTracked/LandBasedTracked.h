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


        // Deep copy constructor
        LandBasedTracked(const LandBasedTracked &source):LandBasedTracked(
                source.name_,
                source.x_,
                source.y_,
                *source.track_type){}

        //--Constructor

        LandBasedTracked(std::string name, int x, int y) : LandBasedTracked(name, x, y, "flat"){
        }
        LandBasedTracked(std::string name, int x, int y, std::string t_type) : LandBasedRobot(name_, x_, y_), track_type{nullptr} {
            auto* track_type = new std::string;
            *track_type = t_type;
        }

        //--Destructor
        virtual ~LandBasedTracked(){}
    protected:
        // --attributes
        std::shared_ptr<std::string> track_type;  //Type of track mounted on the robot.

    };//--class LandBasedTracked
}//--namespace rwa3

