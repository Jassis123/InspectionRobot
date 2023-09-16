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

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include <mysql/mysql.h>

float str2float(char* data)
{
  float num=0;
  // int count=0;
  int x=10;
  char *str;
  str=data;
  // cout<<data<<endl;
  while('0'<=*str<='9')
  {
    std::cout<< "1:"<<*str<<std::endl;
    if(*str=='.')
    {
      //
      break;
    }
    num*=10;
    num+=int(*str)-48;
    str++;
  }
  if(*str=='.')
  {
    str++;
    while('0'<=*str<='9')
    {
      std::cout<< "2:"<<(float(*str)-48)/x<<std::endl;
      num+=(float(*str)-48)/x;
      x*=10;
      str++;
      if(*str=='\0') break;
    }
  }
  str=data;
  // cout <<num<<endl;
  return num;
}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "movpub_node");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = 
  //nh.advertise<std_msgs::String>("say_hello_world", 100);
  nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal",10);

  ros::Rate loop_rate(10);
  int count = 0;
  

  char *data;
  std::string str;
  float num;
  std::ifstream infile; 
  while (ros::ok())
  {
   
    // infile.open("/home/ljs/myRosspace/src/test_pkg/src/POS.txt"); 
    //  if (!infile.is_open())
    // {
    //     std::cout << "打开文件失败" << std::endl;
    //     return 0;
    // }
    geometry_msgs::PoseStamped msg;
    // std::cout << "Reading from the file" << std::endl; 
    // std::string buf;
    // infile>>num;
    // msg.pose.position.x=num;
    // infile>>num;
    // msg.pose.position.y=num;
    // infile>>num;
    // msg.pose.position.z=num;

   // 关闭打开的文件
    // infile.close();

    msg.header.stamp=ros::Time::now();

    msg.header.frame_id="map";
    msg.pose.position.x=-1.629;
    msg.pose.position.y=-0.457;
    msg.pose.position.z=0.0;
    
    msg.pose.orientation.x=0;
    msg.pose.orientation.y=0;
    msg.pose.orientation.z=-0.542;
    msg.pose.orientation.w=0.840;

    // std::cout<<msg<<std::endl;
    chatter_pub.publish(msg);
    // ros::spinOnce();
    loop_rate.sleep();

  }
  // geometry_msgs::PoseStamped msg;
  // msg.header.stamp=ros::Time::now();

  //   msg.header.frame_id="map";
  //   msg.pose.position.x=-1.12;
  //   msg.pose.position.y=2.887;
  //   msg.pose.position.z=0.0;
    
  //   msg.pose.orientation.x=0;
  //   msg.pose.orientation.y=0;
  //   msg.pose.orientation.z=-0.595;
  //   msg.pose.orientation.w=0.8035;

  //   // std::cout<<msg<<std::endl;
  //   chatter_pub.publish(msg);
  return 0;
}
