/*
 * Servo.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: nico
 */

#include "Servo.hpp"

Servo::Servo(const unsigned short anId, const unsigned short aMinAngle,
		const unsigned short aMaxAngle,
		unsigned short aPosition) :
		id(anId), minAngle(aMinAngle), maxAngle(aMaxAngle), position(aPosition)
{
	// TODO Auto-generated constructor stub

}

Servo::Servo(const Servo& aServo)
:id(aServo.id), minAngle(aServo.minAngle), maxAngle(aServo.maxAngle), position(aServo.position)
{
}

Servo::~Servo()
{
	// TODO Auto-generated destructor stub
}
