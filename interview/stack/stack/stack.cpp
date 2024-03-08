//C语言实现 stack
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
//用数组模拟stack
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
//定义栈的数据结构， 要求添加一个 min 函数， 能够得到栈的最小元素。 要求函数 min、 push 以及 pop 的时间复杂度都是 O(1)

//O(1)指的是常数时间运行，比如操作对象为一个链表，对其有一个算法，O(1)时间指的是，无论链表大或者小，所耗费的时间都是一样的

//O(n)指的是某算法的运行时间与输入规模成正比，即，若输入规模为T, 花费时间为N, 则输入规模2T时花费时间为2N‘
//http://blog.csdn.net/u012434102/article/details/44871763
#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

struct Stack {
	int top;//当前栈顶指针
	int index;//当前最小min值指针(index索引）
	ElemType data[MAXSIZE];//存储栈的数据
	ElemType minData[MAXSIZE];//存储最小值集合
	int min;//记录当前最小值(可有可无，为了容易理解保留)
};

//初始化栈
bool InitStack(Stack* ptr)
{
	ptr->top = 0;
	ptr->index = 0;
	ptr->min = 0;

	return true;
}

bool push(Stack* ptr, ElemType elem) {
	//首先需要判断栈是否已满
	if (MAXSIZE - 1 == ptr->top) {
		cout << "Stack is full, cannot push data anymore!" << endl;
		return false;
	}
	//判断是否是第一个压入栈的数据,将最小值存储到minStack中
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
	//判断栈是否为空
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
//动态规划  讲解
//http://www.sohu.com/a/153858619_466939