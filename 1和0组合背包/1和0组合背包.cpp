//https://leetcode.cn/problems/ones-and-zeroes/description/
//https://www.programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html#%E6%80%9D%E8%B7%AF
/*
����һ���������ַ������� strs ���������� m �� n ��

�����ҳ������� strs ������Ӽ��ĳ��ȣ����Ӽ��� ��� �� m �� 0 �� n �� 1 ��

��� x ������Ԫ��Ҳ�� y ��Ԫ�أ����� x �Ǽ��� y �� �Ӽ� ��
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