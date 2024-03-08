#include <iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
 
class String
{
public:
	String(const char *str = NULL);	//ͨ�ù��캯��
	String(const String &str);		//�������캯��
	~String();						//��������

	String operator+(const String &str) const;	//����+
	String& operator=(const String &str);		//����=
	String& operator+=(const String &str);		//����+=
	bool operator==(const String &str) const;	//����==
	char& operator[](int n) const;				//����[]

	size_t size() const;		//��ȡ����
	const char* c_str() const;	//��ȡC�ַ���

	friend istream& operator >> (istream &is, String &str);//����
	friend ostream& operator<<(ostream &os, String &str);//���

private:
	char *data;		//�ַ���
	size_t length;	//����
};