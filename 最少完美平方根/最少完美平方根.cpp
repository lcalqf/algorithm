//求n的最少完美平方根
//https://leetcode.cn/problems/perfect-squares/description/
/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，
其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/
//https://www.programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html
/*
我来把题目翻译一下：完全平方数就是物品（可以无限件使用），凑个正整数n就是背包，问凑满这个背包最少有多少物品？
*/
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int numSquares(int n) {
	vector<int>dp( n+ 1,INT_MAX );
	dp[0] = 0;
	for (int i = 1; i <= n ;i++)
	{
		int j = 1;
		while (i - j * j >= 0)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
			j++;
		}
	}
	return dp[n];
}

int main()
{
	int num = numSquares(12);
	cout << "num:" << num << endl;
	return 0;
}