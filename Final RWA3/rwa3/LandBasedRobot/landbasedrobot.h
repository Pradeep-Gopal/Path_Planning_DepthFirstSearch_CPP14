/**
 * @class LandBasedRobot
 * @author Markose Jacob (UID 117000269), Pradeep Gopal (116885027), Rohit Thakur (115803282), Srikumar Muralidharan (UID 116950572)
 * @date 25 April 2020
 * @file landbasedrobot.h
 * @brief This is the abstract base class for LandBasedTracked class and LandBasedWheeled class contains the required methods, constructors, destructors and attributes
 */

#pragma once

#include <string>

namespace rwa3 {
    class LandBasedRobot {

    public:
        //--method prototypes
        /**
        * @brief Virtual method definition for making the robot move up
        */
        virtual void GoUp(int x_, int y_)=0;
        /**
        * @brief Virtual method definition for making the robot move Down
        */
        virtual void GoDown(int x_, int y_)=0;
        /**
        * @brief Virtual method definition for making the robot move left
        */
        virtual void TurnLeft(int x_, int y_)=0;
        /**
        * @brief Virtual method definition for making the robot move right
        */
        virtual void TurnRight(int x_, int y_)=0;
        /**
        * @brief Virtual method definition for making the robot pick up an item
        */
        virtual void PickUp(std::string& pick)=0;
        /**
        * @brief Virtual method definition for making the robot release an item
        */
        virtual void Release(std::string& release)=0;
        /**
	    * @brief Virtual method definition for a getter for the robots X coordinate
        * @return The X coordinate value
	    */
        virtual int get_x() const=0;
        /**
	    * @brief Virtual method definition for a getter for the robots Y coordinate
        * @return The Y coordinate value
	    */
        virtual int get_y() const=0;
        /**
	    * @brief Virtual method definition for a setter for the robots X coordinate
	    */
        virtual void set_x(int x)=0;
        /**
	    * @brief Virtual method definition for a setter for the robots y coordinate
	    */
        virtual void set_y(int y)=0;
        /**
	    * @brief Constructor to initialise the attributes
         *@param Initialises name as none if no input is provided
         *@param Initialises X coordinate as 0 if no input is provided
         *@param Initialises Y coordinate as 0 if no input is provided
	    */
        //--Constructor
        LandBasedRobot(std::string name="none", int x=0, int y=0): name_{name}, x_{x}, y_{y}{
        }
        /**
	    * @brief Destructor to delete the object when it goes out of scope
	    */
        //-- destructor
        virtual ~LandBasedRobot(){}

    protected:
        /**
         * @brief Declaring attributes for LandBasedRobot
         * @param name_ stores the name of robot
         * @param speed_ stores Driving speed of the robot
         * @param length_ stores length of the base of the robot
         * @param height_ stores height of the base of the robot
         * @param capacity_ stores the payload of the robot
         * @param x_ stores the x coordinate of the robot in the maze
         * @param y_ stores the y coordinate of the robot in the maze
         */
        //--attributes
        std::string name_;
        double speed_;
        double width_;
        double length_;
        double height_;
        double capacity_;
        int x_;
        int y_;

    };//--class LandBasedRobot
}//--namespace rwa3