#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <tutorial/movetoAction.h>
#include <tutorial/searchAction.h>

//TASK 7: Create a node that makes the robot search through the flat using the move_server and spot_server  

float x[] = { 1.0, 1.0, 0.5, 0.5, 0.5, 2.5, 3.8, 4.2, 3.8, 2.8, 2.8, 4.8, 2.8,  3.0, 3.2, 2.8, 2.8, 1.0, 0.8,  1.0};
float y[] = { 0.0, 1.0, 2.5, 3.5, 5.0, 5.5, 5.2, 3.0, 2.0, 1.5, 0.0, 0.0, 0.0, -2.5,-2.5,-1.5,-0.5,-0.5,-2.0, -0.5};
int s[] =   { 	1,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,    1,   0,   0,   0,   0,   1,   0};
int steps = 60;

int main (int argc, char **argv)
{
	ros::init(argc, argv, "robotMove");

	//create the action client
	actionlib::SimpleActionClient<tutorial::movetoAction> moveAc("moveto", true);
	actionlib::SimpleActionClient<tutorial::searchAction> searchAc("search", true);

	ROS_INFO("Waiting for action server to start.");
	// wait for the action server to start
	moveAc.waitForServer(); //will wait for infinite time
	ROS_INFO("Waiting for action server to start.");
	searchAc.waitForServer(); //will wait for infinite time

	ROS_INFO("Action servers started, sending goal.");
	// send a goal to the action
	tutorial::movetoGoal goal;
	tutorial::searchGoal sg;
	bool OK = true; 
	for (int i = 0;i<steps;i++){
		int index = i%20;
		goal.x = x[index];
		goal.y = y[index];
		ROS_INFO("Next goal %f %f.",goal.x,goal.y);
		moveAc.sendGoal(goal);
		OK = moveAc.waitForResult(ros::Duration(30.0));
		if (s[index] == 1){
			searchAc.sendGoal(sg);
			OK = searchAc.waitForResult(ros::Duration(30.0));
		}
	}

	if (OK)
	{
		actionlib::SimpleClientGoalState state = moveAc.getState();
		ROS_INFO("Action finished: %s",state.toString().c_str());
	}
	else
	{
		ROS_INFO("Action did not finish before the time out.");
	}
	return 0;
}
