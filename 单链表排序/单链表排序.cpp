//chatgpt���ɵ�ð�ݷ�����������
#include <iostream>

using namespace std;

// ��������ڵ�
struct Node {
	int data;
	Node* next;
};

// �����½ڵ㵽����ĩβ
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

// �����������
void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// ð������
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

	// ����һЩ����
	insert(head, 5);
	insert(head, 3);
	insert(head, 8);
	insert(head, 1);
	insert(head, 2);

	cout << "Original list:" << endl;
	display(head);

	// ����
	bubbleSort(head);

	cout << "Sorted list:" << endl;
	display(head);

	return 0;
}
//ð������ʱ�临�Ӷ�̫�ߣ���ҪO(nlogn)��ʱ�临�Ӷȣ�����ʵ��ǹ鲢����

