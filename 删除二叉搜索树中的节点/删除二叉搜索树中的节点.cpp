/*
https://leetcode.cn/problems/delete-node-in-a-bst/solutions/
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬
����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�
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
		//�����ж�root���ڵ��Ƿ�Ϸ������Ϸ�ֱ��return
		if (root == nullptr)
		{
			return nullptr;
		}
		//�����ǰ�ڵ���ڱ�ɾ��key,˵����ɾ���ڵ��ڸýڵ����������
		//��ݹ�ýڵ����������ɾ���ýڵ�
		if (root->val > key)
		{
			//��Ϊ��ɾ���ýڵ��������ϵĵ㣬˵���ýڵ���������ı���
			//��left������ָ���������µ�
			root->left = deleteNode(root->left, key);
			return root;
		}
		//�����ǰ�ڵ��ֵС��key��˵��Ҫɾ���Ľڵ��ڸ�root�ڵ����������
		//��ݹ�ýڵ�����������ڸ�root�ڵ����������Ѱ��Ҫ��ɾ���Ľڵ�
		if (root->val < key)
		{
			root->right = deleteNode(root->right, key);
			return root;
		}
		//�����ǰ�ڵ���Ǳ�ɾ���Ľڵ�
		if (root->val == key)
		{
			//���������ɾ������
			//��һ���������ɾ���Ľڵ㣬���Һ��Ӷ�Ϊnull
			//��ɾ���ýڵ��ֱ�ӷ���nullptr���У���Ϊ�ýڵ�û�к���
			//ɾ������ͻ����
			if (!root->left && !root->right)
			{
				return nullptr;
			}
			//�ڶ������,�����ɾ���Ľڵ���������Ϊ�գ�������Ϊ��
			//��ɾ���ýڵ��ֱ�ӷ��ظýڵ��������еĵ�һ���ڵ����
			if (root->left && !root->right)
			{
				return root->left;
			}
			//�����������������Ϊ�գ���������Ϊ��
			//ɾ���ýڵ�� ��ֱ�ӷ�������������
			if (!root->left && root->right)
			{
				return root->right;
			}
			//�����������������������Ϊ��
			//����������������ʱ��ɾ���ýڵ��
			//�ҵ��ýڵ�����������Сһ���ڵ�Ϊ��
			if (root->left && root->right)
			{
				//Ĭ�����ҽڵ��һ���ڵ���Ϊ��
				//Ȼ������ýڵ����������ҵ�������������Сֵ��
				//����ô��һ��������С�ڵ���
				//��ʵһ������������Сֵ����������������Ҷ�ӽڵ��ϣ�����ýڵ�û��������
				//��ô�ýڵ㱾�������Сֵ�ˣ���Ϊ�������϶��Ǵ��ڸ��ڵ��
				//�������һֱ������������ֱ��������Ϊnullptr����ô���ص�
				//�ڵ���Ǹ�������Сֵ��
				TreeNode* successor = root->right;
				while (successor->left)
				{
					successor = successor->left;
				}
				//�ҵ����������е���Сֵ successor
				//Ȼ��ɾ����successor��Ȼ��Ѹ�succesor�ڵ��ƶ���ǰ����
				root->right = deleteNode(root->right, successor->val);
				//��successor �ŵ���ɾ���Ľڵ�λ�ô�
				//successor��ָ�룬ָ��ԭ��root����ָ��
				//successor��ָ�룬ָ��ԭ��root����ָ��
				successor->right = root->right;
				successor->left = root->left;
				return successor;
			}
			return root;
		}
	
	}
};
//���ѵ���һ�ֽⷨ

//���˾����ҵ����������ڵ㣬�ٰ��������ӵ����ұߵ������ȽϺ����ɣ����ص���ʾ������һ����ȷ�𰸣���Ҳ���ö���һ�εݹ顣
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
