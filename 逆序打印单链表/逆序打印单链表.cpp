//������������ӡ
//https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
#include<iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};
class Solution {
public:
	vector<int> reverBookList(ListNode* head)
	{
		if (head ==nullptr)
		{
			return {};
		}
		vector<int> vec_resut;
		//ͨ��ջ���Ƚ����ԭ��ﵽ�����Ŀ��
		//��������������������е�Ԫ�طŵ�ջ��
		stack<int> node_stack;
		while (head != nullptr)
		{
			node_stack.push(head->val);
			head = head->next;
		}
		//��ջ�е�Ԫ�طŵ�vector��
		while (!node_stack.empty())
		{
			//ȡջ��Ԫ��
			int temp_value = node_stack.top();
			vec_resut.emplace_back(temp_value);
			//Ԫ�س�ջ
			node_stack.pop();
		}
		return vec_resut;
	 }
};
int main()
{
	return 0;
}