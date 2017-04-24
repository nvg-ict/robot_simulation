/*
 * Servo.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: root
 */

#include "Servo.hpp"

#include <iostream>
#include <sstream>

Servo::Servo(unsigned char anId,double aLowAngle, double aHighAngle, unsigned short aLowPWM,
		unsigned short aHighPWM)
: id(anId), lowAngle(aLowAngle), highAngle(aHighAngle), lowPWM(aLowPWM), highPWM(aHighPWM)
{
}

Servo::~Servo()
{
}


unsigned short Servo::getPWMPulse(double angle)
{
	//double value1 = map(angle,-30,90,1885,800);
	double value = map(angle,lowAngle,highAngle,lowPWM,highPWM);
	return value;
}

std::string Servo::message(double angle)
{
	short PWM = getPWMPulse(angle);

	std::ostringstream oss;
	oss << "#" << id << "P" << PWM;

	return oss.str();
}

double Servo::map(double x, double  in_min, double  in_max, double  out_min, double  out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
