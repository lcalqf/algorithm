//https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/
//环形链表2可以不用双指针
//就是用哈希表，如果以前遍历过该节点，那么该节点就存在在于哈希表中
//并且该节点就是相遇的节点

#include<iostream>
#include <unordered_map>
#include<unordered_set>
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};
using namespace std;
class Solution {
public:
	ListNode* detectCycle(ListNode* head)
	{
		unordered_set<ListNode*> visited;
		//遍历链表，把遍历的每个节点放到哈希表中，如果以前哈希表中存在该节点，
		//说明该节点就是环的入口节点
		while (head !=nullptr)
		{
			//如果哈希表中存在该节点，说明以前遍历过该节点，直接返回就行
			if (visited.count(head))
			{
				return head;
			}
			//以前哈希表不存在，就把该节点插入到链表中
			visited.insert(head);
			head = head->next;
		}
		return nullptr;
	}
};
//用双指针，快慢指针方法
//https://www.programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html

class Solution_2
{
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast !=nullptr && fast->next!=nullptr)
		{
			//慢指针每次走一步，快指针每次走两步，也就是快指针的速度是慢指针的两倍
			slow = slow->next;
			fast = fast->next->next;
			//当快慢指针相遇时，此时从head和相遇节点同时向前，再次相遇的节点就是环的入口交点
			if (slow == fast)
			{
				//声明两个临时变量，一个是相交的节点，一个是头节点
				ListNode* index1 = fast;
				ListNode* index2 = head;
				//这两个节点分别向后走，直到他们相遇
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // 返回环的入口
			}
		}
		return NULL;
	}
}