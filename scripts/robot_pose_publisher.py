#!/usr/bin/env python

import rospy

#import rostopic
#from actionlib_msgs.msg import *
#from move_base_msgs.msg import *
from geometry_msgs.msg import Pose
from geometry_msgs.msg import PoseWithCovarianceStamped
#from nav_msgs.msg import Odometry
#from std_msgs.msg import String




class robot_pose_pub(object):
       
    
    def __init__(self, name) :

        self.rp_pub = rospy.Publisher('/robot_pose', Pose, latch=True, queue_size=1)
       
        rospy.Subscriber('/amcl_pose', PoseWithCovarianceStamped, self.PoseCallback)
        rospy.sleep(rospy.Duration.from_sec(0.1))
        
        rospy.loginfo("All Done ...")
        rospy.spin()


    def PoseCallback(self, msg):
        self.current_pose = msg
        self.publish(self.current_pose.pose.pose)
 

    def publish(self, msg) :
        self.rp_pub.publish(msg)



if __name__ == '__main__':
    rospy.init_node('robot_pose_pub')
    server = robot_pose_pub(rospy.get_name())
