//��Ƶ����
//https://www.bilibili.com/video/BV19v4y1S79W/?spm_id_from=333.788&vd_source=f35bc5021a71dc19b28e485c08d0957e
//https://blog.csdn.net/youngyangyang04/article/details/110094590
/*
����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:
����: [1,2,3]
���:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
//���������֮���Ǽ���һ��use��������ѱ�ѡȡ��Ԫ��
//ÿ�α���ʱ���鿴����ѡ���Ԫ�أ��Ƿ��Ѿ���ѡȡ��
#include<vector>
#include <iostream>
using namespace std;
/*

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used) {
		// ��ʱ˵���ҵ���һ��
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == true) 
				continue; // path���Ѿ���¼��Ԫ�أ�ֱ������
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			//���ݻ�ȥ�����������֧��ȡ���ص������ϲ㸸�ڵ㣬ȡ��һ����֧����
			//�������ߣ�����ǰ��Ĳ���
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
		//������Ҷ��β�����������鶼�ź�����
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size();i++)
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