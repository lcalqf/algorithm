
//https://leetcode.cn/problems/combination-sum-iii/
//组合总和三
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//从1到9中选取k个数，和为n
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> resultVec;
		vector<int> tempVec;
		int sum = 0;
		backtracking(n, 1, k, sum,tempVec, resultVec);
		return resultVec;

	}
	 

	//回溯法实现 backtracking
	void backtracking(int targetSum, int startIndex, int k,int &sum,vector<int>& tempVec, vector<vector<int>>& resultVec)
	{
		//剪枝，如果此时sum已经大于结果了，就直接返回了
		if (sum > targetSum)
		{
			return;
		}
		//递归返回条件
		//找到了一组结果
		if (tempVec.size() == k) //找到了k个元素 然后再判断这k个元素是否等于结果sum
		{
			if (sum == targetSum)
			{
				resultVec.push_back(tempVec);
				return;
			}
		}
		
		//遍历组合中的所有元素,从1 到9取数
		for (startIndex; startIndex <= 9; startIndex++)
		{
			tempVec.push_back(startIndex);
			sum += startIndex;
			backtracking(targetSum, startIndex + 1, k,sum, tempVec, resultVec);
			//弹出上一个选择的元素，进行回溯
			sum -= startIndex;
			tempVec.pop_back();
		}
		//轮训完了，也没找到符合条件的组合，此时返回什么呢
		return;
	}
};
int main()
{
	Solution solu;
	vector<vector<int>> result = solu.combinationSum3(2, 18);
	return 0;
}