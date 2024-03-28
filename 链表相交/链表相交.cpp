//通过哈希表的方式实现查询两个链表的相交节点
//哈希表中存储的是链表的指针
#include <iostream>
#include <unordered_set>
//声明链表的节点
struct ListNode 
{
	int valu;
	ListNode* next;
	//构造函数就声明了
};
using namespace std;
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//首先声明一个哈希表存在链表A
		unordered_set<ListNode*> hash_node;
		//声明一个临时变量存储节点指针，不要改变头指针的值
		ListNode* temp = temp;
		//遍历链表A，把链表中的节点放到哈希表中
		while (temp !=nullptr)
		{
			hash_node.insert(temp);
			temp = temp->next;
		}
		temp = headB;
		//再遍历B链表，看B链表中的节点是否在A中，如果在，则该节点就是两个链表相交的第一个节点
		while (temp !=nullptr)
		{
			if (hash_node.count(temp))
			{
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
};
int main()
{
	return 0;
}