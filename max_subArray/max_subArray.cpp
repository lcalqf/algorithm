/*
程序员面试题精选(03)－求子数组的最大和
题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一
个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，因此输出为该子数组的和18。
分析：本题最初为2005年浙江大学计算机系的考研题的最后一道程序设计题，在2006年里包括google在内的很多知名公
司都把本题当作面试题。由于本题在网络中广为流传，本题也顺利成为2006年程序员面试题中经典中的经典。
如果不考虑时间复杂度，我们可以枚举出所有子数组并求出他们的和。不过非常遗憾的是，由于长度为n的数组有O(n2)
个子数组；而且求一个长度为n的数组的和的时间复杂度为O(n)。因此这种思路的时间是O(n3)。
很容易理解，当我们加上一个正数时，和会增加；当我们加上一个负数时，和会减少。如果当前得到的和是个负数，那
么这个和在接下来的累加中应该抛弃并重新清零，不然的话这个负数将会减少接下来的和。基于这样的思路，我们可以
写出如下代码。
*/
//#include <stdio.h>
//参考代码：
/////////////////////////////////////////////////////////////////////////////
// Find the greatest sum of all sub-arrays
// Return value: if the input is valid, return true, otherwise return false
/////////////////////////////////////////////////////////////////////////////
//bool FindGreatestSumOfSubArray
//(
//	int *pData, // an array
//	unsigned int nLength, // the length of array
//	int &nGreatestSum // the greatest sum of all sub-arrays
//) {
//	// if the input is invalid, return false
//	if ((pData == NULL) || (nLength == 0))
//		return false;
//	int nCurSum = nGreatestSum = 0;
//	for (unsigned int i = 0; i < nLength; ++i)
//	{
//		nCurSum += pData[i];
//		// if the current sum is negative, discard it
//		if (nCurSum < 0)
//			nCurSum = 0;
//		// if a greater sum is found, update the greatest sum
//		if (nCurSum > nGreatestSum)
//			nGreatestSum = nCurSum;
//	}
//	// if all data are negative, find the greatest element in the array
//	if (nGreatestSum == 0)
//	{
//		nGreatestSum = pData[0];
//		for (unsigned int i = 1; i < nLength; ++i)
//		{
//			if (pData[i] > nGreatestSum)
//				nGreatestSum = pData[i];
//		}
//	}
//	return true;
//}
//int main()
//{
//	int array[10] = { 3,-2,-4,-5,1,6,2,-5,-2,-3 };
//	int sum = -100000;
//	FindGreatestSumOfSubArray(array, 10, sum);
//	return 0;
//}
//暴力遍历与分治算法
//https://www.cnblogs.com/AlgrithmsRookie/p/5882379.html
#include <stdio.h>
#include<vector>
#include <algorithm>
using namespace  std;
//分治法求最大子数组和问题
struct PositioASum {
	int low;
	int high;
	int sum;
};
//寻找包含中点位置的最大子数组函数
PositioASum MaxCrossingSubarray(int a[], int low, int mid, int high)
{
	//求中点左边的最大值和最大位置
	int maxLeft;//记录左边的最大位置
	int maxSumLeft = -10000;//记录左边的最大和
	int sumLeft = 0;
	for (int i = mid; i >= low; i--)
	{
		sumLeft += a[i];
		if (sumLeft > maxSumLeft)
		{
			maxSumLeft = sumLeft;
			maxLeft = i;
		}
	}
	//求中点右边的最大值和最大位置
	int maxRight = mid + 1;//记录右边的最大位置
	int maxSumRight = -10000;//记录右边的最大和
	int sumRight = 0;//记录右边子数列的和
	for (int i = mid + 1; i <= high; i++)
	{
		sumRight += a[i];
		if (sumRight > maxSumRight)
		{
			maxSumRight = sumRight;
			maxRight = i;
		}
	}
	PositioASum ps;
	ps.low = maxLeft;
	ps.high = maxRight;
	ps.sum = maxSumLeft + maxSumRight;
	return ps;
}
//分治法
PositioASum FindMaxSubArray(int a[], int low, int high)
{
	if (low == high)
	{
		PositioASum ps;
		ps.low = low;
		ps.high = high;
		ps.sum = a[low];
		return ps;
	}
	else {
		int mid = (low + high) / 2;// <=(high-low)/2+low
		PositioASum left = FindMaxSubArray(a, low, mid);
		PositioASum right = FindMaxSubArray(a, mid + 1, high);
		PositioASum cross = MaxCrossingSubarray(a, low, mid, high);
		if (left.sum >= cross.sum && left.sum >= right.sum)
		{
			return left;
		}
		else if (right.sum >= left.sum && right.sum >= cross.sum)
		{
			return right;
		}
		else {
			return cross;
		}
	}
}


int maxSubArray(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	//dp表示指针指向第i个元素时，最长子数组的和   
	vector<int>dp = vector<int>(nums.size(), 0);
	//最大在子数组和,最开始res最大肯定是nums[0]的值
	int res = nums[0];
	dp[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		//因为dp[i]是表示，到下标i时，最大子数组的长度，
		//所以nums[i]是必须会选入的
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		res = max(res, dp[i]);
	}
	return res;
}


int main(int argc, char* argv[])
{
	//int A[8] = { 1,0,3,0,-1 };
	//PositioASum result = FindMaxSubArray(A, 0, 4);
	//printf("%d  %d  %d", result.low, result.high, result.sum);//将结果打印出来

	vector<int> nums = { 5,4,-1,7,8 };
	int res = maxSubArray(nums);

	vector<vector<int>> dp = vector<vector<int>>(5, vector<int>(10,2));
	getchar();
	return 0;
}