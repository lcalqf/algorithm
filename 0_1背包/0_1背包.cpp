//��Ŀ����
//https://kamacoder.com/problempage.php?pid=1046
//����
//https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF
// һάdp����ʵ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test_1_wei_bag_problem() {
	vector<int> weight = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	int bagWeight = 4;

	// ��ʼ��
	vector<int> dp(bagWeight + 1, 0);
	for (int i = 0; i < weight.size(); i++) { // ������Ʒ
		for (int j = bagWeight; j >= weight[i]; j--) { // ������������
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
	//���ֶ������ˣ�ֱ��ָ��������Ϣ
	// ��ȡ M �� N
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
 
	// ����һ����̬�滮����dp����ʼֵΪ0
	vector<int> dp(N + 1, 0);

	// ���ѭ������ÿ�����͵��о�����
	for (int i = 0; i < M; ++i) {
		// �ڲ�ѭ���� N �ռ��𽥼��ٵ���ǰ�о�������ռ�ռ�
		for (int j = N; j >= costs[i]; --j) {
			// ���ǵ�ǰ�о�����ѡ��Ͳ�ѡ��������ѡ�����ֵ
			dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
			cout << dp[j] <<" ";
		}
		cout << "\n" << endl;
	}

	// ���dp[N]�����ڸ��� N ����ռ����Я�����о���������ֵ
	//cout << dp[N] << endl;
	getchar();
	return 0;
}
