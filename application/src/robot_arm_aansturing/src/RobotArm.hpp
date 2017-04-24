/*
 * RobotArm.hpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Agit
 */

#ifndef SRC_ROBOT_ARM_AANSTURING_SRC_ROBOTARM_HPP_
#define SRC_ROBOT_ARM_AANSTURING_SRC_ROBOTARM_HPP_

#include <vector>
#include <initializer_list>

#include "Servo.hpp"
#include <serial/serial.h>

struct Task;

class RobotArm
{
public:
	RobotArm(std::initializer_list<Servo> sl,std::string serialPort ="/dev/ttyUSB0",unsigned long baudrate = 115200 );
	virtual ~RobotArm();
	void gotoPosition(const Task& aTask);
	bool isArmMoving();
	void stopRobot();
private:
	std::vector<Servo> servo;
	serial::Serial ser;
};

struct Task
{
	Task(std::initializer_list<short> al, unsigned long aTime):
	angles(al), time(aTime)
	{

	}

	Task(const std::vector<short>& al, unsigned long aTime):
	angles(al), time(aTime)
	{

	}
	virtual ~Task(){}

	std::vector<short> angles;
	unsigned long time;
};

#endif /* SRC_ROBOT_ARM_AANSTURING_SRC_ROBOTARM_HPP_ */
