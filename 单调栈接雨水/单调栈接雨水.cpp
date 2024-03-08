
//���ӣ�https ://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		stack<int> stk;
		int n = height.size();
		for (int i = 0; i < n; ++i) {
			while (!stk.empty() && height[i] > height[stk.top()]) {
				int top = stk.top();
				stk.pop();
				if (stk.empty()) {
					break;
				}
				int left = stk.top();
				int currWidth = i - left - 1;
				int currHeight = min(height[left], height[i]) - height[top];
				ans += currWidth * currHeight;
			}
			stk.push(i);
		}
		return ans;
	}
};

 