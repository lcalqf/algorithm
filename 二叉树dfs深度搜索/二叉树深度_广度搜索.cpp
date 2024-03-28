#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace  std;

//�������ڵ�
struct TreeNode
{
	int value;//�ڵ�ֵ
	TreeNode* left;//�ڵ���ָ��
	TreeNode* right;//�ڵ���ָ��
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	//�����������
	void bfs(TreeNode* pTreeHead)
	{
		if (!pTreeHead)
		{
			return ;
		}
		queue<TreeNode*>dfsQueue;
		TreeNode* head = pTreeHead;
		//���ڵ������
		dfsQueue.push(pTreeHead);
		while(!dfsQueue.empty())
		{
			TreeNode* pCurrentNode = dfsQueue.front();
			dfsQueue.pop();
			//����ýڵ�
			std::cout << head->value << std::endl;
			
			//�ýڵ����ڵ������
			if (pCurrentNode->left !=nullptr)
			{
				dfsQueue.push(pCurrentNode->left);
			}
			//�ýڵ���ҽڵ������
			if (pCurrentNode->right != nullptr)
			{
				dfsQueue.push(pCurrentNode->right);
			}
		}
	}

	//�����������
	void dfs(TreeNode* pTreeHead)
	{
		if (!pTreeHead)
			return;
		stack<TreeNode*>dfsStack;
		TreeNode* head = pTreeHead;
		//���ڵ������
		dfsStack.push(pTreeHead);
		while (!dfsStack.empty())
		{
			//��ȡջ��Ԫ��
			TreeNode* pfront = dfsStack.top();
			//����ýڵ��ֵ
			std::cout << pfront->value << std::endl;
			//��ջ
			dfsStack.top();
			//ջ���Ƚ�����ģ����Ժ�������ҽڵ�����ջ
			//�ýڵ���ҽڵ���ջ
			if (pfront->right!=nullptr)
			{
				dfsStack.push(pfront->right);
			}
			//�ýڵ���ڵ���ջ
			if (pfront->left!=nullptr)
			{
				dfsStack.push(pfront->left);
			}
			
		}

	}

	//dfs������ȱ����ݹ鷽ʽʵ��
	void dfs(TreeNode* pTreeHead) {
		if (pTreeHead == nullptr) {
			return;
		}
		std::cout << pTreeHead->value << ",";
		dfs(pTreeHead->left);
		dfs(pTreeHead->right);
	}
 
};
int main()
{
	return 0;
}