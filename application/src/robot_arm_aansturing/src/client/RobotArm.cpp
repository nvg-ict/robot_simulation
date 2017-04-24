/*
 * RobotArm.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: nico
 */

#include "RobotArm.hpp"
#include <iostream>

RobotArm::RobotArm(std::initializer_list<Servo> sl) :
servo(sl)
{
}

RobotArm::~RobotArm()
{
}


/*
void RobotArm::gotoPosition(const Task& aTask)
{
	if(servo.size() == aTask.angles.size())
	{
		std::cout<<"Task added" <<std::endl;
		//If the task meets requirements, push it in the task list.
		taskList.push(aTask);
	}
	else {
		throw;
	}
}

*/
