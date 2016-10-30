# ICRAI 2016 ROS\STRANDS WORSKHOP
Speaker - Dr. Tomas Krajnick 

This is the repository for the ICRAI 2016 ROS\STRANDS workshop. The workshop will be divided into 4 sessions and will cover the following topics:
* ROS basics - topics, nodes, compilation 
* Odometry and position control 
* Image processing
* ROS action servers and launch files
* Occupancy grids, localization and planning 
* Topological maps in STRANDS 
* Frequency-based models using STRANDS 

You can read more about ROS at http://wiki.ros.org
You can read more about STRANDS at http://strands.acin.tuwien.ac.at/

## Installation

If you would like to bring your own laptop to the workshop, you are more than welcome to. We encourage that you do. 
You need to prepare your laptop for the workshop. 
You must have the following installed:
* Ubuntu 14.04 as the operating system. You can find it here http://releases.ubuntu.com/14.04/
You can create a bootable usb and do a dual boot install if you'd like. (Unetbootin is a good tool for this)
* Once ubuntu is installed you should install ROS Indigo http://wiki.ros.org/indigo/Installation/Ubuntu

Alternatively you could also use a virtual machine. You can use a software such as virtualbox (https://www.virtualbox.org/wiki/Downloads) or vmware. 
You can download an image of ubuntu with ros preinstalled here http://nootrix.com/software/ros-indigo-virtual-machine/


* Once ROS desktop is installed please also install the following packages using the terminal: 
` sudo apt-get install ros-indigo-turtlebot-simulator ros-indigo-turtlebot-apps ros-indigo-turtlebot-rviz-launchers git python-catkin-tools `

## Testing the installation. 
You can test the installation using the following in the terminal:

`roslaunch turtlebot_gazebo turtlebot_world.lauch`

You should be able to see a robot world with a black robot in it:

`roslaunch turtlebot_teleop turtlebot_keyboard.launch`

You should be able to see the robot moving when you press the keys mentioned in the terminal. 

If you would like you can also clone this repository using git: 

Create a new directory:

`mkdir -p icrai_ws/src`

`cd icrai_ws/src`


Clone the repository

`git clone https://github.com/gestom/ICRAI_workshop.git` 

Build the package

`cd ~/icrai_ws` or wherever you created the new directory 

`catkin init` 

`catkin build`




