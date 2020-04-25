/**
 * @class LandBasedWheeled
 * @author Markose Jacob (UID 117000269), Pradeep Gopal (116885027), Rohit Thakur (115803282), Srikumar Muralidharan (UID 116950572)
 * @date 25 April 2020
 * @file landbasedwheeled.h
 * @brief This is a concrete derived class from LandBasedRobot and contains the required methods, constructors, destructors and attributes
 */
#pragma once
#include <string>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"
#include <iostream>

namespace rwa3 {
    class LandBasedWheeled : public LandBasedRobot {
    public:
        //--method prototypes
        /**
        * @brief Virtual method prototype for making the robot move up
        */
        virtual void GoUp(int x_, int y_) override; //Move the robot up in the maze
        /**
        * @brief Virtual method prototype for making the robot move Down
        */
        virtual void GoDown(int x_, int y_) override;  //Move the robot down in the maze
        /**
        * @brief Virtual method prototype for making the robot move left
        */
        virtual void TurnLeft(int x_, int y_) override;  //Move the robot left in the maze
        /**
        * @brief Virtual method prototype for making the robot move right
        */
        virtual void TurnRight(int x_, int y_) override;  //Move the robot right in the maze
        /**
        * @brief Virtual method prototype for making the robot pick up an item
        */
        virtual void PickUp(std::string& pick) override;  //Arm picks up an object
        /**
        * @brief Virtual method prototype for making the robot release an item
        */
        virtual void Release(std::string& release) override;  //Arm releases an object
        /**
	    * @brief Virtual method prototype for a getter for the robots X coordinate
        * @return The X coordinate value
	    */
        virtual int get_x() const override;//--get the x coordinate of a robot
        /**
	    * @brief Virtual method prototype for a getter for the robots Y coordinate
        * @return The Y coordinate value
	    */
        virtual int get_y() const override;//--get the y coordinate of a robot
        /**
	    * @brief Virtual method prototype for a setter for the robots X coordinate
	    */
        virtual void set_x(int x) override; //--set the x coordinate of a robot
        /**
	    * @brief Virtual method prototype for a setter for the robots Y coordinate
	    */
        virtual void set_y(int y) override ; //--set the y coordinate of a robot
        /**
	    * @brief Deep copy constructor if we have to use raw pointers
	    */
        // Deep copy constructor
        LandBasedWheeled(const LandBasedWheeled &source):LandBasedWheeled(
                source.name_,
                source.x_,
                source.y_,
                source.wheel_number,
                *source.wheel_type
        ){}

        /**
	    * @brief Constructor to initialise the attributes
         *@param Initialises name as none if no input is provided
         *@param Initialises X coordinate as 0 if no input is provided
         *@param Initialises Y coordinate as 0 if no input is provided
         *@param Initialises w_number as 2 if no input is provided
         *@param Initialises w_type as round if no input is provided
	    */
        //--Constructor
        LandBasedWheeled(std::string name="None", int x=0, int y=0, int w_number=2, std::string w_type="round") : LandBasedRobot(name, x , y), wheel_number{w_number}, wheel_type{nullptr}{
            std::shared_ptr<std::string> wheel_type {new std::string {w_type}};
        }
        /**
	    * @brief Destructor to delete the object when it goes out of scope
	    */
        //--Destructor
        virtual ~LandBasedWheeled(){
        }

    protected:
        /**
         * @brief Additional attributes which are not present in LandBasedRobot
         * @param wheel_number stores the number of wheels
         * @param wheel_type stores the type on wheel
         */
        // --attributes
        int wheel_number;  //Number of wheels mounted on the robot
        std::shared_ptr<std::string> wheel_type;  //Type of wheels mounted on the robot.

    };//--class LandBasedWheeled
}//--namespace rwa3