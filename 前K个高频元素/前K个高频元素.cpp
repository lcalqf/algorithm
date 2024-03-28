//https://www.programmercarl.com/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace  std;

class Solution {
public:
	class Compare {
	public:
		bool operator()(pair<int, int>& m, pair<int, int>& n)
		{
			return m.second > n.second;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		//ͳ��Ԫ�س��ֵ�Ƶ��
		unordered_map<int, int> map;
		for (int i=0;i< nums.size();i++)
		{
			//map[nums[i]] ++;
			map[nums[i]] = map[nums[i]] + 1;
		}
		//��Ƶ�ʽ�������
		//����һ��С����,��СΪk
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pre_que;
		//����Ƶ�����ڵ�map
		for (unordered_map<int,int>::iterator it = map.begin(); it!= map.end();it++)
		{
			//�� pair�Էŵ�������
			//pre_que.push(*it);
			//��Ϊ�Ƕ����С���ѵ����ȼ����У����Ի��Զ�����
			pre_que.push(pair<int,int>(it->first, it->second));
			//����ѵĴ�С������K,����е�������֤�ѵĴ�СһֱΪk
			if (pre_que.size()> k )
			{
				pre_que.pop();
			}
		}

		//�ҳ�ǰK����ƵԪ�أ���Ϊ��С���ѣ��ȵ���������С�ģ����Ե������������
		//����浽vector��
		vector<int> result(k);
		for (int i = k - 1; i >=0; i--)
		{
			result[i] = pre_que.top().first;
			pre_que.pop();
		}
		return result;
	}
};
int main()
{
	Solution solution;
	vector<int>nums{ 1,1,1,2,2,3 };
	vector<int>resutl;
	resutl=solution.topKFrequent(nums, 2);
	return 0;
}