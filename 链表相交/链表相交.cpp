//ͨ����ϣ��ķ�ʽʵ�ֲ�ѯ����������ཻ�ڵ�
//��ϣ���д洢���������ָ��
#include <iostream>
#include <unordered_set>
//��������Ľڵ�
struct ListNode 
{
	int valu;
	ListNode* next;
	//���캯����������
};
using namespace std;
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//��������һ����ϣ���������A
		unordered_set<ListNode*> hash_node;
		//����һ����ʱ�����洢�ڵ�ָ�룬��Ҫ�ı�ͷָ���ֵ
		ListNode* temp = temp;
		//��������A���������еĽڵ�ŵ���ϣ����
		while (temp !=nullptr)
		{
			hash_node.insert(temp);
			temp = temp->next;
		}
		temp = headB;
		//�ٱ���B������B�����еĽڵ��Ƿ���A�У�����ڣ���ýڵ�������������ཻ�ĵ�һ���ڵ�
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