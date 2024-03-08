//leetcode��ַ
//https://leetcode.cn/problems/sort-list/solutions/492301/pai-xu-lian-biao-by-leetcode-solution/


//����һ���Զ����¹鲢����
//�������Զ����¹鲢����Ĺ������¡�
//
//�ҵ�������е㣬���е�Ϊ�ֽ磬�������ֳ�����������Ѱ��������е����ʹ�ÿ���ָ�����������ָ��ÿ���ƶ� 222 ������ָ��ÿ���ƶ� 111 ��������ָ�뵽������ĩβʱ����ָ��ָ�������ڵ㼴Ϊ������е㡣
//
//������������ֱ�����
//
//������������������ϲ����õ���������������������ʹ�á�21.�ϲ����������������������������������������кϲ���

#include <iostream>

using namespace std;

// ��������ڵ�
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// �ϲ�������������
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

// �з�����
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

// �鲢����
ListNode* mergeSort(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	ListNode* secondHalf = split(head);
	ListNode* left = mergeSort(head);
	ListNode* right = mergeSort(secondHalf);

	return merge(left, right);
}

// �����������
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

	// ����
	head = mergeSort(head);

	cout << "Sorted list:" << endl;
	display(head);

	// �ͷ��ڴ�
	ListNode* current = head;
	while (current != nullptr) {
		ListNode* temp = current;
		current = current->next;
		delete temp;
	}

	return 0;
}

//�ϲ���������ʹ����������

ListNode* merge(ListNode* head1, ListNode* head2)
{
	//������һ������ͷ�ڵ㣬�����Ӧ��ͷ�ڵ�ָ��
	//�����������ڵ㣬��ʵ�൱�ڿ�����һ���µ�����
	//�����루�洢��������������Ľ��
	ListNode* dummyHead = new ListNode(0);
	ListNode* temp = dummyHead;
	ListNode* temp1 = head1;
	ListNode* temp2 = head2;
	//while����ѭ��������������
	while (temp1 != nullptr && temp2 != nullptr)
	{
		//��Ϊ����ʱ����������ܳ����ظ�Ԫ�أ������ж�������С�ڵ���
		if (temp1->val <= temp2->val)
		{
			//˭С�Ȳ���˭
			temp->next = temp1;
			//˭�����뵽�µ������ˣ�˭���ƶ�
			temp1 = temp1->next;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}

	//while�˳���˵��������������������пյ���
	//��ʱ�ѷǿյ��Ǹ�����嵽������������о�����

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

//ͨ������ָ�룬�ҵ�������м�ڵ㣬Ȼ�������Ľڵ�Ϊ�㣬��������Ϊ2
//Ȼ��ݹ��֣����鲢����

ListNode* sortList(ListNode* head, ListNode* tail)
{
	if (head == nullptr_t)
	{
		return nullptr;
	}
}