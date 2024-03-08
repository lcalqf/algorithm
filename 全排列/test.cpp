#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;

	vector<int>path;
	void backtracs(vector<int>nums,vector<bool>use)
	{
		//遍历到叶子尾部，整个数组都排好序了
		//因为遍历到叶子节点后，把排序的组合已经push放到结果res队列中了
		//接着进行回溯，回溯时就是把当前选取的节点删除回到上一步
		//然后选取另一条路径
		//因为path每次有pop删除会一直实时更新，所以在递归的时候不用做参数传下去了
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i< nums.size();i++)
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
		vector<bool>use(nums.size(),false);
		backtracs(nums, use);
	}
};