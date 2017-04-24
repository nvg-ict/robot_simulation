/*
 * Servo.hpp
 *
 *  Created on: Mar 4, 2017
 *      Author: nico
 */

#ifndef SERVO_HPP_
#define SERVO_HPP_

class Servo
{
public:
	Servo(const unsigned short anId, const unsigned short aMinAngle,
			const unsigned short aMaxAngle, unsigned short aPosition);
	Servo(const Servo& aServo);
	virtual ~Servo();
private:
	const unsigned short id;
	const unsigned short minAngle;
	const unsigned short maxAngle;
	unsigned short position;
};

#endif /* SERVO_HPP_ */
