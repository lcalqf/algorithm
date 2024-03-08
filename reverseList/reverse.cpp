/*
  单链表两个临近节点翻转
  如：      1-》3--》4--》5--》9--》10
  翻转后
            3-》1--》5--》4--》10--》9

			第一个节点的next，其实指向了第四个节点
   
*/
#include <iostream>
using namespace std;
struct ListNode 
{
	int value;
	ListNode *next;
};


ListNode* creatList()
{
	ListNode* head = NULL;
	ListNode* CurNode = head;
	for (int i = 1; i <= 8; i++)
	{
		ListNode* TempNode = new ListNode;
		TempNode->value = i;
		TempNode->next = NULL;
		if (head == NULL)
		{
			CurNode = TempNode;
			head = TempNode;
		}
		else
		{
			CurNode->next = TempNode;
			CurNode = TempNode;
		}
	}
	return head;
}
 

void printList(ListNode* head)
{
	while (head)
	{
		if (head->next)
			cout << head->value << "->";
		else
			cout << head->value;
		head = head->next;
	}
	cout << endl;
}
 
 

ListNode *reverse(ListNode *pHead)
{
	ListNode *pPre = pHead;
	ListNode *pCurrent = pHead->next;
	ListNode*pNext = nullptr;
	while (pCurrent!=nullptr)
	{
		if (pPre==pHead)
		{
			pPre->next = nullptr;
		}
		pNext = pCurrent->next;
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}
	 
	return pPre;
 }


 
ListNode* reverseList(ListNode* head)
{
	if (!head || head->next == NULL)
		return head;
	ListNode* NewHead;
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* Next = NULL;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur != head)
			pre->next = cur->next;
		if (cur == head)
			head = cur->next;
		pre = cur;
		Next = cur->next->next;
		cur->next->next = cur;
		cur->next = Next;
		cur = Next;
	}
	return head;
 }
 
int main()
{
	ListNode* head = NULL;
	head = creatList();
	printList(head);
	ListNode* NewHead = reverse(head);
	cout << "after changed" << endl;
	printList(NewHead);
	int a = 0;
	cin >> a;
	return 0;

}