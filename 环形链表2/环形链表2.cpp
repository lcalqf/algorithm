//https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/
//��������2���Բ���˫ָ��
//�����ù�ϣ�������ǰ�������ýڵ㣬��ô�ýڵ�ʹ������ڹ�ϣ����
//���Ҹýڵ���������Ľڵ�

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
		//���������ѱ�����ÿ���ڵ�ŵ���ϣ���У������ǰ��ϣ���д��ڸýڵ㣬
		//˵���ýڵ���ǻ�����ڽڵ�
		while (head !=nullptr)
		{
			//�����ϣ���д��ڸýڵ㣬˵����ǰ�������ýڵ㣬ֱ�ӷ��ؾ���
			if (visited.count(head))
			{
				return head;
			}
			//��ǰ��ϣ�����ڣ��ͰѸýڵ���뵽������
			visited.insert(head);
			head = head->next;
		}
		return nullptr;
	}
};
//��˫ָ�룬����ָ�뷽��
//https://www.programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html

class Solution_2
{
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast !=nullptr && fast->next!=nullptr)
		{
			//��ָ��ÿ����һ������ָ��ÿ����������Ҳ���ǿ�ָ����ٶ�����ָ�������
			slow = slow->next;
			fast = fast->next->next;
			//������ָ������ʱ����ʱ��head�������ڵ�ͬʱ��ǰ���ٴ������Ľڵ���ǻ�����ڽ���
			if (slow == fast)
			{
				//����������ʱ������һ�����ཻ�Ľڵ㣬һ����ͷ�ڵ�
				ListNode* index1 = fast;
				ListNode* index2 = head;
				//�������ڵ�ֱ�����ߣ�ֱ����������
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // ���ػ������
			}
		}
		return NULL;
	}
}