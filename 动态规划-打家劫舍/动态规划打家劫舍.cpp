//https://www.programmercarl.com/0198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size()==0)
		{
			return 0;
		}
		if (nums.size()==1)
		{
			return nums[0];
		}
		vector<int>dp(nums.size());
		//ֻ��һ�����ӣ���ֻ�ܴ����һ�ҵ�
		dp[0] = nums[0];
		//���������ӣ����ټ�ֵ����ķ���
		dp[1] = max(nums[0], nums[1]);
		
		//
		for (int  i = 2; i < nums.size(); i++)
		{
			//�����ĸ����Ӹ���ȷ���Ǵ�ٵ�i�����ӣ����Ǵ����һ������
			//�����ٵ�i�����ӣ��ǾͲ��ܴ�ٵ�i-1��������i-2��i��һ��
			//Ȼ���i-1��һ��Ƚ�
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		//��ٵ����һ������ʱ�����ܴ�ٵ�������ֵ
		return dp[nums.size() - 1];
	}
};
int main()
{
	return 0;
}
