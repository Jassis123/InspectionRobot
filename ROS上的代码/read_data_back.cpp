#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;


template<class  T,class T2>
void myadd(T a, T2 b)
{
cout << typeid(T).name() << endl;
 cout << typeid(T2).name() << endl;
}


float strtofloat(char* data)
{
  float num=0;
  // int count=0;
  int x=10;
  char *str;
  str=data;
  // cout<<data<<endl;
  while('0'<=*str<='9')
  {
    // cout<< "1:"<<*str<<endl;
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
      // cout<< "2:"<<(float(*str)-48)/x<<endl;
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
void readTxt(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流 
}

int main()
{
    string data;
    char *chr;
    float num;
    //以二进制模式打开 in.txt 文件
     // 以读模式打开文件
   ifstream infile; 
   infile.open("POS.txt"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data;

    // chr = &data[0];
    // myadd(*chr,data[0]);
    // chr+=1;
   // 在屏幕上写入数据
   // cout << data << endl;
    num=strtofloat(chr);
   // cout<<num<<endl;
   cout<<"aaa"<<endl;
   data="123.111";
   chr=&data[0];
   cout<<strtofloat(chr);

   // 再次从文件读取数据，并显示它
   // infile >> data; 
   // cout << data << endl; 
 
   // infile >> data; 
   // cout << data << endl; 

   // 关闭打开的文件
   infile.close();
   
  readTxt("POS.txt");

    // string str;
    // str="11.2";
    // chr=&str[0];
    // // *chr='a';
    // cout<<&str[0]<<endl;
    return 0;

}