// listSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//https://leetcode.cn/problems/merge-two-sorted-lists/description/
//合并两个有序链表
#include <iostream>
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (list1 == nullptr && list2 == nullptr)
			return nullptr;
		if (list1 != nullptr && list2 == nullptr)
		{
			return list1;
		}
		if (list1 == nullptr && list2 != nullptr)
		{
			return list2;
		}
		//程序刚开始时，这个新节点的指针并没有赋值
		//新节点的指针，是不是得指向其中一个连接的头指针呢
		ListNode* head; //存储排序的后的链表头指针
		ListNode* pre;//指向新加入的节点
		//得先把头指针指向哪里确定好
		if (list1->val <= list2->val)
		{
			head = pre = list1;
			list1 = list1->next;
		}
		else
		{
			head = pre = list2;
			list2 = list2->next;
		}
		while (list1 != nullptr && list2 != nullptr)
		{
			//比较两个链表中节点，谁小就先插入谁
			if (list1->val <= list2->val)
			{
				pre->next = list1;
				list1 = list1->next;

			}
			else
			{
				pre->next = list2;
				list2 = list2->next;

			}
			pre = pre->next;

		}
		if (list1 != nullptr)
		{
			pre->next = list1;
		}
		else if (list2 != nullptr)
		{
			pre->next = list2;
		}
		return head;
	}
///////////官方教程中引入一个虚拟节点//////////////////////////
	ListNode * mergeTwoLists_2(ListNode* list1, ListNode* list2)
	{
		//开始也不判断list1和list2的是否为空，而是统一放到后面的while循环来判断
		//声明一个虚拟的哨兵节点,最终返回的头指针，是该虚拟节点的next节点
		ListNode* preHead = new ListNode(-1);
		ListNode* prev = preHead;
		while (list1 !=nullptr && list2 !=nullptr)
		{
			if (list1->val < list2->val)
			{
				prev->next = list1;
				list1 = list1->next;
			}
			else //注意这里有个炕，不能再直接调用list1->next进行判断了
				//因为前面执行了list1=list->next ，此时并不知道list是否为空
			{
				prev->next = list2;
				list2 = list2->next;
			}
			prev = prev->next;//前向指针向后移动
		}
		//最后把不为空的链表拼接到后面即可
		if (list1 != nullptr)
		{
			prev->next = list1;
		}
		else if (list2 !=nullptr)
		{
			prev->next = list2;
		}
		return preHead->next;//返回的是虚拟节点的next节点
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

 