
//链接：https://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
//该单调栈的存储性质是递增的
//也就是从栈顶到栈底是逐渐增大的，栈顶的元素最小
//如果遍历的过程中发现一个新元素比栈顶大，然后栈又是单调递增的
//则栈中第二个元素也比栈顶大，那么对于栈顶元素来说
//相当于找到了一个左边比它大的元素，右边比它大的元素。
//即栈中第二个元素、栈顶元素、新元素三者之间
//就形成了一个凹槽可以用来接雨水了
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		stack<int> stk;
		int n = height.size();
		//遍历所有的元素
		for (int i = 0; i < n; ++i) {
			//遍历栈，
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

 