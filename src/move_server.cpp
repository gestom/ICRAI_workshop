#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <tutorial/movetoAction.h>
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<tutorial::movetoAction> Server;
bool active = false;
float currentX,currentY,targetX,targetY,yaw,distance;

void execute(const tutorial::movetoGoalConstPtr& goal, Server* as)
{
	targetX = goal->x;
	targetY = goal->y;
	distance = 1000; 
	active = true;
	usleep(500000);
	tutorial::movetoFeedback feedback;
	while (active){
		feedback.distance = distance;
		as->publishFeedback(feedback);
		usleep(100000);
	}
	tutorial::movetoResult result;
	result.distance = distance;
	as->setSucceeded(result);
}
  
//whenever we receive a message over the odom topic, this callback is activated
void odomCallback(const nav_msgs::Odometry &msg)
{
	yaw = tf::getYaw(msg.pose.pose.orientation);
	currentX = msg.pose.pose.position.x;
	currentY = msg.pose.pose.position.y;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "movetoServer");
	ros::NodeHandle n;
	ros::Subscriber subOdom = n.subscribe("odom", 1, odomCallback);
	ros::Publisher commandRobot = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1000);

	ros::Rate loop_rate(10);
	Server server(n, "moveto", boost::bind(&execute, _1, &server), false);
	server.start();

	//form the twist command to turn the robot
	geometry_msgs::Twist command;

	while (ros::ok())
	{
		if (active)
		{
			float x = targetX - currentX;
			float y = targetY - currentY;
			float dx = x*cos(yaw)+y*sin(yaw);
			float dy = x*sin(yaw)-y*cos(yaw);

			command.linear.x =  dx*0.3;
			command.angular.z = -dy;
			distance = sqrt(dx*dx+dy*dy);
			if (distance < 0.1) active = false;
			commandRobot.publish(command);
		}
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
