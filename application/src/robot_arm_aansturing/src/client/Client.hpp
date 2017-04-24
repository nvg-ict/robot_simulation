/*
 * Client.hpp
 *
 *  Created on: Mar 9, 2017
 *      Author: nico
 */

#ifndef SRC_ROBOT_ARM_AANSTURING_SRC_CLIENT_CLIENT_HPP_
#define SRC_ROBOT_ARM_AANSTURING_SRC_CLIENT_CLIENT_HPP_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_tutorials/AveragingAction.h>
#include <robot_arm_aansturing/positionAction.h>
#include <boost/thread.hpp>

#include "ArmContol.hpp"

class Client
{
public:
	/**
	 * @brief Getter for the singleton instance
	 * @return
	 */
	static Client& getClient();
	virtual ~Client();
	/**
	 * @brief Function that will send a task to the low level interface
	 * @param task The task that needs to be sent
	 * @return true when message has been succesfully sent
	 */
	bool sendMessage(Task task);
	/**
	 * @brief This function will stop the goal and thus execute an emergency stop
	 * @return true if the emergency stop can be executed
	 */
	bool stop();
private:
	/**
	 * Private constructor
	 */
	Client();

	actionlib::SimpleActionClient<robot_arm_aansturing::positionAction> ac;
	boost::thread t;

};

#endif /* SRC_ROBOT_ARM_AANSTURING_SRC_CLIENT_CLIENT_HPP_ */
