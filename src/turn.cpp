#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <sstream>

//TASK 3: turn the robot 360 degrees
//HINT: subscribe to the relevant topic and use the robot's position callback to measure it's yaw  

//whenever we receive a message over the odom topic, this callback is triggered 
void odomCallback(const nav_msgs::Odometry &msg)
{
	//robot rotation is in quaternions, we just need to retreve its yaw
	ROS_INFO("Robot yaw: %f",tf::getYaw(msg.pose.pose.orientation));
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turn");
	ros::NodeHandle n;
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	ros::Rate loop_rate(10);

	//subscribing to the relevant topic
	ros::Subscriber subOdom = n.subscribe("GUESS", 1, odomCallback);

	//make the robot turn around
	geometry_msgs::Twist command;
	command.angular.z = 0.2;

	while (ros::ok() /* && turn not completed */)
	{
		commandRobot.publish(command);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
