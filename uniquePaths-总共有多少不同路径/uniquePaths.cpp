#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		//dp[i][j]��ʾ�����(i,j)�ܵ�·����
		vector<vector<int>>dp = vector<vector<int>>(m,vector<int>(n));
		dp[0][0] = 1;
		//��ʼ��n�е�ֵ
		for (int i = 1; i< n;i++)
		{
			dp[0][i] = 1;
		}
		//��ʼ��m�е�ֵ
		for (int i = 1; i < m;i++)
		{
			dp[i][0] = 1;
		}
		//�����������ֵ
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
	//vectorС�����ǳ�ʼ��
	//��ʾvector���м���Ԫ�أ�ÿ��Ԫ�ص�ֵ�Ƕ���
	
	vector<int> nums(3, 4);
	////�������Ǹ�ֵ����ʾvector�еĵ�һ����һ��Ԫ�أ��ڶ���Ԫ���Ƕ���
	vector<int> big{ 3,4 };
	int path_num = solu.uniquePaths(7, 3);
	return 0;
}