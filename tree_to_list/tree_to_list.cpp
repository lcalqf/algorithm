// tree_to_list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :value(x), left(nullptr), right(nullptr) {}
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* right_, TreeNode* left_) :value(x), left(left_), right(right_){} 
};
class Solution_ {
public:
	void flatten(TreeNode* root) {
		std::vector<TreeNode*> l;
		preorderTraversal(root, l);
		int n = l.size();
		for (int i = 1; i < n; i++) {
			TreeNode* prev = l.at(i - 1), * curr = l.at(i);
			prev->left = nullptr;
			prev->right = curr;
		}
	}

	void preorderTraversal(TreeNode* root, std::vector<TreeNode*>& l) {
		if (root != NULL) {
			l.push_back(root);
			preorderTraversal(root->left, l);
			preorderTraversal(root->right, l);
		}
	}
};
 
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}
		std::vector<TreeNode*> tree_node_vec;
		//先序遍历二叉树
		preOrderTree(root, tree_node_vec);
		//修改对应指针变成链表
		for (int i = 1; i < tree_node_vec.size(); i++)
		{
			TreeNode* pre = tree_node_vec[i - 1];
			TreeNode* current = tree_node_vec[i];
			pre->right = current;
			pre->left = nullptr;
		}
	}
	void preOrderTree(TreeNode* root, std::vector<TreeNode*>& vec)
	{
		if (root != nullptr)
		{
			vec.push_back(root);
			//先序遍历左子树
			preOrderTree(root->left, vec);
			//先序遍历右子树
			preOrderTree(root->right, vec);
		}
	}
};

void changeVector(std::vector<int>& vec_i,int *p)
{
	for (int i = 0 ;i < 10; i++)
	{
		vec_i.push_back(i);
	}
	*p = 7;
}
int main()
{
	std::vector<int> num;
	int val = 5;
	int* p = &val;
	changeVector(num,p);
	int n = num.size();
	std::cout << *p << std::endl;
	for (int i = 0 ;i < num.size(); i++)
	{
		std::cout << num[i] << std::endl;
	}
    std::cout << "Hello World!\n";
	getchar();
	return 0;
}

 
