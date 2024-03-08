//https://www.bilibili.com/video/BV1UB4y1w7HG/?spm_id_from=333.337.search-card.all.click&vd_source=f35bc5021a71dc19b28e485c08d0957e
//走出迷宫的最少步数
//输出从左上角到右下角至少要经过多少步（即至少要经过多少个空地格子）。
// 计算步数要包括起点和终点
//思路:
// 如果走到某个点x,y，需要的步数，比d数组中记录的最少步数还少，则说明该点是最优的，
//则走该点
/*输入
5 5
..###
#....
#.#.#
#.#.#
#.#..
*/
#include <stdio.h>
#include <iostream>
using namespace  std;
int n, m;
char a[50][50];//地图
int d[50][50];//存储走到每个点最少需要多少步
//方向值变化的数组，(0,0)表示当前点
//右、下、左、上四个方向
//(0,1)、（1,0）、（0，-1）、（-1,0）
int fx[5] = { 0,0,1,0,-1 };
int fy[5] = { 0,1,0,-1,0 };
//递归探索地图，求走到每个点最少需要多少步
//走到(x,y)点，需要的最少步数dep
void dfs(int x, int y, int dep)
{
	d[x][y] = dep;
	//走到下个节点
	int tx, ty;
	//分别遍历4个方向,走到tx，ty点
	for (int i = 1 ; i<=4 ; i++)
	{
		tx = x + fx[i];
		ty = y + fy[i];
		//可以走到dx,dy的条件
		//如果tx,ty可以探索（该点在地图内，且该点是‘.'，
		//且走到该点的步数更少
		//这个是深度优先搜索算法，一直按一个方向比如先向右，向深了查找，
		//直到到达图的边界或者遇到障碍物，才会触发向下个方向，比如想左查找，
		//此时就会回退，回退的时候，就看看dep+1是否比上次保存的步数小
		//所谓dep+1就是从上相邻的前一个节点走到当前节点，经过的步数，那就是上一次的步数加一了呗
		//即dep+1。如果比它小则该点被选中，继续遍历
		if (a[tx][ty] == '.' && (dep+1) < d[tx][ty])
		{
			dfs(tx, ty, dep + 1);
		}
	}
}
int main()
{
	int i, j;
	cin >> n >> m;
	for (i =1 ;i <= n; i++)
	{
		for (j = 1 ; j <= m ;j++)
		{
			cin >> a[i][j];
			//将最少步数初始值设为INT_MAX
			d[i][j] = INT_MAX;
		}
	}
	dfs(1, 1, 1);
	cout << d[n][m];
	//return 0;
}