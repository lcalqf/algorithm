
//���ӣ�https://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
//�õ���ջ�Ĵ洢�����ǵ�����
//Ҳ���Ǵ�ջ����ջ����������ģ�ջ����Ԫ����С
//��������Ĺ����з���һ����Ԫ�ر�ջ����Ȼ��ջ���ǵ���������
//��ջ�еڶ���Ԫ��Ҳ��ջ������ô����ջ��Ԫ����˵
//�൱���ҵ���һ����߱������Ԫ�أ��ұ߱������Ԫ�ء�
//��ջ�еڶ���Ԫ�ء�ջ��Ԫ�ء���Ԫ������֮��
//���γ���һ�����ۿ�����������ˮ��
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		stack<int> stk;
		int n = height.size();
		//�������е�Ԫ��
		for (int i = 0; i < n; ++i) {
			//����ջ��
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

 