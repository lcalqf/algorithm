#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
	int longestValidParentheses(string s) {
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);//��������-1����ʵΪ�����±����ʱ�����Ӻ�һλ
		for (int i = 0; i< s.length();i++)
		{
			//������������ջ,ջ�б���������ŵ��±�
			//�±���ջ��Ϊ�˼����ַ������ȣ����±����
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else {//������������
				if (stk.empty())
				{
					stk.push(i);//��ջΪ�յ�ʱ��Ϊ��������Ҫ��ջ�أ�
				}
				else//�����������ţ��ҵ�ǰջ�ǿ�
				{
					//�Ȱ�ջ��Ԫ�ص�������ʱ���������Ԫ�غ͸������������������һ������
					stk.pop();
					//�������ջ�������ź�ջΪ�գ��ٰѵ�ǰԪ���±����ջ��
					// �ٴη��뵽ջ�У���Ϊ�����´�ƥ��ʱ�������㳤�ȵ��±�
					if (stk.empty())
					{
						stk.push(i);
					}
					else
					{
						//��ƥ�����ŵĳ���
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