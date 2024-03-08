//题目
/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
*/
//解题方法:
//https://leetcode.cn/problems/word-search/solution/hui-su-suan-fa-zui-tong-su-yi-dong-de-ji-h2ny/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
	//定义搜索的四个方向，上、下、左、右
	//两种定义方式，可以用二维数组表示，也可以分别用两个二维数组表示x,y
	//int dir[4][2] = { -1,0,1,0,0,-1,0,1 };]
public:
	
	int dx[4] = { -1,0,1,0 };
	int dy[4] = {  0,1,0,-1 }; //方向数组
	//u 是word中的第几个单词
	bool dfs(vector<vector<char>>& board, string &word , int u, int x, int y)
	{
		if (board[x][y] != word[u])
		{
			return false;
		}
		if (u == word.size() -1 )
		{
			return true;
		}
		char t = board[x][y];
		board[x][y] = '.';//修改board当前值，防止多次遍历
		for (int i = 0 ; i < 4 ; i++ )
		{
			int a = x + dx[i];
			int b = y + dy[i];
			//如果越界，或者走到已经搜索过的位置，则continue
			if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size()||
				board[a][b] == '.')
			{
				 continue;
			}
			//递归遍历
			if (dfs(board,word,u+1 ,a ,b))
			{
				return true;
			}
		}
		//把board的值再改回去
		board[x][y] = t;
		return false;
	}
	bool exist(vector<vector<char>>& board, string world)
	{
		for (int i = 0 ; i < board.size();i++)
		{
			for (int j = 0 ; j < board[i].size(); j++)
			{
				if (dfs(board,world,0,i,j))
				{
					return true;
				}
			}
		}
		return false;
	}
};
int main()
{
	return 0;
}