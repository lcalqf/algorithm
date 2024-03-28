#include<iostream>
#include<vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            //ÿ�β�������ָ��
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        ListNode* ans = dummyHead->next;
        //ɾ��ǰ��new���ɵ��ƽڵ�
        delete dummyHead;
        return ans;
    }
};
int main()
{
	return 0;
}