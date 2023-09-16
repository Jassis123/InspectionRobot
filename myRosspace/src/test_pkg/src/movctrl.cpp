#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>
#include <mysql/mysql.h>
#include <geometry_msgs/Twist.h>
using namespace std;

void ifconnect(MYSQL *ceshi)
{
	if (mysql_real_connect(ceshi, "w.rdc.sae.sina.com.cn", "mlj1myy543","215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h", "app_garbagesorting", 3306, NULL, 0))  //连接到mysql
	{
		cout << "\n\t-----MySQL已连接----" << endl;
	}
	else cout<<"connect fail.."<<endl;
}

void lookupdb(MYSQL *ceshi)
{
	if (!mysql_query(ceshi, "SELECT * FROM velctrl"))   //若查询成功返回0，失败返回随机数
	{
		;//cout << "\n\t  ----查询成功----" << endl;
	}
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cmdctrl_node");
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = 
  //nh.advertise<std_msgs::String>("say_hello_world", 100);
  nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
  ros::Rate loop_rate(10);
  cout<<"start!";
  //cmd_vel
  geometry_msgs::Twist cmdvel;
  // cmdvel.linear.x=0.5;
  cmdvel.linear.y=0;
  cmdvel.linear.z=0;

	MYSQL ceshi; 
	mysql_init(&ceshi);   //初始化MYSQL变量
	MYSQL_RES *result; 
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i,id,delta_total;         
 	string timestamp;
 	float last_row,deltatime,t,s,realvel;
	//连接MySQL数据库
 	ifconnect(&ceshi);
 	last_row=0;
 	while(ros::ok())
 	{

 		lookupdb(&ceshi);                       //查询
 		result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
		num = mysql_num_fields(result);        //将结果集列数存放到num中
 		row = mysql_fetch_row(result);
 		
 		switch(atoi(row[1])) //当前移动方位
 		{
 			case 1: cmdvel.linear.x=0.3;break;
 			case 2: cmdvel.linear.x=-0.3;;break;
 			case 3: cmdvel.angular.z=1;break;
 			case 4: cmdvel.angular.z=-1;break;
 			default : cmdvel.angular.z=0;cmdvel.linear.x=0;cmdvel.linear.z=0;
 		}
		
 		chatter_pub.publish(cmdvel);
 		
    	loop_rate.sleep();

 	}

	mysql_free_result(result);     //释放结果集所占用的内存
	mysql_close(&ceshi);          //关闭与mysql的连接
    cout <<"ending"<<endl;
    return 0;

}
