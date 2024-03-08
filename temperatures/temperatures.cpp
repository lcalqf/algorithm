#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace  std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int size = temperatures.size();
	if (size == 0)
		return {};
	vector<int> result(size,0) ;
	for (int i = 0;i < size; i++) {
		for (int j = i + 1; j < size; j++)
		{
			if (temperatures[j] > temperatures[i])
			{
				result[i] = j - i;
				break;
			}
		}
	}
	return result;
}


vector<int> dailyTemperatures2(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n), next(101, INT_MAX);
	for (int i = n - 1; i >= 0; --i) {
		int warmerIndex = INT_MAX;
		for (int t = temperatures[i] + 1; t <= 100; ++t) {
			warmerIndex = min(warmerIndex, next[t]);
		}
		if (warmerIndex != INT_MAX) {
			ans[i] = warmerIndex - i;
		}
		next[temperatures[i]] = i;
	}
	return ans;
}
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	if (n <= 0)
	{
		return {};
	}
	vector<int>ans(n);
	stack<int>s;
	for (int i =0 ; i< n; ++i)
	{
		//找到栈中，所有比当前temperatures[i]温度小的
		//并计算出它们对应的时间距离
		//单调栈，温度是单调递减的。当出现一个温度比当前温度大的值时，
		//它也可能比栈中以前插入的温度也高。
		//所以用while找出所有当前温度小的温度
		while (!s.empty() && temperatures[i] > temperatures[s.top()])
		{
			int priviousIndex = s.top();
			ans[priviousIndex] = i - priviousIndex;
			s.pop();
		}
		s.push(i);
	}
	return ans;
}
 
int main()
{
	vector<int >temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int > result = dailyTemperatures2(temperatures);
	for (auto i : result)
	{
		std::cout << i << ",";
	}
	return 0;
}