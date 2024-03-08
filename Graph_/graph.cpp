#include <stdio.h>
#define self2 0
#define VexNum 100
typedef char VerType;
typedef int ArcType;

typedef struct 
{
	VerType vex[VexNum];//ͼ�Ķ���������v1,v2 ...
	ArcType arc[VexNum][VexNum];//ͼ�ı�
	int vexnum, arcnum;//ͼ�Ķ������ͱ���
}MGraph;

//���庯�������붥��������ö����±�
int VexName(MGraph G, char v);
//����ͼ
void CreateUD(MGraph& G)
{
	//8�����㡢9����
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
	//��ʼ���ڽӾ��󣬼�����ıߣ���ʼֵΪ0
	for (int i =0; i< G.vexnum;i++)
	{
		for (int j =0 ;j <G.vexnum;j++)
		{
			G.arc[i][j] = self2;
		}
	}
	//����������������ӣ��Ѷ�Ӧ�ı�����Ϊ1 
	int i, j;
	i = VexName(G,'v1');
	j = VexName(G, 'v2');
	//���������бߵĻ���˫������Ϊ1
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
// ���붥��������������Ӧ���±�
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

//�ݹ����ͼ
void Prints(MGraph G, int v)
{
	printf("v%c->", G.vex[v]);
	visited[v] = true;
	for (int w =0 ; w<G.vexnum;w++)
	{
		//��w���v��֮���бߣ��Ҹ�w��û�б����ʹ�
		//����ʸõ�
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