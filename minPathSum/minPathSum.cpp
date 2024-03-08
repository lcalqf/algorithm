#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int minPathSum(vector<vector<int>>& grid)
{
	if (grid.size() == 0)
	{
		return 0;
	}
	// 保存走到某个几点时最短路径值
	// 比如path[i][j]表示走到节点(i,j)时的最短路径值
	vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
	path[0][0] = grid[0][0];
	// 填充第一行每个节点的最短路径值
	for (int i = 1; i < grid[0].size()  ; i++)
	{
		path[0][i] = path[0][i - 1] + grid[0][i];
	}
	// 填充第一列每个节点的最短路径值
	for (int i = 1; i < grid.size(); i++)
	{
		path[i][0] = path[i - 1][0] + grid[i][0];
	}
	// 除第一行和第一列之外的其他节点的值
	for (int i = 1; i < grid.size()  ; i++)
	{
		for (int j = 1; j < grid[0].size() ; j++)
		{
			path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
		}
	}
	return path[grid.size() -1 ][grid[0].size() -1 ];
}
//实例代码，只保存部分结果，只定义一个一维数组空间利用率更低
int minPathSum2(vector<vector<int>>& grid) {
	vector<int> dp(grid[0].size());

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (i == 0 && j == 0)
			{
				dp[j] = grid[i][j];
			}
			else if (i == 0)
			{
				dp[j] = dp[j - 1] + grid[0][j];
			}
			else if (j == 0)
			{
				dp[j] = dp[j] + grid[i][0];
			}
			else
			{
				dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
			}
		}
	}

	return dp[grid[0].size() - 1];
}

int main()
{
	vector<vector<int>> vec_path(2,vector<int>(2,0));
// 	vec_path[0] = { 1,3,1 };
// 	vec_path[1] = { 1,5,1 };
// 	vec_path[2] = { 4,2,1 };
    vec_path[0] = { 1,2,3 };
  	vec_path[1] = { 4,5,6 };
	int minPath = minPathSum2(vec_path);
	std::cout << "minPath:" << minPath << std::endl;
	return 0;
}