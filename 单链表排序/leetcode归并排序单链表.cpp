

//���ߣ����۹ٷ����
//���ӣ�https ://leetcode.cn/problems/sort-list/solutions/492301/pai-xu-lian-biao-by-leetcode-solution/
// 


//����һ���Զ����¹鲢����
//�������Զ����¹鲢����Ĺ������¡�
//
//�ҵ�������е㣬���е�Ϊ�ֽ磬�������ֳ�����������Ѱ��������е����ʹ�ÿ���ָ�����������ָ��ÿ���ƶ� 222 ������ָ��ÿ���ƶ� 111 ��������ָ�뵽������ĩβʱ����ָ��ָ�������ڵ㼴Ϊ������е㡣
//
//������������ֱ�����
//
//������������������ϲ����õ���������������������ʹ�á�21.�ϲ����������������������������������������кϲ���

 

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode* slow = head, * fast = head;
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}

	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* dummyHead = new ListNode(0);
		ListNode* temp = dummyHead, * temp1 = head1, * temp2 = head2;
		while (temp1 != nullptr && temp2 != nullptr) {
			if (temp1->val <= temp2->val) {
				temp->next = temp1;
				temp1 = temp1->next;
			}
			else {
				temp->next = temp2;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		if (temp1 != nullptr) {
			temp->next = temp1;
		}
		else if (temp2 != nullptr) {
			temp->next = temp2;
		}
		return dummyHead->next;
	}
};
