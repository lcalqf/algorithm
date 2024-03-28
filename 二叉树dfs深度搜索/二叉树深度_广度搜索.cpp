#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace  std;

//二叉树节点
struct TreeNode
{
	int value;//节点值
	TreeNode* left;//节点左指针
	TreeNode* right;//节点右指针
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	//广度优先搜索
	void bfs(TreeNode* pTreeHead)
	{
		if (!pTreeHead)
		{
			return ;
		}
		queue<TreeNode*>dfsQueue;
		TreeNode* head = pTreeHead;
		//根节点入队列
		dfsQueue.push(pTreeHead);
		while(!dfsQueue.empty())
		{
			TreeNode* pCurrentNode = dfsQueue.front();
			dfsQueue.pop();
			//输出该节点
			std::cout << head->value << std::endl;
			
			//该节点的左节点入队列
			if (pCurrentNode->left !=nullptr)
			{
				dfsQueue.push(pCurrentNode->left);
			}
			//该节点的右节点入队列
			if (pCurrentNode->right != nullptr)
			{
				dfsQueue.push(pCurrentNode->right);
			}
		}
	}

	//深度优先搜索
	void dfs(TreeNode* pTreeHead)
	{
		if (!pTreeHead)
			return;
		stack<TreeNode*>dfsStack;
		TreeNode* head = pTreeHead;
		//根节点入队列
		dfsStack.push(pTreeHead);
		while (!dfsStack.empty())
		{
			//获取栈顶元素
			TreeNode* pfront = dfsStack.top();
			//输出该节点的值
			std::cout << pfront->value << std::endl;
			//出栈
			dfsStack.top();
			//栈是先进后出的，所以后遍历的右节点先入栈
			//该节点的右节点入栈
			if (pfront->right!=nullptr)
			{
				dfsStack.push(pfront->right);
			}
			//该节点左节点入栈
			if (pfront->left!=nullptr)
			{
				dfsStack.push(pfront->left);
			}
			
		}

	}

	//dfs深度优先遍历递归方式实现
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