#include<iostream>
#include <queue>
#include <unordered_map>
using namespace std;
//���ȼ����� std::priority_queue()�ĵײ�ʵ�־��Ƕ�
//���������ȼ����й���󶥶ѡ�С���ѣ�ʵ���������
//�������k��ƵԪ��
//https://www.programmercarl.com/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
	bool compare(int x, int y)
	{
		if (x > y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void testPriorityQueue()
	{
		const auto data = { 1,8,5,6,3,4,0,9,7,2 };
		//std::less<�������������> ��ʹ�ô󶥶�
		//std::greater<�������������> ������С����
		std::priority_queue<int, vector<int>, std::greater<int>>timer_queue;
		for (auto n : data)
		{
			timer_queue.push(n);
		}

		std::priority_queue<int, vector<int>, std::less<int>>timer_queue_2;
		for (auto n : data)
		{
			timer_queue_2.push(n);
		}
		//��������ӡ������Ԫ�أ������ջ��Ԫ��pop����
		while (!timer_queue.empty()) {
			std::cout << timer_queue.top() << " " << std::endl;
			timer_queue.pop();

		}
		std::cout << "timer_queue_2" << std::endl;

		while (!timer_queue_2.empty()) {

			std::cout << timer_queue_2.top() << " " << std::endl;
			timer_queue_2.pop();

		}
	}
};
int main()
{
	Solution solution;
	solution.testPriorityQueue();
	getchar();
	return 0;
}