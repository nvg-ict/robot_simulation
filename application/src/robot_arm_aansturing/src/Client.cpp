#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_tutorials/AveragingAction.h>
#include <robot_arm_aansturing/positionAction.h>
#include <boost/thread.hpp>

void spinThread()
{
  ros::spin();
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_low_interface");

  actionlib::SimpleActionClient<robot_arm_aansturing::positionAction> ac("low_interface");
  boost::thread spin_thread(&spinThread);

  ROS_INFO("Waiting for action server to start.");
  ac.waitForServer();

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  robot_arm_aansturing::positionGoal goal;
  goal.time = 10000;
  goal.angles = {0,-30,100,0,1,0};

  //goal.time = 4000;
 // goal.angles = {45,45,0,0,0,0};
  //4000
  //{0,-30,100,0,1,0};
  ac.sendGoal(goal);
  //wait for the action to return
  //bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));
  bool finished_before_timeout = ac.waitForResult(ros::Duration(2.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
  {
    ROS_INFO("Action did not finish before the time out.");
    //ac.cancelAllGoals();
    ac.cancelGoal();
  }

  // shutdown the node and join the thread back before exiting
  ros::shutdown();
  spin_thread.join();

  //exit
  return 0;
}
