#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	// 创建一个vector来保存每一阶楼梯的爬法数量
	vector<int> dp(n + 1, 0);

	// 初始化基础情况
	dp[1] = 1; // 爬一阶楼梯有一种方法
	dp[2] = 2; // 爬两阶楼梯有两种方法

	// 使用动态规划计算爬n阶楼梯的方法数量
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2]; // 当前阶的爬法数量等于前两阶的爬法数量之和
	}

	// 返回结果
	return dp[n];
}

int main() {
	//输入要爬的楼梯阶数：
	int numSteps = 11;
 

	int waysToClimb = climbStairs(numSteps);
	cout << "共有 " << waysToClimb << " 种不同的方式爬到第 " << numSteps << " 阶。" << endl;

	return 0;
}