//leetcode地址
//https://leetcode.cn/problems/sort-list/solutions/492301/pai-xu-lian-biao-by-leetcode-solution/


//方法一：自顶向下归并排序
//对链表自顶向下归并排序的过程如下。
//
//找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 222 步，慢指针每次移动 111 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
//
//对两个子链表分别排序。
//
//将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21.合并两个有序链表」的做法，将两个有序的子链表进行合并。

#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 合并两个有序链表
ListNode* merge(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	if (l1->val < l2->val) {
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else {
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

// 切分链表
ListNode* split(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* secondHalf = slow->next;
	slow->next = nullptr;

	return secondHalf;
}

// 归并排序
ListNode* mergeSort(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	ListNode* secondHalf = split(head);
	ListNode* left = mergeSort(head);
	ListNode* right = mergeSort(secondHalf);

	return merge(left, right);
}

// 输出链表内容
void display(ListNode* head) {
	ListNode* temp = head;
	while (temp != nullptr) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	ListNode* head = new ListNode(5);
	head->next = new ListNode(3);
	head->next->next = new ListNode(8);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(2);

	cout << "Original list:" << endl;
	display(head);

	// 排序
	head = mergeSort(head);

	cout << "Sorted list:" << endl;
	display(head);

	// 释放内存
	ListNode* current = head;
	while (current != nullptr) {
		ListNode* temp = current;
		current = current->next;
		delete temp;
	}

	return 0;
}

//合并两个链表，使其有序排列

ListNode* merge(ListNode* head1, ListNode* head2)
{
	//创建了一个虚拟头节点，和其对应的头节点指针
	//创建这个虚拟节点，其实相当于开启了一个新的链，
	//来插入（存储）两个链表排序的结果
	ListNode* dummyHead = new ListNode(0);
	ListNode* temp = dummyHead;
	ListNode* temp1 = head1;
	ListNode* temp2 = head2;
	//while开启循环遍历两个链表
	while (temp1 != nullptr && temp2 != nullptr)
	{
		//因为排序时两个链表可能出现重复元素，所以判断条件是小于等于
		if (temp1->val <= temp2->val)
		{
			//谁小先插入谁
			temp->next = temp1;
			//谁被插入到新的琏中了，谁先移动
			temp1 = temp1->next;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}

	//while退出，说明两个待排序的链表中有空的了
	//此时把非空的那个链表插到待排序的链表中就行了

	if (temp1 != nullptr)
	{
		temp->next = temp1;
	}
	else if (temp2 != nullptr)
	{
		temp->next = temp2;
	}
	return dummyHead->next;
}

//通过快慢指针，找到链表的中间节点，然后以中心节点为点，把链表拆分为2
//然后递归拆分，最后归并排序

ListNode* sortList(ListNode* head, ListNode* tail)
{
	if (head == nullptr_t)
	{
		return nullptr;
	}
}