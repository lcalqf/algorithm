#include <stdio.h>
#define self2 0
#define VexNum 100
typedef char VerType;
typedef int ArcType;

typedef struct 
{
	VerType vex[VexNum];//图的顶点名，如v1,v2 ...
	ArcType arc[VexNum][VexNum];//图的边
	int vexnum, arcnum;//图的顶点数和边数
}MGraph;

//定义函数，输入顶点名，获得顶点下标
int VexName(MGraph G, char v);
//创建图
void CreateUD(MGraph& G)
{
	//8个顶点、9条边
	G.vexnum = 8;
	G.arcnum = 9;
	G.vex[0] = 'v1';
	G.vex[1] = 'v2';
	G.vex[2] = 'v3';
	G.vex[3] = 'v4';
	G.vex[4] = 'v5';
	G.vex[5] = 'v6';
	G.vex[6] = 'v7';
	G.vex[7] = 'v8';
	//初始化邻接矩阵，即顶点的边，初始值为0
	for (int i =0; i< G.vexnum;i++)
	{
		for (int j =0 ;j <G.vexnum;j++)
		{
			G.arc[i][j] = self2;
		}
	}
	//如果两个顶点有连接，把对应的边设置为1 
	int i, j;
	i = VexName(G,'v1');
	j = VexName(G, 'v2');
	//两个顶点有边的话，双向都设置为1
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v1');
	j = VexName(G, 'v3');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v2');
	j = VexName(G, 'v4');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v2');
	j = VexName(G, 'v5');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v5');
	j = VexName(G, 'v8');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v4');
	j = VexName(G, 'v8');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v3');
	j = VexName(G, 'v6');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v3');
	j = VexName(G, 'v7');
	G.arc[i][j] = G.arc[j][i] = 1;

	i = VexName(G, 'v6');
	j = VexName(G, 'v7');
	G.arc[i][j] = G.arc[j][i] = 1;

}
// 输入顶点名，输出顶点对应的下标
int VexName(MGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vex[i] == v)
		{
			return i;
		}
	}
}

bool visited[VexNum];

//递归遍历图
void Prints(MGraph G, int v)
{
	printf("v%c->", G.vex[v]);
	visited[v] = true;
	for (int w =0 ; w<G.vexnum;w++)
	{
		//该w点和v点之间有边，且该w点没有被访问过
		//则访问该点
		if (G.arc[v][w]!= 0 && !visited[w])
		{
			Prints(G, w);
		}
	}
}
int main()
{
	MGraph G;
	CreateUD(G);
	int v = 0;
	Prints(G, v);
	return 0;
}