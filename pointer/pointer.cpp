#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	int *p = &a;
	int *next = p;
	cout <<"next:"<< next<<"p:" <<p<< endl;
	next++;
	cout << "next:" << next << "p:" << p << endl;
	getchar();
	return 0;
}