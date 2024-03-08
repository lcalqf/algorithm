//题目描述
//https://kamacoder.com/problempage.php?pid=1046
//讲解
//https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF
// 一维dp数组实现
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test_1_wei_bag_problem() {
	vector<int> weight = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	int bagWeight = 4;

	// 初始化
	vector<int> dp(bagWeight + 1, 0);
	for (int i = 0; i < weight.size(); i++) { // 遍历物品
		for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			cout << dp[j] << " ";
		}
		cout << "\n" << endl;
	}
	cout << dp[bagWeight] << endl;
}
int main() {
	test_1_wei_bag_problem();
	getchar();
	return 0;
	//不手动输入了，直接指定背包信息
	// 读取 M 和 N
	/*int M, N;
	cin >> M >> N;

	vector<int> costs(M);
	vector<int> values(M);

	for (int i = 0; i < M; i++) {
		cin >> costs[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> values[j];
	}*/
	int M = 3;
	int N = 4;
	vector<int> costs{1,3,4 };
	vector<int> values{15,20,30};
 
	// 创建一个动态规划数组dp，初始值为0
	vector<int> dp(N + 1, 0);

	// 外层循环遍历每个类型的研究材料
	for (int i = 0; i < M; ++i) {
		// 内层循环从 N 空间逐渐减少到当前研究材料所占空间
		for (int j = N; j >= costs[i]; --j) {
			// 考虑当前研究材料选择和不选择的情况，选择最大值
			dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
			cout << dp[j] <<" ";
		}
		cout << "\n" << endl;
	}

	// 输出dp[N]，即在给定 N 行李空间可以携带的研究材料最大价值
	//cout << dp[N] << endl;
	getchar();
	return 0;
}
