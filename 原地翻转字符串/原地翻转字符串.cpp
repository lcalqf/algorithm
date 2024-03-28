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
		//双指针翻转字符串，一个指针指向头部然后向后移动， 一个指针指向尾部向前移动
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