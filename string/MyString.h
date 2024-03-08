#include <iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
 
class String
{
public:
	String(const char *str = NULL);	//通用构造函数
	String(const String &str);		//拷贝构造函数
	~String();						//析构函数

	String operator+(const String &str) const;	//重载+
	String& operator=(const String &str);		//重载=
	String& operator+=(const String &str);		//重载+=
	bool operator==(const String &str) const;	//重载==
	char& operator[](int n) const;				//重载[]

	size_t size() const;		//获取长度
	const char* c_str() const;	//获取C字符串

	friend istream& operator >> (istream &is, String &str);//输入
	friend ostream& operator<<(ostream &os, String &str);//输出

private:
	char *data;		//字符串
	size_t length;	//长度
};