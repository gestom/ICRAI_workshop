#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include "image_transport/image_transport.h"
#include <sstream>
#include <tutorial/searchAction.h>
#include <actionlib/server/simple_action_server.h>

//TASK 7: create an action server that turns the robot around and searches for a target   

//HINT: very bare skeleton this time, but you should be able to combine the move_server.cpp and spot.cpp files

//1) the execute callback to start the robot activity 
//2) the odom  callback to monitor robot yaw in case the object is not visible 
//3) the image callback to analyse the incoming image for pixels of given color 
//4) the main loop with subscribers, publishers server definition etc. 

int main(int argc, char **argv)
{
	ros::init(argc, argv, "searchServer");
	ros::NodeHandle n;
	ros::Rate loop_rate(10);

	//ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	//ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);
	//image_transport::ImageTransport imageTransport(n);
	//image_transport::Subscriber subImage = imageTransport.subscribe("/camera/rgb/image_raw", 1, imageCallback);
	//Server server(n, "search", boost::bind(&execute, _1, &server), false);
	//server.start();
	geometry_msgs::Twist command;
	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
