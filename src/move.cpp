#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <sstream>

//TASK 5: make the robot move to a predefined position
//HINT : calculate relative pose of the target position to the robot position and set robot commands proportionally 

float currentX,currentY,targetX,targetY,yaw;

//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	//robot rotation is in quaternions, we just need to retreve its yaw
	yaw = tf::getYaw(msg.pose.pose.orientation);
	ROS_INFO("Robot angle is: %f",yaw);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "move");
	ros::NodeHandle n;

	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	ros::Rate loop_rate(10);
	targetX = atof(argv[1]);
	targetY = atof(argv[2]);

	//subscriber to the odometry topic
	ros::Subscriber subOdom = n.subscribe("/odom", 1, odomCallback);

	//form the twist command
	geometry_msgs::Twist command;
	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}


	return 0;
}
// %EndTag(FULLTEXT)%
