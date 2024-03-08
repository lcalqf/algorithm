//C����ʵ�� stack
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
//������ģ��stack
template <class ElemType>
class Stack
{
public:
	Stack(int capacity_)
		: elements(NULL)
		, top(0)
		, capacity(capacity_)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("capacity should be larger than 0");
		}
		elements = new ElemType[capacity];
	}
	~Stack()
	{
		delete[] elements;
	}
	bool isFull()
	{
		return (top >= capacity);
	}
	void push(const ElemType& val)
	{
		if (isFull())
		{
			throw std::overflow_error("stack is full");
		}
		elements[top] = val;
		(top)++;
	}
	bool isEmpty()
	{
		return (top == 0);
	}
	ElemType pop()
	{
		if (isEmpty())
		{
			throw std::underflow_error("stack is empty");
		}
		(top)--;
		return (elements[top]);
	}
private:
	ElemType* elements;
	int top;
	int capacity;
};

int main()
{
	Stack<int> st(10);
	try
	{
		for (int i = 0; i < 100; i++)
		{
			st.push(i);
			printf("stack push %d\n", i);
		}
	}
	catch (std::exception& ex)
	{
		printf("excpetion: %s\n", ex.what());
	}
	try
	{
		for (int i = 0; i < 100; i++)
		{
			printf("stack pop %d\n", st.pop());
		}
	}
	catch (std::exception& ex)
	{
		printf("excpetion: %s\n", ex.what());
	}
	return 0;
}
*/
//����ջ�����ݽṹ�� Ҫ�����һ�� min ������ �ܹ��õ�ջ����СԪ�ء� Ҫ���� min�� push �Լ� pop ��ʱ�临�Ӷȶ��� O(1)

//O(1)ָ���ǳ���ʱ�����У������������Ϊһ������������һ���㷨��O(1)ʱ��ָ���ǣ�������������С�����ķѵ�ʱ�䶼��һ����

//O(n)ָ����ĳ�㷨������ʱ���������ģ�����ȣ������������ģΪT, ����ʱ��ΪN, �������ģ2Tʱ����ʱ��Ϊ2N��
//http://blog.csdn.net/u012434102/article/details/44871763
#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

struct Stack {
	int top;//��ǰջ��ָ��
	int index;//��ǰ��Сminֵָ��(index������
	ElemType data[MAXSIZE];//�洢ջ������
	ElemType minData[MAXSIZE];//�洢��Сֵ����
	int min;//��¼��ǰ��Сֵ(���п��ޣ�Ϊ��������Ᵽ��)
};

//��ʼ��ջ
bool InitStack(Stack* ptr)
{
	ptr->top = 0;
	ptr->index = 0;
	ptr->min = 0;

	return true;
}

bool push(Stack* ptr, ElemType elem) {
	//������Ҫ�ж�ջ�Ƿ�����
	if (MAXSIZE - 1 == ptr->top) {
		cout << "Stack is full, cannot push data anymore!" << endl;
		return false;
	}
	//�ж��Ƿ��ǵ�һ��ѹ��ջ������,����Сֵ�洢��minStack��
	if (0 == ptr->top) {
		ptr->min = elem;
		ptr->minData[ptr->index++] = elem;
	}
	else if (elem <= ptr->min) {
		ptr->min = elem;
		ptr->minData[ptr->index++] = ptr->min;
	}

	ptr->data[(ptr->top)++] = elem;

	return true;
}

ElemType pop(Stack* ptr, ElemType* elem) {
	//�ж�ջ�Ƿ�Ϊ��
	if (0 == ptr->top) {
		cout << "stack is empty, cannot pop data anymore!" << endl;
		return -65535;
	}
	*elem = ptr->data[--(ptr->top)];

	int i = ptr->index - 1;
	if (*elem == ptr->minData[i]) {
		--(ptr->index);
	}

	return *elem;
}

ElemType minMethod(Stack* ptr) {
	return ptr->minData[--(ptr->index)];
}


int main() {
	Stack ptr;
	int elem;
	InitStack(&ptr);
	push(&ptr, 5);
	push(&ptr, 4);
	push(&ptr, 4);
	push(&ptr, 4);
	//  cout << "pop1: " << pop(&ptr, &elem) << endl;
	//  push(&ptr, 8);
	pop(&ptr, &elem);
	pop(&ptr, &elem);
	pop(&ptr, &elem);
	//  cout << "pop2: " << pop(&ptr, &elem) << endl;
	cout << "minMethod: " << minMethod(&ptr) << endl;

	return 0;
}
//��̬�滮  ����
//http://www.sohu.com/a/153858619_466939