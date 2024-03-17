
#include <iostream>
#include <vector>
//https://leetcode.cn/problems/WNC0Lk/description/
#include <unordered_map>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
  */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 class Solution {
 public:
     vector<int> rightSideView(TreeNode* root) {
         if (!root)
         {
             return {};
         }
         //�ýṹ��ʾ�ض��Ĳ����Ƿ��Ѿ�������ҽڵ�
         //��Ϊ�Ǳ����ҽڵ㣬����������ò����Ѿ��������ҽڵ���
         //˵����ǰ��ĺ���Ľڵ㶼�ᱻ�ڵ���
         unordered_map<int, int > map_node;
         int max_depth = -1;
         stack<TreeNode*> stack_node;
         stack<int> depthStack;
         //���ȸ��ڵ���ջ ��map
         stack_node.push(root);
         depthStack.push(0);
         //ÿ���ȱ����ҽڵ�
         while (!stack_node.empty())
         {
             //Ҫ�����ĵ��ջ
             TreeNode* temp_node = stack_node.top();
             stack_node.pop();
             int depth = depthStack.top();
             depthStack.pop();
             if (temp_node) {
                 //ά����������������
                 max_depth = max(max_depth, depth);
                 //���ýڵ����ڵĲ��Ƿ��Ѿ���ӹ��Ҳ�ڵ�
                 //����Ѿ���ӹ��Ҳ�ڵ㣬��ýڵ�Ϳ������ˣ�
                 //Ҳ���ǲ��ܱ����뵽map_node
                 if (map_node.find(depth) == map_node.end())
                 {
                     //��ǰ�ڵ����ڵĲ����û�м�����Ҳ�ڵ�
                     //��ýڵ���Բ���
                     map_node[depth] = temp_node->val;
                 }
                 //�Ѹýڵ���ӽڵ���ջ��������Ҫ�ȱ����ҽڵ�
                 //�ҿ��ǵ�ջ���������ģ�����δ�����ҽڵ���ǰ��
                 //�ú��룬������ջ��ڵ�

                 stack_node.push(temp_node->left);
                 stack_node.push(temp_node->right);

                 depthStack.push(depth + 1);
                 depthStack.push(depth + 1);
             }

         }
         //��������ͼ�ɿ����Ľڵ㣬������� map_node��
         //��Ϊ����ֵ��vector<int>�����Ա�����map����ֵ�ŵ�vector��
         vector<int> res;
         for (int i = 0; i <= max_depth;++i)
         {
             res.push_back(map_node[i]);
         }
         return res;
     }
 };
//����д�ģ�ͨ�������������dfs����ӡ����ͼ
class Solution1 {
public:
	vector<int> dfs(TreeNode* root, int depth, int& cmp, vector<int>& vec) {
		if (root == nullptr) return {};
		if (depth > cmp) {
			cmp = depth;
			vec.push_back(root->val);
		}

		dfs(root->right, depth + 1, cmp, vec);
		dfs(root->left, depth + 1, cmp, vec);

		return vec;
	}

	vector<int> rightSideView(TreeNode* root) {
		int cmp = 0;
		vector<int> vec;
		return dfs(root, 1, cmp, vec);
	}
};
int main()
{
    
    return 0;
}