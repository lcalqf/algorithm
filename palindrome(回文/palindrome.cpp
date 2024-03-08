//https://leetcode.cn/problems/longest-palindromic-substring/
//最长回文子串
#include <iostream>
#include <string>
using namespace  std;
class Solution {
public:
	string longestPalindrome(string s) {
		//中心扩散法求回文子串
		pair<int, int> index;
		//定义两个变量并赋初始值
		int start=0 , end = 0;
		for (int i = 0 ; i< s.size() ; i++)
		{
			//以 i点为中心，向两边扩散
			index = compare(s, i, i);
			if ((index.second - index.first)  > (end - start))
			{
				start = index.first;
				end = index.second;
			}
			//以i和i+1点之间的虚拟节点为中心向两边扩散
			index = compare(s, i, i + 1);
			if ((index.second - index.first) > (end - start))
			{
				start = index.first;
				end = index.second;
			}
		}
		return s.substr(start, end - start + 1);
	}
	//回文规则比较函数,返回回文左、右两边索引
	pair<int, int> compare(string s, int left, int right)
	{
		while (left >= 0 && right <  s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}
		//while退出时，说明此时左右边界不相等
		//那此时相等的左右两边是上一次比较时的左右两边值
		//即左右各自向回倒一步
		return pair<int,int>(left+1,right-1);
	}
};
int main()
{
	Solution solu;
	string teset ="babad";
	string rest = solu.longestPalindrome(teset);
	return 0;
}