//求n的最少完美平方根
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