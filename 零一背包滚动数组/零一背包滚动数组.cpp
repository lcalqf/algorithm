//https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF

//dp遍历时，每一层遍历只操作一个物品，
//一维数组实现
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	//物品数
	int m = 3;
	//背包容量
	int n = 4;
	//物品重量
	vector<int>costs(m);
	//物品价值
	vector<int> values(m);
	//填充每个物品的重量
	costs[0] = 1;
	costs[1] = 3;
	costs[2] = 4;
 
	//填充每个物品的价值
	values[0] = 15;
	values[1] = 20;
	values[2] = 30;

	//创建一个动态规划数组dp，初始值为0
	//注意这里，创建的dp数据的大小是背包容量的大小加一
	//因为dp[j]的含义是，容量为j的背包最多能装多少物品
	//所以j是背包容量的下标索引，所以创建的dp数组的大小是背包的容量
	vector<int>dp(4 + 1, 0);
	//	dp[0] = 0;创建dp时已经初始化了，不用再单独遍历了
	//外层先遍历物品
	for (int i =0;i< 3;i++)
	{
		//内层遍历背包，背包倒叙遍历，这块需要思考一下
		//倒叙遍历，并且背包容量要大于等于物品容量
		for (int j=4;j>=costs[i];--j)
		{
			dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
			cout << dp[j]<<" ";
		}
		cout << endl;

	}
	
	cout <<"最多价值:"<<dp[4] << endl;
	getchar();
	return 0;
}