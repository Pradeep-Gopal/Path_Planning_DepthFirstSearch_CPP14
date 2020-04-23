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
        // Deep copy constructor
        LandBasedTracked(const LandBasedTracked &source):LandBasedTracked(
                *source.track_type){}

        //--Constructor
        LandBasedTracked(std::string t_type) : track_type{nullptr} {
            auto* track_type = new std::string;
            *track_type = t_type;
        }

        //--Destructor
        ~LandBasedTracked(){}
    protected:
        // --attributes
        std::shared_ptr<std::string> track_type;  //Type of track mounted on the robot.

    };//--class LandBasedTracked
}//--namespace rwa3

