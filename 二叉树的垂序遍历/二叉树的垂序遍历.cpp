//https://blog.csdn.net/zhizhengguan/article/details/124396825
/*
 ����һ����������������ڵ㴹ֱ���򣨴��ϵ��£����У�������ֵ
 ��������ڵ���ͬһ�к��У���ô˳����Ϊ������

 ����˼·��
 ������԰Ѹ��ڵ�������0��Ȼ��ʼ����������������ӽڵ�����ż�һ�����ӽڵ���ż�һ����������ͨ�����������ͬ�еĽڵ�ֵ����һ��
���ǿ�����һ��Map��������ź����Ӧ�Ľڵ�ֵӳ�䣬�������������Զ������������Զ������ҡ�
���ڲ������Ҫ�õ�queue����ʱ��queue����ֻ��ڵ㣬����洢pair{��ţ��ڵ�}������ȡ���Ϳ��Բ�����ţ�������������еĽڵ�Ҳ�ܸ�����ȷ�����

ͨ������ⷢ��һ�����ɣ�������Щ���⣬�����������ֵ���������������ʱ��Ҫ��������µ�����ֵ���µ��ֶ���ʵ���Լ���Ŀ�ġ�
������������һ�����е�����ֵ����ڵ�����������Ǹ��ڵ��һ���ҽڵ��Ǹ��ڵ��һ����ô��ͬ�еĽڵ���Ȼ������������ֵҲ����ͬ�ģ�
Ȼ��������������ֵΪkey�洢��map�У���Ȼ��ͬ�ľʹ浽һ��vector����
 */
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	vector<vector<int>> verticalOrder(TreeNode* root)
	{
		 //�����ж����Ƿ�Ϊ��
		if (root == nullptr)
		{
			return {};
		}
		//����һ��map�����洢��ͬ���������Ľڵ�ֵ����ͬ�������ԵĽڵ�ֵ�ᱣ�浽ͬһ��vector��
		std::map<int, std::vector<int>> m;
		//��ʲôһ�����У���������������������ʱ�����һ���µ�ά�ȣ���������������������
		//Ȼ���������ÿ�����Ľڵ���ٰѶ�Ӧ�����������ŵ�map��
		std::queue<std::pair<int, TreeNode*>>q;
		//���ȸ��ڵ������
		q.push({ 0,root });
		//��ȱ�������
		while (!q.empty())
		{
			//�Ӷ�����ȡ����ǰҪ���������ڵ�
			std::pair<int,TreeNode*> a = q.front();
			q.pop();
			//�Ըýڵ�����index����Ϊkey�����뵽map����ô�������������Ի��Զ����뵽��ͬ��map��
			m[a.first].push_back(a.second->val);
			//�ٱ����ýڵ��������
			if (a.second->left)
			{
				//��ڵ�����У�ÿ���µĽڵ������ʱ������������ڵ㸳ֵ���µ���������ֵ
				//��ڵ��Ǹ������Լ�һ���ҽڵ��Ǹ��ڵ��һ
				q.push({ a.first - 1,a.second->left });
			}
			//�ٱ����ýڵ��������
			if (a.second->right)
			{
				//�ҽڵ������
				q.push({ a.first + 1,a.second->right });
			}
		}
		//����һ��vector�洢���ֵ
		std::vector<std::vector<int>>res;
		//map��ÿ��vector�е�ֵ������ͬ�������ԣ���������map����ÿ��vectorȡ���󣬴�ӡ������
		for (auto &a:m)
		{
			res.push_back(a.second);
		}
		return res;
	}
};