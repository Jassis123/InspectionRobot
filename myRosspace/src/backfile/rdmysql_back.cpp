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
	if (!mysql_query(ceshi, "SELECT * FROM MyGuests"))   //若查询成功返回0，失败返回随机数
	{
		cout << "\n\t  ----查询成功----" << endl;
	}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rdmysql_node");
  ros::NodeHandle nh;

  ros::Rate loop_rate(10);

  geometry_msgs::PoseStamped posimsg;

	MYSQL ceshi; 
	mysql_init(&ceshi);   //初始化MYSQL变量
	MYSQL_RES *result; 
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i,id;         
 
 	string timestamp;
 
 	ifconnect(&ceshi);
 // 	if (mysql_real_connect(&ceshi, "w.rdc.sae.sina.com.cn", "mlj1myy543","215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h", "app_garbagesorting", 3306, NULL, 0))  //连接到mysql
	// {
	// 	cout << "\n\t-----MySQL已连接----" << endl;
	// }

	// if (mysql_real_connect(&ceshi, "127.0.0.1", "ljs","123456", "testsql", 3306, NULL, 0))  //连接到mysql
	// {
	// 	cout << "\n\t-----MySQL已连接----" << endl;
	// }
	// else cout<<"fail.."<<endl;

 	lookupdb(&ceshi);
	// if (!mysql_query(&ceshi, "SELECT * FROM MyGuests"))   //若查询成功返回0，失败返回随机数
	// {
	// 	cout << "\n\t  ----查询成功----" << endl;
	// }
 
	result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
	num = mysql_num_fields(result);        //将结果集列数存放到num中
 
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		id=atoi(row[0]);
		posimsg.pose.position.x=atof(row[1]);
		posimsg.pose.position.y=atof(row[2]);
		posimsg.pose.position.z=atof(row[3]);
		// timestamp=row[4];
		// cout<<" data:"<<posimsg.pose.position.x<<endl;
		for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i]<< "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout <<"_______ " <<endl;
	}


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
    

}
