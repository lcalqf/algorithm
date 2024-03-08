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
		//dp数组
		vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n));
		//自己本身是回文串
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = true;
		}
		//外层for循环表示子串的长度
		for (int L = 2; L <= n ; L++)
		{
			//内层for循环遍历字符串
			for (int i = 0 ; i < n  ; i++ )
			{
				//子串长度 L = j - i +1
				//子串的右边界 j = L + i -  1
				int j = L + i - 1;
				// 如果右边界越界，就可以退出当前循环
				if (j >= n) {
					break;
				}
				//前面的子串相等，并且左右边界的值也相等
                //则该串是回文串
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
		// dp[i][j] 表示 s[i..j] 是否是回文串
		vector<vector<int>> dp(n, vector<int>(n));
		// 初始化：所有长度为 1 的子串都是回文串
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// 递推开始
		// 先枚举子串长度
		for (int L = 2; L <= n; L++) {
			// 枚举左边界，左边界的上限设置可以宽松一些
			for (int i = 0; i < n; i++) {
				// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
				int j = L + i - 1;
				// 如果右边界越界，就可以退出当前循环
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

				// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
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