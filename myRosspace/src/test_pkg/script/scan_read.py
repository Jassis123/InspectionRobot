#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan

def callback(scan):
#    rospy.loginfo(scan.range_max)
    print "lllllllllllllllllllllllllll"
    an=list(scan.ranges)
    for i in range(-5,5): 
        if an[i]>8:
            an[i]=8
	print "%d\t"%i
	print "\n"
    	print "\t",an[i]
	print "\n"
    rospy.spin()
    
def listener():
    rospy.init_node('laser_read')
    #while not rospy.is_shutdown():
    print "start!"
    rospy.Subscriber('/scan',LaserScan,callback)
    rospy.spin()
    
if __name__=="__main__":
    listener()


