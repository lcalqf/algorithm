#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;
void quicSort(std::vector<int>& nums, int left, int right)
{
	if (nums.empty())
	{
		return;
	}
	int temp = nums[0];
	for (int i = left; i < right;  )
	{
		//从右侧开始遍历
		while (nums[right] > temp && right > left )
		{
			right--;
		}
		//交换
		nums[left] = nums[right];

		while (nums[left] < temp && left < right)
		{
			left++;
		}
		nums[right] = nums[left];
		i = left;
	}
	
	//把做比较的字段插入
	nums[left] = temp;
	quicSort(nums, 0, left);
	quicSort(nums, left + 1, nums.size() - 1);

}

int main()
{
	//std::vector<int> nums = { 2,5,7,1,8,3,9,4,15,10 };
	//quicSort(nums, 0, nums.size()-1);


	std::unordered_map<int, int>num;
	num[0] = 1;
	num[3] = 9;
	num[2] = 10;
	num[1] = 5;
	num[4] = 7;
	num[8] = 15;
	num[9] = 3;
	num[10] = 6;
	num[11] = 17;
	num[12] = 19;
	int current_bucket = num.bucket_count();
	int max_bucket = num.max_bucket_count();

	return 0;
}