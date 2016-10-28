#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include "image_transport/image_transport.h"
#include <sstream>
#include <tutorial/searchAction.h>
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<tutorial::searchAction> Server;
bool objectFound = false;
bool active = false;
float currentYaw,lastYaw,initialYaw,turnVal;

void execute(const tutorial::searchGoalConstPtr& goal, Server* as)
{
	currentYaw=lastYaw=initialYaw=turnVal=turnVal = 0;
	active = true;
	objectFound = false;
	usleep(500000);
	tutorial::searchFeedback feedback;
	while (active){
		feedback.percentComplete = turnVal/6.28*100.0;
		as->publishFeedback(feedback);
		usleep(100000);
	}
	tutorial::searchResult result;
	result.found = objectFound;
	as->setSucceeded(result);
}
	  
  
//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	lastYaw = currentYaw;
	currentYaw = tf::getYaw(msg.pose.pose.orientation);

	//calculate the total robot rotation
	float diff = currentYaw-lastYaw;
	if (diff > 0) turnVal+=diff;
}

//whenever we receive a message over the odom topic, this callback is activated
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	//HINT
	//msg->width  = WITDH  of the image in pixels
	//msg->height = HEIGHT of the image in pixels
	//msg->data[3*i+0] = red channel of ith pixel
	//msg->data[3*i+1] = green channel of ith pixel
	int pixelCount = 0;
	if (active){
		unsigned char r,g,b;
		pixelCount = 0;
		for (int cnt = 0; cnt<msg->width*msg->height;cnt++)
		{
			r = msg->data[cnt*3+0];
			g = msg->data[cnt*3+1];
			b = msg->data[cnt*3+2];
			if (r > g + 100 && r > b +100) pixelCount++;
		}
		if (pixelCount > 1000000){
			objectFound = true;
			active = false;
		}
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "searchServer");
	ros::NodeHandle n;
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	/*special layer for image transport  */
	image_transport::ImageTransport imageTransport(n);
	image_transport::Subscriber subImage = imageTransport.subscribe("/camera/rgb/image_raw", 1, imageCallback);

	ros::Rate loop_rate(10);
	Server server(n, "search", boost::bind(&execute, _1, &server), false);
	server.start();

	//form the twist command to turn the robot
	geometry_msgs::Twist command;
	command.angular.z = 0.2;

	while (ros::ok())
	{
		if (active)
		{
			ROS_INFO("Robot angle is: %f %f",currentYaw,turnVal);
			if (turnVal > 2*M_PI) active = false; 
			commandRobot.publish(command);
		}
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
