#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	// ����һ��vector������ÿһ��¥�ݵ���������
	vector<int> dp(n + 1, 0);

	// ��ʼ���������
	dp[1] = 1; // ��һ��¥����һ�ַ���
	dp[2] = 2; // ������¥�������ַ���

	// ʹ�ö�̬�滮������n��¥�ݵķ�������
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2]; // ��ǰ�׵�������������ǰ���׵���������֮��
	}

	// ���ؽ��
	return dp[n];
}

int main() {
	//����Ҫ����¥�ݽ�����
	int numSteps = 11;
 

	int waysToClimb = climbStairs(numSteps);
	cout << "���� " << waysToClimb << " �ֲ�ͬ�ķ�ʽ������ " << numSteps << " �ס�" << endl;

	return 0;
}