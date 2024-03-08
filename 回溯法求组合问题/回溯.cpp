//���Լ��ô�������¼���ܵĻ��ݷ�д������
//https://leetcode.cn/problems/combinations/solutions/405094/zu-he-by-leetcode-solution/
/*
���ݷ�ģ��
void backtracking(����){
	if(��ֹ����){
		��Ž��;
		return;
	}

	for(ѡ�񣺱��㼯����Ԫ��(���нڵ㺢�ӵ��������Ǽ��ϵĴ�С)){
		����ڵ�;
		backtracking(·����ѡ���б�);//�ݹ�
		���ݣ�����������;
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

	//���ݷ�ʵ�� backtracing
	void backtracing(int n,int startIndex, int k, vector<int>& tempVec,vector<vector<int>>& resultVec)
	{
		//�ݹ鷵������
		//�ҵ���һ����
		if (tempVec.size() == k)
		{
			resultVec.push_back(tempVec);
			return ;
		}
		//��������е�����Ԫ��
		for (startIndex; startIndex <= n ; startIndex++)
		{
			tempVec.push_back(startIndex);
			backtracing(n, startIndex+1, k, tempVec, resultVec);
			//������һ��ѡ���Ԫ�أ����л���
			tempVec.pop_back();
		}
		//��ѵ���ˣ�Ҳû�ҵ�������������ϣ���ʱ����ʲô��
		return;
	}
};
int main()
{
	Solution solu;
	vector<vector<int>> result = solu.combine(4, 2);
	return 0;
}