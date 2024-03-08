//https://leetcode.cn/problems/ones-and-zeroes/description/
//https://www.programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html#%E6%80%9D%E8%B7%AF
/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/
#include<iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;
class Solution {
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		return dp[m][n];
	}
};
int main()
{
	vector<vector<int>>dp(5, vector<int>(6 + 1, 0));
	return 0;
}