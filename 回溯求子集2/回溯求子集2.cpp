//视频教程
//https://www.bilibili.com/video/BV1vm4y1F71J/?spm_id_from=333.788&vd_source=f35bc5021a71dc19b28e485c08d0957e
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, int startIndex) {
		result.push_back(path);
		for (int i = startIndex; i < nums.size(); i++) {
			// 而我们要对同一树层使用过的元素进行跳过
			//注意这里，只有递归到头，回溯回来选取后面一个元素时，这里的判断才会生效
			if (i > startIndex && nums[i] == nums[i - 1]) { // 注意这里使用i > startIndex
				continue;
			}
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		result.clear();
		path.clear();
		sort(nums.begin(), nums.end()); // 去重需要排序
		backtracking(nums, 0);
		return result;
	}
};
int main()
{
	std::vector<int> nums = { 1,2,2 };
	Solution solu;
	vector<vector<int>> resutl = solu.subsetsWithDup(nums);
	return 0;
}