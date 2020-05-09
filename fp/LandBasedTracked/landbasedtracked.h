//
// Created by prade on 4/22/2020.
//

#pragma once
#include <string>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp {
    class landbasedtracked : public landbasedrobot {
    public:
        //--method prototypes
        virtual void GoUp(int x_, int y_) override;  //Move the robot up in the maze
        virtual void GoDown(int x_, int y_) override;  //Move the robot down in the maze
        virtual void GoLeft(int x_, int y_) override;  //Move the robot left in the maze
        virtual void GoRight(int x_, int y_) override;  //Move the robot right in the maze
        virtual void PickUp(std::string& pick) override;  //Arm picks up an object
        virtual void Release(std::string& release) override;  //Arm releases an object.
        virtual int get_x() const override;//--get the x coordinate of a robot
        virtual int get_y() const override;//--get the y coordinate of a robot
        virtual char get_direction() const override ;//--get the current direction of the robot
        virtual void set_x(int x) override; //--set the x coordinate of a robot
        virtual void set_y(int y) override ; //--set the y coordinate of a robot




        // Deep copy constructor
        landbasedtracked(const landbasedtracked &source):landbasedtracked(
                source.name_,
                source.x_,
                source.y_,
                source.speed_,
                source.width_,
                source.length_,
                source.height_,
                source.capacity_,
                source.directions_,
                *source.track_type){}

        //--Constructor

        landbasedtracked(std::string name="None", int x=0, int y=0, double speed = 0, double width = 0, double length = 0, double height = 0, double capacity = 0, char directions = 'N', std::string t_type="flat") : landbasedrobot(name, x, y, speed, width, length, height, capacity, directions), track_type{nullptr} {
            std::shared_ptr<std::string> track_type {new std::string {t_type}};
        }

        //--Destructor
        virtual ~landbasedtracked(){}
    protected:
        // --attributes
        std::shared_ptr<std::string> track_type;  //Type of track mounted on the robot.

    };//--class landbasedtracked
}//--namespace fp

