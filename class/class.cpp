#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
using namespace std;
 
class String
{
public:
	String::String(const char* str)    //普通构造函数
	{
		cout << "construct" << endl;
		if (str == NULL)        //如果str 为NULL，就存一个空字符串“”
		{
			m_string = new char[1];
			*m_string = '\0';
		}
		else
		{
			m_string = new char[strlen(str) + 1];   //分配空间
			strcpy_s(m_string, strlen(str)+1, str);
		}
	}
	String::String(const String&other)   //拷贝构造函数
	{
		cout << "copy construct" << endl;
		m_string = new char[strlen(other.m_string) + 1]; //分配空间并拷贝
		strcpy_s(m_string,  strlen(other.m_string)+1,other.m_string);
	}

	String & String::operator=(const String& other) //赋值运算符
	{
		cout << "operator =funtion" << endl;
		if (this == &other) //如果对象和other是用一个对象，直接返回本身
		{
			return *this;
		}
		delete[]m_string; //先释放原来的内存
		m_string = new char[strlen(other.m_string) + 1];
		strcpy_s(m_string,  strlen(other.m_string)+1,other.m_string);
		return *this;
	}
private:
	char *m_string;
};

class singleton
{
protected:
	singleton()
	{}
private:
	static singleton* p;
public:
	static singleton* initance();
};
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
	return p;
}

int getValue()
{
	int a = 5;
	return a;
}
struct LIST
{
	int value;
	LIST *next;

};

//回溯求子集
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> item;
		result.push_back(item);
		generate(0, nums, item, result);
		return result;

	}

	void generate(int i, vector<int> & nums, vector<int> &item, vector<vector<int>> &result) {
		if (nums.size() == i)
		{
			return;
		}
		item.push_back(nums[i]);
		result.push_back(item);
		generate(i + 1, nums, item, result);
		item.pop_back();
		generate(i + 1, nums, item, result);
	}
};

int main()
{
	int grid[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	grid[2][2] = '0';
	Solution solution;
	vector<vector<int>>vec_resut;
	vector<int>vec = { 1,2,3 };
	vec_resut=solution.subsets(vec);
	
	for (int i=0;i<vec_resut.size();i++)
	{
		for (int j=0;j<vec_resut[i].size();j++)
		{
			cout << vec_resut[i][j] ;
		}
		cout << endl;
	}

	auto i = 5;
	vector<int>_vec = { 1,2,4,5 };
	vector<int>::iterator new_iter = _vec.begin();
	new_iter = _vec.erase(new_iter);
	for (new_iter; new_iter !=_vec.end();)
	{
		if (*new_iter == 5)
		{
			new_iter = _vec.erase(new_iter);
		}
		else
			new_iter++;
		
	}
	vector<int>::iterator new_iter_2 = _vec.begin();
	for (new_iter_2; new_iter_2 != _vec.end(); new_iter_2++)
	{
		cout << *new_iter_2 << endl;
	}
	LIST *plist = new LIST();
	plist->value = 5;
	plist->next = nullptr;

	LIST *plistNext = new LIST();
	plist->next = plistNext;
	plistNext->value = 6;
	plistNext->next = nullptr;
	int a = 0;

	/*
	
	String str("Hello Word");
	//此时str_new没有初始化，所以会调用拷贝构造函数
	String str_new = str;
	//此时str_new_2 已经初始化了，所以会调用赋值构造函数
	String str_new2("beautiful");
	str_new2 = str_new;
	int a = 0;
	cin >> a;

	*/

	vector<int>i_vec;
	i_vec.push_back(1);
	i_vec.push_back(2);
	i_vec.push_back(3);
	vector<int>::iterator iter_vec = i_vec.begin();
 
	i_vec.erase(iter_vec++);
	iter_vec =i_vec.begin();
	cout << *iter_vec << endl;

	int size = i_vec.size();
	int capacity = i_vec.capacity();
	i_vec.resize(4);//此处把大小改为4，而vector中只有三个元素是原来的值，第四个为默认值0
	i_vec.push_back(4);
	i_vec.push_back(5);
	i_vec.push_back(6);

	size = i_vec.size();
	capacity = i_vec.capacity();


	i_vec.resize(10);
	size = i_vec.size();
	capacity = i_vec.capacity();
	i_vec.reserve(20);
	size = i_vec.size();
	capacity = i_vec.capacity();


	map<int, int>i_map;
	i_map.insert(make_pair(1, 10));
	i_map.insert(make_pair(4, 40));
	i_map.insert(make_pair(2, 20));
	i_map[3] = 30;
	//如果有key已经存在了，新的会插入失败但是不报错，不改变map中原来的值。
	i_map.insert(make_pair(5, 50));


	//传输key=3
	map<int, int>::iterator iter;
	for (iter=i_map.begin();iter != i_map.end();)
	{
		if (iter->first == 3)
		{
			i_map.erase(iter++);
		}
		else
			iter++;
	}
	/*
	//另一种删除方式，通过find活动迭代器 iter，然后erase
	map<int, int>::iterator iter = i_map.find(3);
	if (iter!=i_map.end())
	{
	i_map.erase(iter);
	}
	*/
	
	
	//hash map
	unordered_map<string, string>str_map;
	str_map.insert(make_pair("room_123", "第一课"));
	str_map.insert(make_pair("room_456", "第二课"));
	//插入相同key，也不会改变原来的值
	str_map.insert(make_pair("room_123", "第八课"));

	int && b = getValue();
	cout << b << endl;
	 
 
 
 
	return 0;
}

