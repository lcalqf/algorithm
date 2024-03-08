//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
/*
����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨���������
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//Ҫѧ�����ʹ��֪ʶ��
		//������ֲ��ң������ܲ���ָ��ֵ��,//��ȻҲ�ܲ��ҵ�һ������target��ֵ
		//�����漰��lognN ��ʱ�临�Ӷ�Ҫ�ȿ���һ���Ƿ�����ö��ֲ���
		//�����ǰ�������������������λ������
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