//https://blog.csdn.net/qq_39328436/article/details/111909432

#include<iostream>
#include <vector>
using namespace std;

struct MGraph
{
	int numVevsticos, numEdges;//图的顶点数和边数
	int VerticesList[6];//顶点表，存放顶点内容
	int Edge[6][6];//领接矩阵

};
int IsExitEL(vector<vector<int>> g, int n) {
	int count = 0;//记录度为奇数的顶点个数
	int du;//暂存每个节点的度

	for (int i = 0; i < n; i++) {
		du = 0;//每个节点遍历之前都先初始化
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 1)du++;
		}
		if (du % 2 == 1)count++;//如果度为奇数则记录
	}

	if (count == 0 || count == 2)return 1;
	else return 0;
}

void zhenti_2021() {
	int n, m;
	cout << "请输入有向图顶点数和边数" << endl;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, 0));
	create_G(g, n, m);
	cout << "是否存在EL路径" << endl;
	cout << IsExitEL(g, n);
}