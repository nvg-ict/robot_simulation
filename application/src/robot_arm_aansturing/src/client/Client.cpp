/*
 * Client.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: nico
 */

#include "Client.hpp"

Client::Client()
:ac("low_interface")

{
	  //ac("low_interface");
	  //boost::thread temp_t (&spinThread);
	  //t.swap(temp_t);

	  ROS_INFO("Waiting for action server to start.");
	  //ac.waitForServer();
}

Client::~Client()
{
	  // shutdown the node and join the thread back before exiting
	  ros::shutdown();
	  t.join();
}


/*static*/ Client& Client::getClient() {
	static Client c;
	return c;
}

bool Client::stop() {
	if(ac.isServerConnected())
	{
	  ac.cancelGoal();
	  //ac.cancelAllGoals();
	  return true;
	}
	return false;
}

bool Client::sendMessage(Task task) {
	  ROS_INFO("Action server started, sending goal.");
	  // send a goal to the action
	  robot_arm_aansturing::positionGoal goal;
	  goal.time = task.time;
	  goal.angles = {task.angles.at(0),task.angles.at(1),task.angles.at(2),task.angles.at(3),task.angles.at(4),task.angles.at(5)};

	  //goal.angles = {0,-30,100,0,1,0};

	  ac.sendGoal(goal);
	  //wait for the action to return
	  /**
	   * TODO check what happens when the goal is canceled
	   */
	  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

	  if (finished_before_timeout)
	  {
	    actionlib::SimpleClientGoalState state = ac.getState();
	    ROS_INFO("Action finished: %s",state.toString().c_str());
	  }
	  else
	  {
	    ROS_INFO("Action did not finish before the time out.");
	  }
	  return true;
}
