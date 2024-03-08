//https://leetcode.cn/problems/longest-palindromic-substring/
//������Ӵ�
#include <iostream>
#include <string>
using namespace  std;
class Solution {
public:
	string longestPalindrome(string s) {
		//������ɢ��������Ӵ�
		pair<int, int> index;
		//������������������ʼֵ
		int start=0 , end = 0;
		for (int i = 0 ; i< s.size() ; i++)
		{
			//�� i��Ϊ���ģ���������ɢ
			index = compare(s, i, i);
			if ((index.second - index.first)  > (end - start))
			{
				start = index.first;
				end = index.second;
			}
			//��i��i+1��֮�������ڵ�Ϊ������������ɢ
			index = compare(s, i, i + 1);
			if ((index.second - index.first) > (end - start))
			{
				start = index.first;
				end = index.second;
			}
		}
		return s.substr(start, end - start + 1);
	}
	//���Ĺ���ȽϺ���,���ػ���������������
	pair<int, int> compare(string s, int left, int right)
	{
		while (left >= 0 && right <  s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}
		//while�˳�ʱ��˵����ʱ���ұ߽粻���
		//�Ǵ�ʱ��ȵ�������������һ�αȽ�ʱ����������ֵ
		//�����Ҹ�����ص�һ��
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