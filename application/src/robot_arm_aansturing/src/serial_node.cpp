/*
 * serial_node.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: Agit
 */

#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <actionlib/server/simple_action_server.h>
#include <robot_arm_aansturing/positionAction.h>
#include "Server.cpp"

void spinThread()
{
  ros::spin();
}

int main (int argc, char** argv){
    ros::init(argc, argv, "serial_node");

    Server server;
    boost::thread spin_thread(&spinThread);
    while(ros::ok())
    {
    	server.runServer();
    }
    spin_thread.join();
}

