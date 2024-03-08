#include <iostream>
#include<memory.h>
using namespace std;
template <typename T>
class SmartPointer
{
private:
	T * _ptr;//实际的指针
	size_t *_count;//引用计数
public://这个构造函数可以不带参数，第一次构造此时_count = 0
	SmartPointer(T *ptr = nullptr) :_ptr(ptr)
	{
		if (_ptr)
		{
			_count = new size_t(1);
		}
		else
		{
			_count = new size_t(0);
		}
	}

	//拷贝构造函数,拷贝构造函数把引用计数也
	SmartPointer(const SmartPointer &ptr)
	{
		if (this != &ptr)
		{
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(this->_count)++;
		}
	}
	//赋值构造函数
	SmartPointer & operator = (const SmartPointer *ptr)
	{
		if (this->_ptr == &ptr)
		{ 
			return *this;
		}
		//自己的引用数先减一，然后再把别人的赋值过来
		if (this->_ptr)
		{
			(*this->_count)--;
			if (this->_count == 0)
			{
				delete this->_ptr;
				delete this->_count;
			}
		}
		//把别人的指针引用数赋值给自己,然后自己再加一。
		this->_ptr = ptr->_ptr;
		this->_count = ptr->_count;
		(*this->_count)++;  //注意此处 *this-> 其实->是重载的->操作符，返回的是指针所以前面要加个*
		return *this;
	}
	//重载*号操作符,返回的是该类型的引用
	T& operator*()
	{
		assert(this->_ptr == nullptr);
		return *(this->_ptr);
	}
	//重载->操作符
	T* operator ->()
	{
		assert(this->_ptr == nullptr);
		return this->_ptr;
	}
	//析构函数
	~SmartPointer()
	{
		(this->_count)--;
		if (this->_count==0)
		{
			delete this->_ptr;
			
		}

	}
	size_t use_count()
	{
		return *(this->_count);
	}
};
int main()
{
	SmartPointer<int> sp(new int(10));
	SmartPointer<int> sp2(sp);
	SmartPointer<int> sp3(new int(20));
	sp2 = sp3;
	std::cout << sp.use_count() << std::endl;
	std::cout << sp3.use_count() << std::endl;
	int value;
	cin >> value;
	return 0;
}