//https://blog.csdn.net/qq_39328436/article/details/111909432

#include<iostream>
#include <vector>
using namespace std;

struct MGraph
{
	int numVevsticos, numEdges;//ͼ�Ķ������ͱ���
	int VerticesList[6];//�������Ŷ�������
	int Edge[6][6];//��Ӿ���

};
int IsExitEL(vector<vector<int>> g, int n) {
	int count = 0;//��¼��Ϊ�����Ķ������
	int du;//�ݴ�ÿ���ڵ�Ķ�

	for (int i = 0; i < n; i++) {
		du = 0;//ÿ���ڵ����֮ǰ���ȳ�ʼ��
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 1)du++;
		}
		if (du % 2 == 1)count++;//�����Ϊ�������¼
	}

	if (count == 0 || count == 2)return 1;
	else return 0;
}

void zhenti_2021() {
	int n, m;
	cout << "����������ͼ�������ͱ���" << endl;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, 0));
	create_G(g, n, m);
	cout << "�Ƿ����EL·��" << endl;
	cout << IsExitEL(g, n);
}