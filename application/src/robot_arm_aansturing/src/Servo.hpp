/*
 * Servo.hpp
 *
 *  Created on: Mar 9, 2017
 *      Author: root
 */

#ifndef SRC_ROBOT_ARM_AANSTURING_SRC_SERVO_HPP_
#define SRC_ROBOT_ARM_AANSTURING_SRC_SERVO_HPP_

#include <string>

class Servo
{
public:
	Servo(unsigned char anId,double aLowAngle, double aHighAngle, unsigned short aLowPWM,
			unsigned short aHighPWM);
	virtual ~Servo();

	std::string message(double angle);
private:
	double map(double x, double  in_min, double  in_max, double  out_min, double  out_max);
	unsigned short getPWMPulse(double angle);
	const unsigned short id;
	const double lowAngle;
	const double highAngle;
	const unsigned short lowPWM;
	const unsigned short highPWM;
};


#endif /* SRC_ROBOT_ARM_AANSTURING_SRC_SERVO_HPP_ */
