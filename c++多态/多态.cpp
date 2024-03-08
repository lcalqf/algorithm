#include<iostream>
using namespace std;
class Base
{
public:
	Base() {
		cout << "Base struct..." << endl;
	}
	~Base() {
		cout << "Base destruct" << endl;
	}

	virtual void  Hello()
	{
		cout << "Base Hello..." << endl;
	}
};

class Inherit : public Base
{
public:
	Inherit() {
		cout << "Inherit struct..." << endl;
	}
	~Inherit() {
		cout << "Inherit destruct" << endl;
	}

	void  Hello() override
	{
		cout << "Inherit Hello..." << endl;
	}
};
int main()
{
	Base b;
	Inherit &in = &b;
	in.Hello();
	getchar();
	return 0;
}