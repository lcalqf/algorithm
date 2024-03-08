#include <iostream>
#include<memory.h>
using namespace std;
template <typename T>
class SmartPointer
{
private:
	T * _ptr;//ʵ�ʵ�ָ��
	size_t *_count;//���ü���
public://������캯�����Բ�����������һ�ι����ʱ_count = 0
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

	//�������캯��,�������캯�������ü���Ҳ
	SmartPointer(const SmartPointer &ptr)
	{
		if (this != &ptr)
		{
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(this->_count)++;
		}
	}
	//��ֵ���캯��
	SmartPointer & operator = (const SmartPointer *ptr)
	{
		if (this->_ptr == &ptr)
		{ 
			return *this;
		}
		//�Լ����������ȼ�һ��Ȼ���ٰѱ��˵ĸ�ֵ����
		if (this->_ptr)
		{
			(*this->_count)--;
			if (this->_count == 0)
			{
				delete this->_ptr;
				delete this->_count;
			}
		}
		//�ѱ��˵�ָ����������ֵ���Լ�,Ȼ���Լ��ټ�һ��
		this->_ptr = ptr->_ptr;
		this->_count = ptr->_count;
		(*this->_count)++;  //ע��˴� *this-> ��ʵ->�����ص�->�����������ص���ָ������ǰ��Ҫ�Ӹ�*
		return *this;
	}
	//����*�Ų�����,���ص��Ǹ����͵�����
	T& operator*()
	{
		assert(this->_ptr == nullptr);
		return *(this->_ptr);
	}
	//����->������
	T* operator ->()
	{
		assert(this->_ptr == nullptr);
		return this->_ptr;
	}
	//��������
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