#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>
#include <mysql/mysql.h>
#include <geometry_msgs/PoseStamped.h>
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
	if (!mysql_query(ceshi, "SELECT * FROM CarPos"))   //若查询成功返回0，失败返回随机数
	{
		;//cout << "\n\t  ----查询成功----" << endl;
	}else
	{
		cout<<"查询 fail!"<<endl;
	}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rdmysql_node");
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = 
  //nh.advertise<std_msgs::String>("say_hello_world", 100);
  nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal",10);
  ros::Rate loop_rate(10);

  geometry_msgs::PoseStamped posimsg;
  posimsg.header.frame_id="map";
  posimsg.pose.orientation.x=0;
  posimsg.pose.orientation.y=0;
  // posimsg.pose.orientation.z=-0.109;
  // posimsg.pose.orientation.w=0.99;

	MYSQL ceshi; 
	mysql_init(&ceshi);   //初始化MYSQL变量
	MYSQL_RES *result; 
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i,id;         
 	string timestamp;
 	double last_row,now_row;
 	ifconnect(&ceshi);

 	// cout<<"a"<<endl;
 	// lookupdb(&ceshi);
	// result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
	// num = mysql_num_fields(result);        //将结果集列数存放到num中
 	last_row=0;
 	while(ros::ok())
 	{
 		// cout<<"b"<<endl;
 		lookupdb(&ceshi);
 		result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
		num = mysql_num_fields(result);        //将结果集列数存放到num中
 		row = mysql_fetch_row(result);
 		// row = mysql_fetch_row(result);  //2 times
 		
 		now_row=atof(row[1]);
 		// cout<<"now_row:"<<now_row<<endl;
 		if(abs(last_row-now_row)>0.1)
 		{
 			cout<<"d"<<endl;

 			id=atoi(row[0]);
			posimsg.pose.position.x=atof(row[3]);
			posimsg.pose.position.y=-atof(row[1]);
			// posimsg.pose.position.z=atof(row[2]);
			posimsg.pose.position.z=0.0;
			posimsg.pose.orientation.z=sin(atof(row[5])/2.0);
  			posimsg.pose.orientation.w=cos(atof(row[5])/2.0);
				// timestamp=row[4];
				// cout<<" data:"<<posimsg.pose.position.x<<endl;
			for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
			{
				cout << row[i]<< "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
			}
			cout <<"\n_______ \n" <<endl;
			last_row=now_row;
			cout<<"now_row:"<<now_row;
 			cout <<"pub!"<<endl;
 			chatter_pub.publish(posimsg);
    		
 		// 	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
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
			// 	last_row=atof(row[1]);
			// }
 		}
 		// ros::spinOnce();
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
