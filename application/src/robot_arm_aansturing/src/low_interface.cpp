/*
 * low_interface.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Agit
 */
#include "ros/ros.h"
//#include "robot_arm_aansturing/Test.h"
#include "SerialComm.hpp"
#include <exception>
#include <iostream>


int main(int argc, char* argv[])
{

    try
    {
            if (argc != 3)
            {
                    std::cerr << "Usage: SerialComm_Node <baud> <device>\n"; //bijv: 9600 /dev/ttyACM0
                    return 1;
            }
            //ros::init(argc, argv, "serialcomm_server");
            //ros::NodeHandle n;
            boost::asio::io_service io_service;
            std::string usb = "/dev/ttyUSB0";
            SerialComm client(io_service, boost::lexical_cast<unsigned long>(argv[1]), usb);
            //std::string message ="nice_meme123\n";
            std::string message ="#0P1300T3000\r";
            //ROS_INFO("Ready to communicate with Robot");

			client.write_message(message);
			//client.read_start();
            sleep(5);
			client.close(); // close the serialComm client connection

			//ros::spin();

    }
	catch (std::exception& e)
	{
			std::cerr << "Exception: " << e.what() << "\n";
	}
    return 0;
}



