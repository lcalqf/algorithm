//https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF

//dp����ʱ��ÿһ�����ֻ����һ����Ʒ��
//һά����ʵ��
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	//��Ʒ��
	int m = 3;
	//��������
	int n = 4;
	//��Ʒ����
	vector<int>costs(m);
	//��Ʒ��ֵ
	vector<int> values(m);
	//���ÿ����Ʒ������
	costs[0] = 1;
	costs[1] = 3;
	costs[2] = 4;
 
	//���ÿ����Ʒ�ļ�ֵ
	values[0] = 15;
	values[1] = 20;
	values[2] = 30;

	//����һ����̬�滮����dp����ʼֵΪ0
	//ע�����������dp���ݵĴ�С�Ǳ��������Ĵ�С��һ
	//��Ϊdp[j]�ĺ����ǣ�����Ϊj�ı��������װ������Ʒ
	//����j�Ǳ����������±����������Դ�����dp����Ĵ�С�Ǳ���������
	vector<int>dp(4 + 1, 0);
	//	dp[0] = 0;����dpʱ�Ѿ���ʼ���ˣ������ٵ���������
	//����ȱ�����Ʒ
	for (int i =0;i< 3;i++)
	{
		//�ڲ����������������������������Ҫ˼��һ��
		//������������ұ�������Ҫ���ڵ�����Ʒ����
		for (int j=4;j>=costs[i];--j)
		{
			dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
			cout << dp[j]<<" ";
		}
		cout << endl;

	}
	
	cout <<"����ֵ:"<<dp[4] << endl;
	getchar();
	return 0;
}