//最简单的一种没有优化
/*

#include<iostream>
using namespace std;
int Fib(int i)
{
	if ((i == 0) || (i == 1))
	{
		return 1;
	}
	else
		return Fib(i - 1) + Fib(i - 2);
}
int main(int argc, const char * argv[])
{
	int n;
	cout << "请输入你想求的值" << endl;
	cin >> n;
	int result = Fib(n - 1);
	cout << result << endl;
	cin >> n;
	return 0;
}
*/
//修改版
//方法2：结合动态规划和递归
/*
（1）如果save[n] != 0，说明之前已经计算过，就不用计算了，相当于记忆功能，直接返回save[n]中的值；
（2）如果n == 1 || n == 0，为1；
（3）否则当前的Fabonacci数等于它前两个数的和：save[n] = f(n-1) + f(n-2);
		 
*/
#include <iostream>

int save[100];

int f(int n) {
	if (save[n] != 0) // 已计算过
		return save[n];
	if (n == 1 || n == 0) {
		save[n] = 1;
		return save[n];
	}
	save[n] = f(n - 1) + f(n - 2);
	return save[n];
}

int main(int argc, const char * argv[]) {
	char a = '1';
	int re = a;
	int num = atoi("123");
	int n;
	memset(save, 0, sizeof(save));

	while (std::cin >> n)
		std::cout << f(n) << std::endl;
	std::cin >> n;
	return 0;
}