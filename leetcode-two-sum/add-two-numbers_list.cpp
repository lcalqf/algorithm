
/*  题目

 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/



/* 思路
作者：LeetCode-Solution
链接：https://leetcode.cn/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode-solution/

*/


struct ListNode
{
	int val;
	ListNode* next;
	ListNode():val(0), next(nullptr){}
	ListNode(int x) :val(x), next(nullptr) {}//通过这个构造函数对val赋值
	ListNode(int x , ListNode *next ):val(x),next(next){}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 这个地方要注意，多个指针head和tail放到一行进行定义初始化
		// 别隔两行分开定义
		ListNode* head = nullptr, * tail = nullptr;
		int carry = 0;
		while (l1 || l2) {
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry;

			if (!head) {
				// 注意这里，直接把sum的值通过构造函数传给 val,不再通过指针访问val再赋值了
				head = tail = new ListNode(sum % 10);
			}
			else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			carry = sum / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (carry > 0) { 
			//最后如果还有进位，就再创建一个新的 节点，但是tail 不用再向后移动了
			//因为这已经是最后一个了
			tail->next = new ListNode(carry);
		}

	}
};