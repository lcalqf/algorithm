#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	void reverseString(vector<char&>s)
	{
		if (s.empty())
		{
			return;
		}
		//˫ָ�뷭ת�ַ�����һ��ָ��ָ��ͷ��Ȼ������ƶ��� һ��ָ��ָ��β����ǰ�ƶ�
		for (int i = 0,j=s.size()-1;i< (s.size()/2 );i++,j--)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = s[i];
		}
	}

};

int main()
{
	return 0;
 }