#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;

	vector<int>path;
	void backtracs(vector<int>nums,vector<bool>use)
	{
		//������Ҷ��β�����������鶼�ź�����
		//��Ϊ������Ҷ�ӽڵ�󣬰����������Ѿ�push�ŵ����res��������
		//���Ž��л��ݣ�����ʱ���ǰѵ�ǰѡȡ�Ľڵ�ɾ���ص���һ��
		//Ȼ��ѡȡ��һ��·��
		//��Ϊpathÿ����popɾ����һֱʵʱ���£������ڵݹ��ʱ��������������ȥ��
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i< nums.size();i++)
		{
			//���nums���±�������use�У�˵��������Ѿ���ѡȡ���ˣ��򱾴β�����ѡ��
			if (use[i] == true)
			{
				continue;
			}
			//�ߵ�����˵�����Ԫ��û�б�ѡȡ��
			//�򱾴�ѡȡ��Ԫ��
			use[i] = true;
			path.push_back(nums[i]);
			//�ݹ����ѡȡ
			backtracs(nums, use);
			//����ѡȡ�ø��ڵ����һ����֧
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