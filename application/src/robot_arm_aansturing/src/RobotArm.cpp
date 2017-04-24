/*
 * RobotArm.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Agit
 */

#include "RobotArm.hpp"

#include <iostream>
#include <sstream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

RobotArm::RobotArm(std::initializer_list<Servo> sl,std::string serialPort,unsigned long baudrate) :
servo(sl)
{
    try
    {
        ser.setPort(serialPort);
        ser.setBaudrate(baudrate);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
    }

    if(ser.isOpen()) ROS_INFO_STREAM("Serial Port initialized");
    else ROS_ERROR_STREAM("Unable to open port ");
}

RobotArm::~RobotArm()
{
	// TODO Auto-generated destructor stub
}

void RobotArm::gotoPosition(const Task& aTask)
{
	if(servo.size() == aTask.angles.size())
	{
		std::ostringstream oss;
		for(unsigned short i = 0; i < servo.size(); ++i)
		{
			oss << servo.at(i).message(aTask.angles.at(i));
		}
		oss<<"T"<<aTask.time<<"\r";

		std::cout<<oss.str()<<std::endl;

		ser.write(oss.str());

	}
	else {
		throw std::runtime_error{"number of angles is not equal to available servo's"};
	}
}

bool RobotArm::isArmMoving()
{

	std::string carraige_return = "Q\r";
	ser.write(carraige_return);
	while(!ser.available());
    if(ser.available()){
        std_msgs::String result;
        result.data = ser.read(ser.available());
        std::cout<<result.data<<std::endl;
        if(result.data=="+")
        {
        	return true;
        }
    }
    return false;
}

void RobotArm::stopRobot()
{
	std::string stop_message = "STOP\r";
	ser.write(stop_message);
}
