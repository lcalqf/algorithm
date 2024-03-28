//单链表的逆序打印
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
		//通过栈的先进后出原理达到逆序的目的
		//正序遍历单链表，把链表中的元素放到栈中
		stack<int> node_stack;
		while (head != nullptr)
		{
			node_stack.push(head->val);
			head = head->next;
		}
		//把栈中的元素放到vector中
		while (!node_stack.empty())
		{
			//取栈顶元素
			int temp_value = node_stack.top();
			vec_resut.emplace_back(temp_value);
			//元素出栈
			node_stack.pop();
		}
		return vec_resut;
	 }
};
int main()
{
	return 0;
}