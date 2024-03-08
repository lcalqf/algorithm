#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
using namespace std;
 
class String
{
public:
	String::String(const char* str)    //��ͨ���캯��
	{
		cout << "construct" << endl;
		if (str == NULL)        //���str ΪNULL���ʹ�һ�����ַ�������
		{
			m_string = new char[1];
			*m_string = '\0';
		}
		else
		{
			m_string = new char[strlen(str) + 1];   //����ռ�
			strcpy_s(m_string, strlen(str)+1, str);
		}
	}
	String::String(const String&other)   //�������캯��
	{
		cout << "copy construct" << endl;
		m_string = new char[strlen(other.m_string) + 1]; //����ռ䲢����
		strcpy_s(m_string,  strlen(other.m_string)+1,other.m_string);
	}

	String & String::operator=(const String& other) //��ֵ�����
	{
		cout << "operator =funtion" << endl;
		if (this == &other) //��������other����һ������ֱ�ӷ��ر���
		{
			return *this;
		}
		delete[]m_string; //���ͷ�ԭ�����ڴ�
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

//�������Ӽ�
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
	//��ʱstr_newû�г�ʼ�������Ի���ÿ������캯��
	String str_new = str;
	//��ʱstr_new_2 �Ѿ���ʼ���ˣ����Ի���ø�ֵ���캯��
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
	i_vec.resize(4);//�˴��Ѵ�С��Ϊ4����vector��ֻ������Ԫ����ԭ����ֵ�����ĸ�ΪĬ��ֵ0
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
	//�����key�Ѿ������ˣ��µĻ����ʧ�ܵ��ǲ��������ı�map��ԭ����ֵ��
	i_map.insert(make_pair(5, 50));


	//����key=3
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
	//��һ��ɾ����ʽ��ͨ��find������� iter��Ȼ��erase
	map<int, int>::iterator iter = i_map.find(3);
	if (iter!=i_map.end())
	{
	i_map.erase(iter);
	}
	*/
	
	
	//hash map
	unordered_map<string, string>str_map;
	str_map.insert(make_pair("room_123", "��һ��"));
	str_map.insert(make_pair("room_456", "�ڶ���"));
	//������ͬkey��Ҳ����ı�ԭ����ֵ
	str_map.insert(make_pair("room_123", "�ڰ˿�"));

	int && b = getValue();
	cout << b << endl;
	 
 
 
 
	return 0;
}

