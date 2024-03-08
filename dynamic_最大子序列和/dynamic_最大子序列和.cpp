// dynamic_最大子序列和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
我们能这样干，取决于问题的性质：求出f(n)，只需要知道几个更小的f(c)。我们将求解f(c)称作求解f(n)的“子问题”。
这就是DP（动态规划，dynamic programming）.　　
将一个问题拆成几个子问题，分别求解这些子问题，即可推断出大问题的解。

*/
//https://blog.csdn.net/qq_40963043/article/details/100765212
/*
通过动态规划来求最大子序列和
重点是状态定义和状态转移方程
*/
/*
 题目：
 最大子序列的和 (还有另外一道题，求最大上升子序列的长度（https://www.zhihu.com/question/23995189）
 给定一个整数数组nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素）
 示例：
 输入：[-2,1,-3,4,-1,2,1,-5,4]
 输出：6
 解释：连续子数组[4,-1,2,1]的和最大，为6

 解题思路：
 首先，我们来进行状态的定义：（状态就是结果，是前面一段的决策结果）
 我们假设v(i) 能表示下标为 i 时连续数组的最大和。
 状态的定义确实是个技术活。v(i) 是需要包含nums[ i ]的，这样才能保证连续性，
 也就是说，v[ i ]并不是代表的前i + 1 的最大子序列的和。而是包含nuns[i ]的最大子序列的和。

 接下来就可以写出状态转移方程：
 v(i) = max(v(i - 1) + nums[i] ,  nums[ i ])
 ,即下标为 i 时连续数组的最大和 肯定等于 nums[ i ] 和下标为 i  - 1时连续数组的最大和加上nums[ i ]
 的值中的最大的一个。这里为什么不是v(i) = max(v(i - 1) + nums[i] ,  v(i - 1))？
 这里需要解释一下，如果这么写的话，有可能v[ i] 和 v[i - 1] 
 是同一个子序且也不能实现是连续子序的要求

*/
// 动态规划的经典问题：背包问题 https://www.cnblogs.com/mfrank/p/10533701.html
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> v(nums);
	int maxNum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		v[i] = max(v[i - 1] + nums[i], nums[i]);

		if (maxNum < v[i])
			maxNum = v[i];
	}

	return maxNum;
}


int main()
{
	std::vector<int> arry = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int maxNum = maxSubArray(arry);
    std::cout << "Hello World!\n";
}

