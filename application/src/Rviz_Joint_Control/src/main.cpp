/*
 * main.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: rene
 *  A simple program that publishes messages to Jointstate to visualize robot movement.
 *  Only the forearm moves between 0 - 90 degrees. The degrees are converted to radian before send.
 *  Todo: receive messages from motion and send those to the Jointstate topic.
 *  Todo: Split into different header files.
 */

#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>


int main(int argc, char** argv) {
ros::init(argc, argv, "MoveJoint");
ros::NodeHandle n;
ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
tf::TransformBroadcaster broadcaster;
ros::Rate loop_rate(30);

const double degree = M_PI/180;
double rot4 = 90;

geometry_msgs::TransformStamped odom_trans;
sensor_msgs::JointState joint_state;
odom_trans.header.frame_id = "odom";
odom_trans.child_frame_id = "base_link";

joint_state.name.resize(7);
joint_state.position.resize(7);
joint_state.name[0] ="base_link2turret";
joint_state.name[1] ="turret2upperarm";
joint_state.name[2] ="upperarm2forearm";
joint_state.name[3] ="forearm2wrist";
joint_state.name[4] ="wrist2hand";
joint_state.name[5] ="gripper_left2hand";
joint_state.name[6] ="gripper_right2hand";

while (ros::ok()) {
    //update joint_state
	// update here with received radian
    joint_state.header.stamp = ros::Time::now();
    joint_state.position[0] = 0;
    joint_state.position[1] = 0;
    joint_state.position[2] = 0;
    joint_state.position[3] = rot4*degree;
    joint_state.position[4] = 0;
    joint_state.position[5] = 0;
    joint_state.position[6] = 0;

    // update transform
    // (moving in a circle with radius=2)
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.transform.translation.x = 0;
    odom_trans.transform.translation.y = 0;
    odom_trans.transform.translation.z = 0;
    odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0);

    //send the joint state and transform
    joint_pub.publish(joint_state);
    broadcaster.sendTransform(odom_trans);

    rot4 += 1;
    if (rot4 > 90) rot4 = 0;
    loop_rate.sleep();
}
return 0;
}


