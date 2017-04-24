/*
 * client_test.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: nico
 */

#include "ros/ros.h"
#include <robot_arm_aansturing/position.h>
#include <robot_arm_aansturing/command.h>

#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_position_task_test");

	ros::ServiceClient client;
	ros::NodeHandle n;

	if (argc == 8)
	{
		client = n.serviceClient<robot_arm_aansturing::position>(
				"add_position_task");

		robot_arm_aansturing::position pos;

		pos.request.time = atoi(argv[1]);
		pos.request.angles.push_back(atoi(argv[2]));
		pos.request.angles.push_back(atoi(argv[3]));
		pos.request.angles.push_back(atoi(argv[4]));
		pos.request.angles.push_back(atoi(argv[5]));
		pos.request.angles.push_back(atoi(argv[6]));
		pos.request.angles.push_back(atoi(argv[7]));
		std::cout << "Call ROS service" << std::endl;
		if (client.call(pos))
		{
			ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
		}
		else
		{
			ROS_ERROR("Failed to call service");
			return 1;
		}
	}
	else if (argc == 3)
	{
		client = n.serviceClient<robot_arm_aansturing::command>("command_task");

		robot_arm_aansturing::command pos;

		pos.request.time = atoi(argv[1]);
		pos.request.command = argv[2];
		std::cout << "Call ROS service" << std::endl;
		if (client.call(pos))
		{
			ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
		}
		else
		{
			ROS_ERROR("Failed to call service");
			return 1;
		}
	}
	else
	{
		ROS_INFO("usage: Time A1 A2 A3 A4 A5 A6 \n\r OR \n\r Time Command");
		return 1;
	}

	return 0;
}

