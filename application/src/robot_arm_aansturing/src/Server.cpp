/*
 * Server.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Agit
 */


#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib_tutorials/AveragingAction.h>
#include <robot_arm_aansturing/positionAction.h>
#include <algorithm>
#include "RobotArm.hpp"
#include "Servo.hpp"

class Server
{
public:

  Server(std::string server_name="low_interface",std::string sub_topic = "write_low_interface") :
    as(nh, server_name, false),
    action_name(server_name),arm({
	Servo(0,-90,90,640,2360),
	Servo(1,-30,90,1800,800),
	Servo(2,0,135,680,1920),
	Servo(3,-90,90,630,2430),
	Servo(4,1,0,850,2300),
	Servo(5,-90,90,700,2400)
	}),noodStop(false),publishState(false)
  {
    //register the goal and feedback callbacks
    as.registerGoalCallback(boost::bind(&Server::goalCB, this));
    as.registerPreemptCallback(boost::bind(&Server::preemptCB, this));

    //subscribe to the data topic of interest
    sub = nh.subscribe(sub_topic, 1, &Server::handleMessage, this);
    as.start();
  }

  ~Server(void)
  {
  }

  void goalCB()
  {

	auto temp_goal = as.acceptNewGoal();
    time_ = temp_goal->time;
    angles = temp_goal->angles;

    ROS_INFO("time: %ld",time_);

    arm.gotoPosition(Task({angles.at(0),angles.at(1),angles.at(2),angles.at(3),angles.at(4),angles.at(5)},time_));

    publishState = true;
  }

  void preemptCB()
  {
    ROS_INFO("%s: Preempted", action_name.c_str());
    // set the action state to preempted
    //arm.stopRobot();
    as.setPreempted();
    noodStop=true;
//    result.arrived = false;
//    as.setAborted(result);
  }


  void runServer()
  {
	  ros::Rate r(10);
	  while(as.isActive() && publishState)
	  {
		  feedback.moving = arm.isArmMoving();
		  as.publishFeedback(feedback);
		  r.sleep();
		  if(!feedback.moving)
		  {
			  std::cout<<"succeeded"<<std::endl;
			  result.arrived = true;
			  as.setSucceeded(result);
			  publishState = false;
		  }
//		  if(!feedback.moving && !as.isPreemptRequested())
//		  {
//			  result.arrived=true;
//			  as.setSucceeded(result);
//		  }
	  }
	  if(noodStop)
	  {
		  ROS_INFO("STOP NU!!");
		  arm.stopRobot();
		  noodStop=false;
		  publishState = false;
	  }

  }

  void handleMessage(const std_msgs::UInt8 msg)
  {
//	  if(msg.data == 1)
//	  {
//		  arm.stopRobot();
//	  }
  }


protected:

  ros::NodeHandle nh;
  actionlib::SimpleActionServer<robot_arm_aansturing::positionAction> as; //action_server
  std::string action_name;
  unsigned long time_;
  std::vector<int,std::allocator<int>> angles;
  robot_arm_aansturing::positionFeedback feedback;
  robot_arm_aansturing::positionResult result;
  ros::Subscriber sub;
  RobotArm arm;
  bool noodStop;
  bool publishState;

};

