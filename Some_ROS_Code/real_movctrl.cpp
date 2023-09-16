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
  ros::Rate loop_rate(30);
  cout<<"start!";
  //cmd_vel
  geometry_msgs::Twist cmdvel;
  cmdvel.linear.x=0;
  cmdvel.linear.y=0;
  cmdvel.linear.z=0;

	MYSQL ceshi; 
	mysql_init(&ceshi);   //初始化MYSQL变量
	MYSQL_RES *result; 
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i,id,delta_total,now_total,last_total,maxtotal;         
 	string timestamp;
 	float last_row,deltatime,time,dist,realvel;

	
	//连接MySQL数据库
 	ifconnect(&ceshi);


 	// lookupdb(&ceshi);
	// result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
	// num = mysql_num_fields(result);        //将结果集列数存放到num中
 	last_row=0;
 	last_total=0;
	maxtotal=5000;
 	//循环读取数据库信息
 	// cout<<"start!";
 	while(ros::ok())
 	{

 		lookupdb(&ceshi);                       //查询
 		result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
		num = mysql_num_fields(result);        //将结果集列数存放到num中
 		row = mysql_fetch_row(result);
 		
 		for(i=1;i<atoi(row[1]);i++)
 			row = mysql_fetch_row(result);

 		now_total=atoi(row[3]);
 		delta_total=now_total-last_total;
 		if(delta_total>0) //get run time
 		{
 			time=delta_total*0.02;
 		}else
 		{ 
 			time=(delta_total+maxtotal)*0.02; 
 		}

 		switch(atoi(row[1])) //当前移动方位
 		{
 			case 1: cmdvel.linear.x=0.5;break;
 			case 2: cmdvel.linear.x=-0.5;;break;
 			case 3: cmdvel.linear.z=1;break;
 			case 4: cmdvel.linear.z=-1;break;
 			default : cmdvel.linear.x=0;cmdvel.linear.z=0;
 		}
		dist=cmdvel.linear.x*time; //wei yi

 		chatter_pub.publish(cmdvel);
 		
    	loop_rate.sleep();

 	}

	// while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	// {
	// 	id=atoi(row[0]);
	// 	posimsg.pose.position.x=atof(row[1]);
	// 	posimsg.pose.position.y=atof(row[2]);
	// 	posimsg.pose.position.z=atof(row[3]);
	// 	// timestamp=row[4];
	// 	// cout<<" data:"<<posimsg.pose.position.x<<endl;
	// 	for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
	// 	{
	// 		cout << row[i]<< "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
	// 	}
	// 	cout <<"_______ " <<endl;
	// }


	// while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	// {
	// 	for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
	// 	{
	// 		cout << row[i]<< "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
	// 	}
	// 	cout << endl;
	// }


	mysql_free_result(result);     //释放结果集所占用的内存
	mysql_close(&ceshi);          //关闭与mysql的连接
    cout <<"ending"<<endl;
    return 0;

}
