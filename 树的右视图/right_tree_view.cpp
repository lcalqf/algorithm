
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
        //该结构表示特定的层上是否已经添加了右节点
        //因为是遍历右节点，所以如果当该层上已经遍历到右节点了
        //说明当前层的后面的节点都会被遮挡了
        int key = 0;//表示节点所在的层
        unordered_map<int, TreeNode* > map_node;
        stack<TreeNode*> stack_node;
        //首先根节点入栈 和map
        stack_node.push(root);
        //每次先遍历右节点
        while (!stack_node.empty())
        {
            //要遍历的点出栈
            TreeNode *temp_node = stack_node.top();
            //看该节点所在的层是否已经添加过右侧节点
            //如果已经添加过右侧节点，则该节点就看不到了，
            //也就是不能被加入到map_node

			if (map_node.find(key)== map_node.end())
            {
                //当前节点所在的层，从来没有加入过右侧节点
                //则该节点可以插入
                map_node[key] = temp_node;
            }

            //把该节点的子节点入栈，由于需要先遍历右节点
            //有考虑到栈是先入后出的。所以未来让右节点在前面
            //得后入，即先入栈左节点
            stack_node.push(root->left);
            stack_node.push(root->right);
            key++;
        }
        //最终右视图可看到的节点，都存放在 map_node中
        //因为返回值是vector<int>，所以遍历该map，把值放到vector中
        vector<int> res;

        for (int i = 0; i<map_node.size();i++)
        {
            res.push_back(map_node[i]->val);
        }
        return res;
    }
};
//网友写的，通过树的深度搜索dfs来打印右视图
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