//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//要学会灵活使用知识点
		//比如二分查找，除了能查找指定值外,//当然也能查找第一个大于target的值
		//凡是涉及到lognN 的时间复杂度要先考虑一下是否可以用二分查找
		//这个和前面的两个有序数组求中位数类似
	int binarySearch(vector<int>& nums, int target, bool lower) {
		int left = 0, right = nums.size() - 1, ans = (int)nums.size();
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower && nums[mid] >= target)) {
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		int leftIdx = binarySearch(nums, target, true);
		int rightIdx = binarySearch(nums, target, false) - 1;
		if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
			return vector<int>{leftIdx, rightIdx};
		}
		return vector<int>{-1, -1};
	}
};
int main()
{
	Solution solu;
	vector<int> nums{ 5,7,7,8,8,10 };
	vector<int>result = solu.searchRange(nums,8);
	return 0;
}