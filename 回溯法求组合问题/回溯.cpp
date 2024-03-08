//我自己用代码随想录介绍的回溯法写出来了
//https://leetcode.cn/problems/combinations/solutions/405094/zu-he-by-leetcode-solution/
/*
回溯法模板
void backtracking(参数){
	if(终止条件){
		存放结果;
		return;
	}

	for(选择：本层集合中元素(树中节点孩子的数量就是集合的大小)){
		处理节点;
		backtracking(路径，选择列表);//递归
		回溯，撤销处理结果;
	}
}

*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> resultVec;
		vector<int> tempVec;
		backtracing(n, 1, k, tempVec, resultVec);
		return resultVec;
	}

	//回溯法实现 backtracing
	void backtracing(int n,int startIndex, int k, vector<int>& tempVec,vector<vector<int>>& resultVec)
	{
		//递归返回条件
		//找到了一组结果
		if (tempVec.size() == k)
		{
			resultVec.push_back(tempVec);
			return ;
		}
		//遍历组合中的所有元素
		for (startIndex; startIndex <= n ; startIndex++)
		{
			tempVec.push_back(startIndex);
			backtracing(n, startIndex+1, k, tempVec, resultVec);
			//弹出上一个选择的元素，进行回溯
			tempVec.pop_back();
		}
		//轮训完了，也没找到符合条件的组合，此时返回什么呢
		return;
	}
};
int main()
{
	Solution solu;
	vector<vector<int>> result = solu.combine(4, 2);
	return 0;
}