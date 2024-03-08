
//https://leetcode.cn/problems/combination-sum-iii/
//����ܺ���
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//��1��9��ѡȡk��������Ϊn
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> resultVec;
		vector<int> tempVec;
		int sum = 0;
		backtracking(n, 1, k, sum,tempVec, resultVec);
		return resultVec;

	}
	 

	//���ݷ�ʵ�� backtracking
	void backtracking(int targetSum, int startIndex, int k,int &sum,vector<int>& tempVec, vector<vector<int>>& resultVec)
	{
		//��֦�������ʱsum�Ѿ����ڽ���ˣ���ֱ�ӷ�����
		if (sum > targetSum)
		{
			return;
		}
		//�ݹ鷵������
		//�ҵ���һ����
		if (tempVec.size() == k) //�ҵ���k��Ԫ�� Ȼ�����ж���k��Ԫ���Ƿ���ڽ��sum
		{
			if (sum == targetSum)
			{
				resultVec.push_back(tempVec);
				return;
			}
		}
		
		//��������е�����Ԫ��,��1 ��9ȡ��
		for (startIndex; startIndex <= 9; startIndex++)
		{
			tempVec.push_back(startIndex);
			sum += startIndex;
			backtracking(targetSum, startIndex + 1, k,sum, tempVec, resultVec);
			//������һ��ѡ���Ԫ�أ����л���
			sum -= startIndex;
			tempVec.pop_back();
		}
		//��ѵ���ˣ�Ҳû�ҵ�������������ϣ���ʱ����ʲô��
		return;
	}
};
int main()
{
	Solution solu;
	vector<vector<int>> result = solu.combinationSum3(2, 18);
	return 0;
}