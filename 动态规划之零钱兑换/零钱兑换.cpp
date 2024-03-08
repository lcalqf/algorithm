#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		//��Ϊvector��index�±��Ǵ�0��ʼ������amount��Ԫ�أ��������±귶Χ��[0,amount-1]
		//�����������amountΪ�±���б�������Ҫ�ѳ��ȼ�һ
		int Max = amount + 1;
		//����dp vector�����Ա�������Ϊ dp�Ĵ�С�������õĳ�ʼֵΪ amount+1
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;
		//�ȱ�������
		for (int i = 1; i<= amount; ++i)
		{
			//�ٱ���Ǯ��
			for (int j = 0; j <(int)coins.size();++j)
			{
				//�������������������Ǯ��ʱ�����ܰ����Ǯ�Ҽ������
				if(i >= coins[j])
					dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};
int main()
{
	std::vector<int> coins{ 1, 2, 5};
	Solution solu;
	int re = solu.coinChange(coins, 11);
	return 0;
}