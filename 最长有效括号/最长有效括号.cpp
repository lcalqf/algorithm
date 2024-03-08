#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
	int longestValidParentheses(string s) {
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);//这里先入-1，其实为了做下标相减时正好延后一位
		for (int i = 0; i< s.length();i++)
		{
			//遇到左括号入栈,栈中保存的是括号的下标
			//下标入栈是为了计算字符串长度，即下标相减
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else {//遇到了右括号
				if (stk.empty())
				{
					stk.push(i);//当栈为空的时候，为何右括号要入栈呢？
				}
				else//遇到了右括号，且当前栈非空
				{
					//先把栈顶元素弹出，此时这个弹出的元素和刚遇到的右括号组成了一对括号
					stk.pop();
					//如果弹出栈顶左括号后，栈为空，再把当前元素下标放入栈中
					// 再次放入到栈中，是为了再下次匹配时用作计算长度的下标
					if (stk.empty())
					{
						stk.push(i);
					}
					else
					{
						//求匹配括号的长度
						maxans = max(maxans, i - stk.top());
					}
				}
			}
		}
		return maxans;
	}
};
int main()
{
	return 0;

}