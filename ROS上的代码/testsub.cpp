#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <test_pkg/MsgTest.h>

using namespace std;

void msgCallback(const geometry_msgs::PoseStamped& msg)
{

	ROS_INFO("receive msg_x=%f",msg.pose.position.x);

}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"testsub_node");
	ros::NodeHandle nh;
	ros::Subscriber testnode_sub=nh.subscribe("move_base_simple/goal",100,msgCallback);
	ros::spin();

	return 0;
}



