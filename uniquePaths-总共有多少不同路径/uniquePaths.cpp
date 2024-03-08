#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		//dp[i][j]表示到达点(i,j)总的路径数
		vector<vector<int>>dp = vector<vector<int>>(m,vector<int>(n));
		dp[0][0] = 1;
		//初始化n列的值
		for (int i = 1; i< n;i++)
		{
			dp[0][i] = 1;
		}
		//初始化m行的值
		for (int i = 1; i < m;i++)
		{
			dp[i][0] = 1;
		}
		//求其余区域的值
		for (int i = 1; i< m; i++)
		{
			for (int j = 1; j< n;j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
			}
		}
		return dp[m-1][n-1];
	}
};
int main()
{
	Solution solu;
	//vector小括号是初始化
	//表示vector中有几个元素，每个元素的值是多少
	
	vector<int> nums(3, 4);
	////大括号是赋值，表示vector中的第一个第一个元素，第二个元素是多少
	vector<int> big{ 3,4 };
	int path_num = solu.uniquePaths(7, 3);
	return 0;
}