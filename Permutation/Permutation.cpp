//https://leetcode.cn/problems/next-permutation/solutions/479151/xia-yi-ge-pai-lie-by-leetcode-solution/
/*
下一个排列：
本题要求我们实现一个算法，将给定数字序列重新排列成字典序中下一个更大的排列。
换一种思路理解：把数组看成一个多位数，用数组元素组合出下一个比它大的数
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	int size = nums.size();
	int i = size - 1;
	while (i > 0)
	{
		if (nums[i - 1] >= nums[i])
		{
			i--;
		}
		else
			break;
	}
	//出现了 nums[i-1] < nums[i] 的情况，说明出现了降序，即找到了a[i]
	int index_i = i - 1;
	int j = size - 1;
	while (j > 0)
	{
		if (nums[j] <= nums[index_i])
		{
			j--;
		}
		else
		{
			break;
		}
	}
	//找到了nums[j] > nums[index_i]
	//交换这两个值
	int temp = 0;
	temp = nums[index_i];
	nums[index_i] = nums[j];
	nums[j] = temp;

	//重新排序 nums[index_i] 之后的数据
	reverse(nums.begin() + index_i + 1, nums.end());;
}


int main()
{
	vector<int> nums = { 4,5,2,6,3,1 };
	nextPermutation(nums);
	return 0;
}