//https://leetcode.cn/problems/next-permutation/solutions/479151/xia-yi-ge-pai-lie-by-leetcode-solution/
/*
��һ�����У�
����Ҫ������ʵ��һ���㷨�����������������������г��ֵ�������һ����������С�
��һ��˼·��⣺�����鿴��һ����λ����������Ԫ����ϳ���һ�����������
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
	//������ nums[i-1] < nums[i] �������˵�������˽��򣬼��ҵ���a[i]
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
	//�ҵ���nums[j] > nums[index_i]
	//����������ֵ
	int temp = 0;
	temp = nums[index_i];
	nums[index_i] = nums[j];
	nums[j] = temp;

	//�������� nums[index_i] ֮�������
	reverse(nums.begin() + index_i + 1, nums.end());;
}


int main()
{
	vector<int> nums = { 4,5,2,6,3,1 };
	nextPermutation(nums);
	return 0;
}