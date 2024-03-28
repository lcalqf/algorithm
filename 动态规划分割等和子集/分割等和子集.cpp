//动态规划分割等和子集
//https://leetcode.cn/problems/partition-equal-subset-sum/solutions/442320/fen-ge-deng-he-zi-ji-by-leetcode-solution/
//https://www.programmercarl.com/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
class Solution {
public:
	bool canPartition(vector<int>& nums)
	{
		int sum = 0;
		vector<int>dp(10001, 0);
		for (int i =0; i< nums.size();i++)
		{
			sum += nums[i];
		}
		//也可以使用库函数，只需要一步即求和
		//int sum = accumulate(nums.begin(),nums.end(),0);
		//分割综合的一半
		//如果总和是一个奇数，那说明不能查分成相等的两部分
		if (sum %2 ==1)
		{
			return false;
		}
		int target = sum / 2;
		//开始01背包
		//先遍历物品，此处物品的重量和物品的价值相等，都是数组的元素对应值
		for (int i = 0;i < nums.size();i++)
		{
			//遍历背包，背包是倒叙遍历，填满背包，就是填满target
			for (int j = target;j>nums[i];j--)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		//容量为target的背包，恰好被填满
		if (dp[target] == target)
		{
			return true;
		}
		return false;
	}
};
int main()
{
	return 0;
}