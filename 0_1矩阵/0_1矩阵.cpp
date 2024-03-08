//通过广度优先搜索解决0、1矩阵问题
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int> >& matrix)
	{
		int rows = matrix.size();
		if (rows == 0)
		{
			return matrix;
		}
		int cols = matrix[0].size();
		vector<vector<int>>dist(rows, vector<int>(cols, INT_MAX));
		queue<pair<int, int>>q;
		for (int i = 0 ;i < rows; i++)
		{
			for (int j =0 ;j<cols;j++ )
			{
				if (matrix[i][j] == 0)
				{
					dist[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
	}
};
int main()
{
	vector<vector<int>> src_vec;
	src_vec.push_back(vector<int>{ 0, 0, 0 });
	src_vec.push_back(vector<int>{ 0, 1, 0 });
	src_vec.push_back(vector<int>{ 1, 1, 1 });
	Solution solu;
	solu.updateMatrix(src_vec);
	return 0;
}