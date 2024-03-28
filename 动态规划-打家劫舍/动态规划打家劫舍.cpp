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
		//只有一个房子，则只能打劫这一家的
		dp[0] = nums[0];
		//有两个房子，则打劫价值更大的房子
		dp[1] = max(nums[0], nums[1]);
		
		//
		for (int  i = 2; i < nums.size(); i++)
		{
			//根据哪个房子更大，确定是打劫第i个房子，还是打击第一个房子
			//如果打劫第i个房子，那就不能打劫第i-1个，所以i-2和i是一组
			//然后和i-1这一组比较
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		//打劫到最后一个房子时，所能打劫到的最大价值
		return dp[nums.size() - 1];
	}
};
int main()
{
	return 0;
}
