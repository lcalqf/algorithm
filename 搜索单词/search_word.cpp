//��Ŀ
/*
����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false
*/
//���ⷽ��:
//https://leetcode.cn/problems/word-search/solution/hui-su-suan-fa-zui-tong-su-yi-dong-de-ji-h2ny/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
	//�����������ĸ������ϡ��¡�����
	//���ֶ��巽ʽ�������ö�ά�����ʾ��Ҳ���Էֱ���������ά�����ʾx,y
	//int dir[4][2] = { -1,0,1,0,0,-1,0,1 };]
public:
	
	int dx[4] = { -1,0,1,0 };
	int dy[4] = {  0,1,0,-1 }; //��������
	//u ��word�еĵڼ�������
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
		board[x][y] = '.';//�޸�board��ǰֵ����ֹ��α���
		for (int i = 0 ; i < 4 ; i++ )
		{
			int a = x + dx[i];
			int b = y + dy[i];
			//���Խ�磬�����ߵ��Ѿ���������λ�ã���continue
			if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size()||
				board[a][b] == '.')
			{
				 continue;
			}
			//�ݹ����
			if (dfs(board,word,u+1 ,a ,b))
			{
				return true;
			}
		}
		//��board��ֵ�ٸĻ�ȥ
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