#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include "image_transport/image_transport.h"
#include <sstream>

//TASK 4: try to search for a green object in the robot's surrounding
//HINT: count the number of green pixels in the image

float currentYaw,lastYaw,initialYaw,turnVal;
bool objectSpotted = false;

//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	lastYaw = currentYaw;
	//robot rotation is in quaternions, we just need to retreve its yaw
	currentYaw = tf::getYaw(msg.pose.pose.orientation);

	//calculate the total robot rotation
	float diff = currentYaw-lastYaw;
	if (diff > 0) turnVal+=diff;
	ROS_INFO("Robot angle is: %f %f",currentYaw,turnVal);
}

//whenever we receive a message over the odom topic, this callback is activated
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	//HINT
	//msg->width  = WITDH  of the image in pixels
	//msg->height = HEIGHT of the image in pixels
	//msg->data[3*i+0] = red channel of ith pixel
	//msg->data[3*i+1] = green channel of ith pixel
}

int main(int argc, char **argv)
{
	currentYaw=lastYaw=initialYaw=0;
	ros::init(argc, argv, "turn");
	ros::NodeHandle n;
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);

	/*special layer for image transport*/
	image_transport::ImageTransport imageTransport(n);
	image_transport::Subscriber subImage = imageTransport.subscribe("/camera/rgb/image_raw", 1, imageCallback);

	ros::Rate loop_rate(10);

	//form the twist command
	geometry_msgs::Twist command;
	command.angular.z = 0.2;

	while (ros::ok() && turnVal < 2*M_PI && objectSpotted == false)
	{
		commandRobot.publish(command);
		ros::spinOnce();
		loop_rate.sleep();
	}


	return 0;
}
