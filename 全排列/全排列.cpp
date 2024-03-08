//视频讲解
//https://www.bilibili.com/video/BV19v4y1S79W/?spm_id_from=333.788&vd_source=f35bc5021a71dc19b28e485c08d0957e
//https://blog.csdn.net/youngyangyang04/article/details/110094590
/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
//本题的重中之重是加入一个use数组表明已被选取的元素
//每次遍历时都查看将被选则的元素，是否已经被选取了
#include<vector>
#include <iostream>
using namespace std;
/*

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used) {
		// 此时说明找到了一组
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == true) 
				continue; // path里已经收录的元素，直接跳过
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			//回溯回去，就是这个分支不取，回到它的上层父节点，取另一个分支的数
			//即往回走，撤销前面的操作
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		result.clear();
		path.clear();
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}
};
*/
 
class Solution {
public:
	vector<vector<int>> res;
	vector<int>path;
	void backtracs(vector<int>nums, vector<bool>use)
	{
		//遍历到叶子尾部，整个数组都排好序了
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size();i++)
		{
			//如果nums的下标索引在use中，说明这个数已经被选取过了，则本次不能再选它
			if (use[i] == true)
			{
				continue;
			}
			//走到这里说明这个元素没有被选取过
			//则本次选取该元素
			use[i] = true;
			path.push_back(nums[i]);
			//递归继续选取
			backtracs(nums, use);
			//回溯选取该父节点的另一个分支
			path.pop_back();
			use[i] = false;

		}

	}
	vector<vector<int>> permute(vector<int>& nums) {

		res.clear();
		path.clear();
		vector<bool>use(nums.size(), false);
		backtracs(nums, use);
		return res;
	}
};
int main()
{
	Solution solu;
	vector<int> nums{ 1, 2, 3 };
	vector<vector<int>> res;
	res = solu.permute(nums);
	return true;
}