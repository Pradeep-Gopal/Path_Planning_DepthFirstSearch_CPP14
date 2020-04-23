//
// Created by prade on 4/22/2020.
//

#pragma once

#include <string>
#include <memory>
#include "../LandBasedRobot/LandBasedRobot.h"


namespace rwa3 {
    class LandBasedWheeled : public LandBasedRobot {
    public:
        // Deep copy constructor
        LandBasedWheeled(const LandBasedWheeled &source):LandBasedWheeled(
                source.wheel_number,
                *source.wheel_type){}

        //--Constructor
        LandBasedWheeled(int w_number, std::string w_type) : wheel_number{w_number}, wheel_type{nullptr}{
            auto* wheel_type = new std::string;
            *wheel_type = w_type;
        }


//--Destructor
        ~LandBasedWheeled(){
        }

    protected:
        // --attributes
        int wheel_number;  //Number of wheels mounted on the robot
        std::shared_ptr<std::string> wheel_type;  //Type of wheels mounted on the robot.

    };//--class LandBasedWheeled
}//--namespace rwa3

