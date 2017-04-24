/*
 * main.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: nico
 */

#include <ros/ros.h>
#include <robot_arm_aansturing/position.h>
#include <robot_arm_aansturing/command.h>

#include "Servo.hpp"
#include "RobotArm.hpp"

#include <iostream>
#include <thread>

#include "ArmContol.hpp"
#include "Client.hpp"


/**
 * @brief Function gets called as callback when the add position service is used
 * @param req Reference of the request from the service
 * @param res Reference of the response for the service
 * @return true when callback is handled
 */
bool addTaskToList(robot_arm_aansturing::position::Request &req,
		robot_arm_aansturing::position::Response &res)
{
	std::vector<short> a;
	for(unsigned short i = 0; i<req.angles.size();++i)
	{
		a.push_back(req.angles.at(i));
	}
	Task task(a, req.time);

	std::cout << "Task" << std::endl;
	if (task.validateTask())
	{
		ArmContol::getArmContol().addTask(task);
		res.accepted = true;
		ROS_INFO("Task recieved");
	}
	else
		res.accepted = false;

	return true;
}

/**
 * @brief Function gets called as callback when the command service is used
 * @param req Reference of the request from the service
 * @param res Reference of the response for the service
 * @return true when callback is handled
 */
bool addCommandToTaskList(robot_arm_aansturing::command::Request &req,
		robot_arm_aansturing::command::Response &res)
{
	//Task task;
	if (req.command == "READY")
	{
		Task task(
		{ 0, -30, 110, 0, 0, 0 }, req.time);
		ArmContol::getArmContol().addTask(task);
		res.accepted = true;
	}
	else if(req.command == "PARK")
	{
		Task task(
		{ 0, -30, 110, -90, 0, 0 }, req.time);
		ArmContol::getArmContol().addTask(task);
		res.accepted = true;
	}
	else if(req.command == "STRAIGHT-UP")
	{
		Task task(
		{ 0, 0, 0, 0, 0, 0 }, req.time);
		ArmContol::getArmContol().addTask(task);
		res.accepted = true;
	}
	else if(req.command == "STOP")
	{
		res.accepted = Client::getClient().stop();
	}
	else {
		res.accepted = false;
	}

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_low_interface");
	//Call singleton first time to start up action client
	Client::getClient();

	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("add_position_task",
			addTaskToList);
	ros::ServiceServer service2 = n.advertiseService("command_task",
			addCommandToTaskList);

	std::thread t(
			[]()
			{	RobotArmContext rAC(
						{	Servo(0, 10, 100, 0.102), Servo(0, 10, 100, 0.102), Servo(0, 10,
									100, 0.102), Servo(0, 10, 100, 0.102), Servo(0, 10, 100,
									0.102), Servo(0, 10, 100, 0.102)});});
	ros::spin();

	t.join();

	return 0;
}

