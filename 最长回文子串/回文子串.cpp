#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int n = s.size();
		int max_len = 0;
		int left = 0;
		int right = 0;
		//dp����
		vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n));
		//�Լ������ǻ��Ĵ�
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = true;
		}
		//���forѭ����ʾ�Ӵ��ĳ���
		for (int L = 2; L <= n ; L++)
		{
			//�ڲ�forѭ�������ַ���
			for (int i = 0 ; i < n  ; i++ )
			{
				//�Ӵ����� L = j - i +1
				//�Ӵ����ұ߽� j = L + i -  1
				int j = L + i - 1;
				// ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
				if (j >= n) {
					break;
				}
				//ǰ����Ӵ���ȣ��������ұ߽��ֵҲ���
                //��ô��ǻ��Ĵ�
				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					if (L > max_len)
					{
						max_len = L;
						left = i;
						right = j;
					}
				}
				else
					dp[i][j] = false;
				
			}
		}
		return s.substr(left,right - left +1);
	}
};


 

class Solution_1 {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;
		// dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
		vector<vector<int>> dp(n, vector<int>(n));
		// ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// ���ƿ�ʼ
		// ��ö���Ӵ�����
		for (int L = 2; L <= n; L++) {
			// ö����߽磬��߽���������ÿ��Կ���һЩ
			for (int i = 0; i < n; i++) {
				// �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
				int j = L + i - 1;
				// ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
				if (j >= n) {
					break;
				}
				cout << "(i,j) =" << "(" << i << "," << j << ")" << endl;
				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}

				// ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};
 
int main()
{
	Solution_1 solu;
	string s  = "cbbd";
	string result = solu.longestPalindrome(s);
	return 0;
}