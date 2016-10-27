#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <sstream>

/**
 * Make the robot turn a predefined angle that might be larger than 2pi
 */
float currentX,currentY,targetX,targetY,yaw;

//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	//HINT - calculate relative pose of the target position to the robot position
	
	
	//robot rotation is in quaternions, we just need to retreve its yaw
	yaw = tf::getYaw(msg.pose.pose.orientation);
	ROS_INFO("Robot angle is: %f",yaw);
	currentX = msg.pose.pose.position.x;
	currentY = msg.pose.pose.position.y;
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
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);

	//form the twist command
	geometry_msgs::Twist command;
	while (ros::ok())
	{
		float x = targetX - currentX;
		float y = targetY - currentY;

		float dx = x*cos(yaw)+y*sin(yaw);
		float dy = x*sin(yaw)-y*cos(yaw);

		command.linear.x =  dx*0.3;
		command.angular.z = -dy;
		commandRobot.publish(command);
		ros::spinOnce();
		loop_rate.sleep();
	}


	return 0;
}
// %EndTag(FULLTEXT)%
