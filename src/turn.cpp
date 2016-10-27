#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <sstream>

/**
 * Make the robot turn a predefined angle that might be larger than 2pi
 */

//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	//robot rotation is in quaternions, we just need to retreve its yaw
	float yawAngle = tf::getYaw(msg.pose.pose.orientation);
	ROS_INFO("Robot angle is: %f",yawAngle);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turn");
	ros::NodeHandle n;
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	ros::Rate loop_rate(10);
	float angle = atof(argv[1]);

	//form the twist command
	geometry_msgs::Twist command;
	command.angular.z = 0.2;
	while (ros::ok())
	{
		commandRobot.publish(command);
		ros::spinOnce();
		loop_rate.sleep();
	}


	return 0;
}
// %EndTag(FULLTEXT)%
