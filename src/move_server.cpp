#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include "image_transport/image_transport.h"
#include <sstream>
#include <tutorial/searchAction.h>
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<tutorial::searchAction> Server;
bool active = false;
bool atPosition = false;
bool objectFound = false;
float currentX,currentY,targetX,targetY,yaw,lastYaw;

void execute(const tutorial::searchGoalConstPtr& goal, Server* as)
{
	// Do lots of awesome groundbreaking robot stuff here
	targetX = goal->x;
	targetY = goal->y;
	active = true;
	atPosition = false;
	objectFound = false;
	usleep(200000);
	while (active == true) usleep(100000);
	tutorial::searchResult result;
	result.found = objectFound;
	
	if (objectFound) as->setSucceeded(result); else as->setAborted(result);
}
	  
  
/**
 * Make the robot turn a predefined angle that might be larger than 2pi
 */

//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	//robot rotation is in quaternions, we just need to retreve its yaw
	float yawAngle = tf::getYaw(msg.pose.pose.orientation);
	yaw = tf::getYaw(msg.pose.pose.orientation);
	currentX = msg.pose.pose.position.x;
	currentY = msg.pose.pose.position.y;
}

//whenever we receive a message over the odom topic, this callback is activated
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	//HINT
	//msg->width  = WITDH  of the image in pixels
	//msg->height = HEIGHT of the image in pixels
	//msg->data[3*i+0] = red channel of ith pixel
	//msg->data[3*i+1] = green channel of ith pixel
	if (atPosition){
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
		if (pixelCount > 1000){
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

	//form the twist command
	geometry_msgs::Twist command;
	command.angular.z = 0.2;

	while (ros::ok())
	{
		if (active)
		{
			if (atPosition){
				command.linear.x =  0;
				command.angular.z = 0.3;
				if (fabs(yaw-lastYaw) < 0.1) active = false;
				ROS_INFO("Robot angle is: %f %f",yaw,lastYaw);
			}else{
				float x = targetX - currentX;
				float y = targetY - currentY;
				float dx = x*cos(yaw)+y*sin(yaw);
				float dy = x*sin(yaw)-y*cos(yaw);

				command.linear.x =  dx*0.3;
				command.angular.z = -dy;
				if (sqrt(dx*dx+dy*dy) < 0.1){
				       	atPosition = true;
					lastYaw = yaw - 0.2;
				}
				ROS_INFO("Robot distance is: %f",sqrt(dx*dx+dy*dy));
			}
			commandRobot.publish(command);
		}
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
