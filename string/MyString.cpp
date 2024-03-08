#include "MyString.h"
String::String(const char *str)//ͨ�ù��캯��
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}
//�������캯����Ҫ������ơ�

String::String(const String &str)//�������캯��
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}
//����������Ҫ�����ڴ���ͷż����ȵĹ��㡣

String::~String()//��������
{
	delete[]data;
	length = 0;
}
//�����ַ����������㣬�������᷵��һ���µ��ַ�����

String String::operator+(const String &str) const//����+
{
	String newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}
//�����ַ�����ֵ���㣬��������ı�ԭ���ַ�����ֵ��Ϊ�˱����ڴ�й¶�������ͷ���ԭ��������ڴ�����������һ���ʵ���С���ڴ����µ��ַ�����

String& String::operator=(const String &str)//����=
{
	if (this == &str)	
		return *this;

	delete[]data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}
//�����ַ��� += ���������������������������Ľ�ϡ�

String& String::operator+=(const String &str)//����+=
{
	length += str.length;
	char *newData = new char[length + 1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[]data;
	data = newData;
	return *this;
}
//������ȹ�ϵ���㣬���ﶨ��Ϊ���������ӿ������ٶȡ�

inline bool String::operator==(const String &str) const//����==
{
	if (length != str.length)	return false;
	return strcmp(data, str.data) ? false : true;
}
//�����ַ��������������������һ���򵥵Ĵ�����������̫��ʱ�Զ���ȡ���һ���ַ���

inline char& String::operator[](int n) const//����[]
{
	if (n >= length) return data[length - 1]; //������
	else return data[n];
}
//����������ȡ˽�г�Ա�ĺ������ֱ��ȡ���Ⱥ�C�ַ�����

inline size_t String::size() const//��ȡ����
{
	return length;
}
//���������������������һ���㹻����ڴ�������������ַ������ٽ������ַ��������ɡ�����һ���Ƚϼ����ص�ʵ�֣����Ϻܶ�ֱ��is >> str.data�ķ����Ǵ���ģ���Ϊ����ȷ��str.data�Ĵ�С�ͼ���������ַ����Ĵ�С��ϵ��

istream& operator >> (istream &is, String &str)//����
{
	char tem[1000];  //�򵥵�����һ���ڴ�
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}
//��������������ֻ��򵥵�����ַ��������ݼ��ɡ�ע��Ϊ��ʵ������cout << a << b�����������������Ҫ��������������������Ҳ�����ơ�

ostream& operator<<(ostream &os, String &str)//���
{
	os << str.data;
	return os;
}
inline const char* String::c_str() const//��ȡC�ַ���
{
	return data;
}