/*
 * RobotArm.hpp
 *
 *  Created on: Mar 7, 2017
 *      Author: nico
 */

#ifndef ROBOTARM_HPP_
#define ROBOTARM_HPP_

#include <queue>
#include <vector>
#include <initializer_list>

#include "Servo.hpp"

struct Task;

class RobotArm
{
public:
	RobotArm(std::initializer_list<Servo> sl);
	virtual ~RobotArm();
	/**
	 * @brief Function that will set a robotarm to a position
	 * @param aTask The task will hold the position to which the servo's should be set.
	 */
	void gotoPosition(const Task& aTask);
private:
	std::vector<Servo> servo;
};

#endif /* ROBOTARM_HPP_ */
