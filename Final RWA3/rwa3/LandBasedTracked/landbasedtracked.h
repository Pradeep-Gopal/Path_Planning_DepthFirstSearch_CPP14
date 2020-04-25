/**
 * @class LandBasedTracked
 * @author Markose Jacob (UID 117000269), Pradeep Gopal (116885027), Rohit Thakur (115803282), Srikumar Muralidharan (UID 116950572)
 * @date 25 April 2020
 * @file landbasedtracked.h
 * @brief This is a concrete derived class from LandBasedRobot and contains the required methods, constructors, destructors and attributes
 */
#pragma once
#include <string>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"

namespace rwa3 {
    class LandBasedTracked : public LandBasedRobot {
    public:
        //--method prototypes
        /**
        * @brief Virtual method prototype for making the robot move up
        */
        virtual void GoUp(int x_, int y_) override;
        /**
        * @brief Virtual method prototype for making the robot move Down
        */
        virtual void GoDown(int x_, int y_) override;
        /**
        * @brief Virtual method prototype for making the robot move left
        */
        virtual void TurnLeft(int x_, int y_) override;
        /**
        * @brief Virtual method prototype for making the robot move right
        */
        virtual void TurnRight(int x_, int y_) override;
        /**
        * @brief Virtual method prototype for making the robot pick up an item
        */
        virtual void PickUp(std::string& pick) override;
        /**
        * @brief Virtual method prototype for making the robot release an item
        */
        virtual void Release(std::string& release) override;
        /**
	    * @brief Virtual method prototype for a getter for the robots X coordinate
        * @return The X coordinate value
	    */
        virtual int get_x() const override;
        /**
	    * @brief Virtual method prototype for a getter for the robots Y coordinate
        * @return The Y coordinate value
	    */
        virtual int get_y() const override;
        /**
	    * @brief Virtual method prototype for a setter for the robots X coordinate
	    */
        virtual void set_x(int x) override;
        /**
	    * @brief Virtual method prototype for a setter for the robots y coordinate
	    */
        virtual void set_y(int y) override ;

        /**
	    * @brief Deep copy constructor if we have to use raw pointers
	    */
        // Deep copy constructor
        LandBasedTracked(const LandBasedTracked &source):LandBasedTracked(
                source.name_,
                source.x_,
                source.y_,
                *source.track_type){}

        /**
	    * @brief Constructor to initialise the attributes
         *@param Initialises name as none if no input is provided
         *@param Initialises X coordinate as 0 if no input is provided
         *@param Initialises Y coordinate as 0 if no input is provided
         *@param Initialises t_type as flat if no input is provided
	    */
        //--Constructor
        LandBasedTracked(std::string name="None", int x=0, int y=0, std::string t_type="flat") : LandBasedRobot(name, x, y), track_type{nullptr} {
            std::shared_ptr<std::string> track_type {new std::string {t_type}};
        }
        /**
	    * @brief Destructor to delete the object when it goes out of scope
	    */
        //--Destructor
        virtual ~LandBasedTracked(){}
    protected:
        /**
         * @brief Additional attributes which are not present in LandBasedRobot
         * @param track_type stores the type of wheel
         */
        // --attributes
        std::shared_ptr<std::string> track_type;

    };//--class LandBasedTracked
}//--namespace rwa3
