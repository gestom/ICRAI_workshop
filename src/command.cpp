#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system - these messages should cause movement of the robot
 */
//TASK 2: make the robot move using command line parameters
//HINT: have a look what is "geometry_msgs::Twist", fill the 'command' accordingly and publish it

int rate = 10;
float countDown, forwardVelocity,angularVelocity;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Rate loop_rate(rate);

	//initialise the publisher
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);

	//read the params from the command line
	forwardVelocity = atof(argv[1]);
	angularVelocity = atof(argv[2]);
	countDown = rate*atof(argv[3]);

	//this struct needs to be filled accordingly and published repeatedly in the main loop
	geometry_msgs::Twist command;	

	//continue until the given time elapses
	while (ros::ok() && countDown > 0)
	{
		ros::spinOnce();
		loop_rate.sleep();
		countDown--;
	}

	return 0;
}
