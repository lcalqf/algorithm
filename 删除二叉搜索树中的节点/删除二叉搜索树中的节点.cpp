/*
https://leetcode.cn/problems/delete-node-in-a-bst/solutions/
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
*/
#include<iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}

};
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		//首先判断root根节点是否合法，不合法直接return
		if (root == nullptr)
		{
			return nullptr;
		}
		//如果当前节点大于被删除key,说明被删除节点在该节点的左子树上
		//则递归该节点的左子树来删除该节点
		if (root->val > key)
		{
			//因为是删除该节点左子树上的点，说明该节点的左子树改变了
			//用left左子树指针来接收新的
			root->left = deleteNode(root->left, key);
			return root;
		}
		//如果当前节点的值小于key，说明要删除的节点在该root节点的右子树上
		//则递归该节点的右子树，在该root节点的右子树上寻找要被删除的节点
		if (root->val < key)
		{
			root->right = deleteNode(root->right, key);
			return root;
		}
		//如果当前节点就是被删除的节点
		if (root->val == key)
		{
			//分情况进行删除操作
			//第一种情况：被删除的节点，左右孩子都为null
			//则删除该节点后，直接返回nullptr就行，因为该节点没有孩子
			//删除它后就会空了
			if (!root->left && !root->right)
			{
				return nullptr;
			}
			//第二种情况,如果被删除的节点左子树不为空，右子树为空
			//则删除该节点后，直接返回该节点左子树中的第一个节点就行
			if (root->left && !root->right)
			{
				return root->left;
			}
			//第三种情况，左子树为空，右子树不为空
			//删除该节点后 ，直接返回它的右子树
			if (!root->left && root->right)
			{
				return root->right;
			}
			//第四种情况，左右子树都不为空
			//当左右子树都不空时，删除该节点后，
			//找到该节点右子树中最小一个节点为根
			if (root->left && root->right)
			{
				//默认以右节点第一个节点作为根
				//然后遍历该节点右子树，找到该右子树的最小值。
				//那怎么找一个树的最小节点呢
				//其实一个搜索树的最小值是在它的左子树的叶子节点上，如果该节点没有左子树
				//那么该节点本身就是最小值了，因为右子树肯定是大于根节点的
				//如果我们一直遍历左子树，直到左子树为nullptr，那么返回的
				//节点就是该树的最小值了
				TreeNode* successor = root->right;
				while (successor->left)
				{
					successor = successor->left;
				}
				//找到了右子树中的最小值 successor
				//然后删除该successor，然后把该succesor节点移动到前面来
				root->right = deleteNode(root->right, successor->val);
				//把successor 放到被删除的节点位置处
				//successor右指针，指向原来root的右指针
				//successor左指针，指向原来root的左指针
				successor->right = root->right;
				successor->left = root->left;
				return successor;
			}
			return root;
		}
	
	}
};
//网友的另一种解法

//个人觉得找到左子树最大节点，再把右子树接到它右边的做法比较好理解吧（返回的是示例里另一个正确答案），也不用多套一次递归。
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) {
			return root;
		}
		if (root->val > key) {
			root->left = deleteNode(root->left, key);
		}
		else if (root->val < key) {
			root->right = deleteNode(root->right, key);
		}
		else {
			if (!root->left || !root->right) {
				return root->left ? root->left : root->right;
			}
			else {
				TreeNode* cur = root->left;
				while (cur->right) {
					cur = cur->right;
				}
				cur->right = root->right;
				return root->left;
			}
		}
		return root;
	}
};
int main()
{
 
	return 0;
}
