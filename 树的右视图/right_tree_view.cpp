
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
        int key = 0;//��ʾ�ڵ����ڵĲ�
        unordered_map<int, TreeNode* > map_node;
        stack<TreeNode*> stack_node;
        //���ȸ��ڵ���ջ ��map
        stack_node.push(root);
        //ÿ���ȱ����ҽڵ�
        while (!stack_node.empty())
        {
            //Ҫ�����ĵ��ջ
            TreeNode *temp_node = stack_node.top();
            //���ýڵ����ڵĲ��Ƿ��Ѿ���ӹ��Ҳ�ڵ�
            //����Ѿ���ӹ��Ҳ�ڵ㣬��ýڵ�Ϳ������ˣ�
            //Ҳ���ǲ��ܱ����뵽map_node

			if (map_node.find(key)== map_node.end())
            {
                //��ǰ�ڵ����ڵĲ㣬����û�м�����Ҳ�ڵ�
                //��ýڵ���Բ���
                map_node[key] = temp_node;
            }

            //�Ѹýڵ���ӽڵ���ջ��������Ҫ�ȱ����ҽڵ�
            //�п��ǵ�ջ���������ġ�����δ�����ҽڵ���ǰ��
            //�ú��룬������ջ��ڵ�
            stack_node.push(root->left);
            stack_node.push(root->right);
            key++;
        }
        //��������ͼ�ɿ����Ľڵ㣬������� map_node��
        //��Ϊ����ֵ��vector<int>�����Ա�����map����ֵ�ŵ�vector��
        vector<int> res;

        for (int i = 0; i<map_node.size();i++)
        {
            res.push_back(map_node[i]->val);
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