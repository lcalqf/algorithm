#include <iostream>
using namespace std;
class MyClass
{
public:
	MyClass();
	~MyClass();
	int  func() { return 6; }
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
class MyClassA
{
public:
	MyClassA();
	~MyClassA();
	int  func() { return 5; }

private:

};

MyClassA::MyClassA()
{
}

MyClassA::~MyClassA()
{
}
class MyClassSub:public MyClass, public MyClassA
{
public:
	MyClassSub();
	~MyClassSub();

private:

};

MyClassSub::MyClassSub()
{
}

MyClassSub::~MyClassSub()
{
}
void DispBinary(int num)
{
	int i, j;

	j = sizeof(int) * 8;
	for (i = 0; i < j; i++)
	{
		printf("%d", (num >> (j - i - 1) & 0x1));
	}
}
int main()
{
	MyClassSub sub;
	int re=sub.MyClass::func();
	int i = -1;
	DispBinary(i);
	 
	return 0;
}