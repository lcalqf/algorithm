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
				//如果当前温度比栈顶温度大，说明找到一个比前一天温度大的温度
				if (temperature[i] > temperature[index_stack.top()])
				{
					result[i] = index_stack.top() - i - 1;
					//当前元素出栈
					index_stack.pop();
				}
				else
				{
					//当前元素不必栈顶元素温度大，把当前温度的下标入栈
					index_stack.push(i);
				}
			}
			index_stack.push(i);

		}
		return result;
	}
};