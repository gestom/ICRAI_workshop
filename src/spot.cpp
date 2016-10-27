#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include "image_transport/image_transport.h"
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

//whenever we receive a message over the odom topic, this callback is activated
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	//HINT
	//msg->width  = WITDH  of the image in pixels
	//msg->height = HEIGHT of the image in pixels
	//msg->data[3*i+0] = red channel of ith pixel
	//msg->data[3*i+1] = green channel of ith pixel
	
	unsigned char r,g,b;
	int pixelCount = 0;
	for (int cnt = 0; cnt<msg->width*msg->height;cnt++)
	{
		r = msg->data[cnt*3+0];
		g = msg->data[cnt*3+1];
		b = msg->data[cnt*3+2];
		if (r > g + 100 && r > b +100) pixelCount++;
	}
	ROS_INFO("PXC: %i",pixelCount);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turn");
	ros::NodeHandle n;
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	/*special layer for image transport  */
	image_transport::ImageTransport imageTransport(n);
	image_transport::Subscriber subImage = imageTransport.subscribe("/camera/rgb/image_raw", 1, imageCallback);

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
