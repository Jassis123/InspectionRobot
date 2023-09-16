// #include "ros/ros.h"
// #include "std_msgs/String.h"
// #include "test_pkg/MsgTest.h"

// int main(int argc,char **argv)
// {
// 	ros::init(argc,argv,"my_talker");
// 	ros::NodeHandle n;
// 	ros::Publisher Msgtest_pub=n.advertise<test_pkg::MsgTest>("msgtest",100);
// 	ros::Rate loop_rate(10);
// 	test_pkg::MsgTest msg;
// 	int count=0;
// 	while(ros::0k())
// 	{
// 		msg.stamp=ros::Time::now();
// 		msg.data=count;
// 		ROS_INFO("send msg = %d", msg.stamp.sec);   // 显示stamp.sec消息
//     ROS_INFO("send msg = %d", msg.stamp.nsec);  // 显示stamp.nsec消息
//     ROS_INFO("send msg = %d", msg.data);        
//     	Msgtest_pub.publish(msg);
//     	loop_rate.sleep();
//     	++count;
// 	}
// 	return 0;
// }

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <test_pkg/MsgTest.h>
#include <geometry_msgs/PoseStamped.h>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "testpub_node");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = 
  //nh.advertise<std_msgs::String>("say_hello_world", 100);
  nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal",100);

  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  //while(!count)
  {
    // std_msgs::String msg;
    // std::stringstream ss;
    // ss << "hello world!" << count;
    // msg.data = ss.str();
    geometry_msgs::PoseStamped msg;
    msg.header.stamp=ros::Time::now();

    msg.header.frame_id="map";
    msg.pose.position.x=4.28;
    msg.pose.position.y=0.8;
    msg.pose.position.z=0.0;
    
    msg.pose.orientation.x=0;
    msg.pose.orientation.y=0;
    msg.pose.orientation.z=-0.109;
    msg.pose.orientation.w=0.99;

    //ROS_INFO("%d", msg.data);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
