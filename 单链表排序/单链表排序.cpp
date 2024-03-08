//chatgpt生成的冒泡法单链表排序
#include <iostream>

using namespace std;

// 定义链表节点
struct Node {
	int data;
	Node* next;
};

// 插入新节点到链表末尾
void insert(Node*& head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

// 输出链表内容
void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// 冒泡排序
void bubbleSort(Node* head) {
	if (head == nullptr || head->next == nullptr) return;

	Node* current;
	Node* index = nullptr;
	int temp;

	for (current = head; current->next != nullptr; current = current->next) {
		for (index = current->next; index != nullptr; index = index->next) {
			if (current->data > index->data) {
				temp = current->data;
				current->data = index->data;
				index->data = temp;
			}
		}
	}
}

int main() {
	Node* head = nullptr;

	// 插入一些数据
	insert(head, 5);
	insert(head, 3);
	insert(head, 8);
	insert(head, 1);
	insert(head, 2);

	cout << "Original list:" << endl;
	display(head);

	// 排序
	bubbleSort(head);

	cout << "Sorted list:" << endl;
	display(head);

	return 0;
}
//冒泡排序时间复杂度太高，需要O(nlogn)的时间复杂度，最合适的是归并排序

