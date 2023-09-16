#!/usr/bin/env python

import rospy
import tf
from geometry_msgs.msg import Twist,Point,Quaternion
from math import pi
import PyKDL

class tf_listen_init():
    def __init__(self):
        rospy.init_node("tf_listen",anonymous=True)
        self.tf_listener=tf.TransformListener()
     #   self.cmd_vel=rospy.Publisher("/car/cmd_vel",Twist,queue_size=10)
        
     #   rospy.on_shutdown(self.shutdown)
        self.odom_frame="/map"
        self.base_frame="/base_footprint"
        
        while not rospy.is_shutdown():
            self.tf_listener.waitForTransform(self.odom_frame,self.base_frame,rospy.Time(),rospy.Duration(0.1))
            (trans1,rotation)=self.get_odom()
            print trans1
            print "-----------------\n",rotation
            rospy.sleep(0.02)
            

    def normalize_angle(self,angle):
        res = angle
        while res > pi:
            res -= 2.0 * pi
        while res < -pi:
            res += 2.0 * pi
        return res
        
    def get_odom(self):
	self.tf_listener.waitForTransform(self.odom_frame,self.base_frame,rospy.Time(),rospy.Duration(0.1))
        (trans,rot)=self.tf_listener.lookupTransform(self.odom_frame,self.base_frame,rospy.Time())
        return (Point(*trans),self.quat_to_angle(Quaternion(*rot)))
       
    def quat_to_angle(self,*quat):
        rot = PyKDL.Rotation.Quaternion(quat[0].x, quat[0].y, quat[0].z, quat[0].w)
        return rot.GetRPY()[2]
 
    #def shutdown(self):
    #    rospy.loginfo("bye")
    #    self.cmd_vel.publish(Twist())

if __name__=="__main__":
    tf_listen_init()




