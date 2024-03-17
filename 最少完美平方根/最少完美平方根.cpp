//��n����������ƽ����
//https://leetcode.cn/problems/perfect-squares/description/
/*
����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��
��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵��
��ֵ����һ�������Գ˵Ļ������磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�
*/
//https://www.programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html
/*
��������Ŀ����һ�£���ȫƽ����������Ʒ���������޼�ʹ�ã����ո�������n���Ǳ������ʴ���������������ж�����Ʒ��
*/
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int numSquares(int n) {
	vector<int>dp( n+ 1,INT_MAX );
	dp[0] = 0;
	for (int i = 1; i <= n ;i++)
	{
		int j = 1;
		while (i - j * j >= 0)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
			j++;
		}
	}
	return dp[n];
}

int main()
{
	int num = numSquares(12);
	cout << "num:" << num << endl;
	return 0;
}