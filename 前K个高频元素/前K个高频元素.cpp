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
		//统计元素出现的频率
		unordered_map<int, int> map;
		for (int i=0;i< nums.size();i++)
		{
			//map[nums[i]] ++;
			map[nums[i]] = map[nums[i]] + 1;
		}
		//对频率进行排序
		//定义一个小顶堆,大小为k
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pre_que;
		//遍历频率所在的map
		for (unordered_map<int,int>::iterator it = map.begin(); it!= map.end();it++)
		{
			//把 pair对放到队列中
			//pre_que.push(*it);
			//因为是定义的小顶堆的优先级队列，所以会自动排序
			pre_que.push(pair<int,int>(it->first, it->second));
			//如果堆的大小大于了K,则队列弹出，保证堆的大小一直为k
			if (pre_que.size()> k )
			{
				pre_que.pop();
			}
		}

		//找出前K个高频元素，因为是小顶堆，先弹出的是最小的，所以倒叙来输出数组
		//结果存到vector中
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