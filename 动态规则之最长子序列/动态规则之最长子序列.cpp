// 动态规则之最长子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//https://leetcode.cn/problems/longest-palindromic-subsequence/solutions/930442/zui-chang-hui-wen-zi-xu-lie-by-leetcode-hcjqp/
//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
//
//子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。


#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace  std;
class Solution {
    int longesetPalindromeSubseq(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int length = s.length();
        //创建二维dp数组
        vector<vector<int>>dp(length,vector<int>(length));
       //遍历
        for (int i = length-1;i>0;i--)
        {
            dp[i][i] = 1;
            for (int j = i+1;j<length;j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][length - 1];
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

 