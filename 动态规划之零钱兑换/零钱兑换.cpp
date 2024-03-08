#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		//因为vector的index下标是从0开始，所以amount个元素，正常的下标范围是[0,amount-1]
		//所以如果想以amount为下标进行遍历，需要把长度加一
		int Max = amount + 1;
		//声明dp vector，是以背包容量为 dp的大小，并设置的初始值为 amount+1
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;
		//先遍历背包
		for (int i = 1; i<= amount; ++i)
		{
			//再遍历钱币
			for (int j = 0; j <(int)coins.size();++j)
			{
				//背包容量得能容纳这个钱币时，才能把这个钱币加入进来
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