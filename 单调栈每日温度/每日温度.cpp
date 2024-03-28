#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> nextGreat(vector<int> temperature)
	{
		if (temperature.empty())
		{
			return {0};
		}
		
		int size = temperature.size();
		vector<int>result(size, 0);
		stack<int> index_stack;
		for (int i = 0; i<size ; i++)
		{
			while (!index_stack.empty())
			{
				//�����ǰ�¶ȱ�ջ���¶ȴ�˵���ҵ�һ����ǰһ���¶ȴ���¶�
				if (temperature[i] > temperature[index_stack.top()])
				{
					result[i] = index_stack.top() - i - 1;
					//��ǰԪ�س�ջ
					index_stack.pop();
				}
				else
				{
					//��ǰԪ�ز���ջ��Ԫ���¶ȴ󣬰ѵ�ǰ�¶ȵ��±���ջ
					index_stack.push(i);
				}
			}
			index_stack.push(i);

		}
		return result;
	}
};