#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	ros::Rate loop_rate(10);

	//establish the countdown to determine how long time the robot is supposed to move
	float count = 10*atof(argv[3]);
	//form the twist command
	geometry_msgs::Twist command;
	//forward speed
	command.linear.x = atof(argv[1]);
	//turning speed
	command.angular.z = atof(argv[2]);
	//continue publishing until the given time elapses
	while (ros::ok() && count > 0)
	{
		commandRobot.publish(command);
		ros::spinOnce();
		loop_rate.sleep();
		count--;
	}


	return 0;
}
// %EndTag(FULLTEXT)%
