//https://blog.csdn.net/zhizhengguan/article/details/124396825
/*
 给定一个二叉树，返回其节点垂直方向（从上到下，逐列）遍历的值
 如果两个节点在同一行和列，那么顺序则为从左到右

 解题思路：
 这里可以把根节点给个序号0，然后开始层序遍历，凡是左子节点则序号减一，右子节点序号加一，这样可以通过序号来把相同列的节点值放在一起
我们可以用一个Map来建立序号和其对应的节点值映射，这样可以用其自动排序功能让列自动从左到右。
由于层序遍历要用到queue，此时的queue不能只存节点，必须存储pair{序号，节点}，这样取出就可以操作序号，而且排入队列中的节点也能附上正确的序号

通过这道题发现一个规律，就是有些问题，如果它的属性值不够表达它的内容时，要懂得添加新的属性值即新的字段来实现自己的目的。
本题就是添加了一个竖行的索性值，左节点的竖行索引是根节点加一，右节点是根节点减一，那么相同列的节点自然它的竖行索性值也是相同的，
然后再以竖行索引值为key存储到map中，自然相同的就存到一个vector中了
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
		 //首先判断树是否为空
		if (root == nullptr)
		{
			return {};
		}
		//声明一个map用来存储相同序列索引的节点值，相同竖行索性的节点值会保存到同一个vector中
		std::map<int, std::vector<int>> m;
		//再什么一个队列，用来遍历树，遍历树的时候，添加一个新的维度，就是树的竖行序列索引
		//然后遍历出来每个树的节点后，再把对应的竖行索引放到map中
		std::queue<std::pair<int, TreeNode*>>q;
		//首先根节点入队列
		q.push({ 0,root });
		//深度遍历该树
		while (!q.empty())
		{
			//从队列中取出当前要遍历的树节点
			std::pair<int,TreeNode*> a = q.front();
			q.pop();
			//以该节点竖行index索引为key，插入到map，那么想他的竖行索性会自动插入到相同的map中
			m[a.first].push_back(a.second->val);
			//再遍历该节点的左子树
			if (a.second->left)
			{
				//左节点入队列，每次新的节点入队列时，都会给该树节点赋值上新的竖行索引值
				//左节点是根的索性加一，右节点是根节点减一
				q.push({ a.first - 1,a.second->left });
			}
			//再遍历该节点的右子树
			if (a.second->right)
			{
				//右节点入队列
				q.push({ a.first + 1,a.second->right });
			}
		}
		//声明一个vector存储结果值
		std::vector<std::vector<int>>res;
		//map中每个vector中的值都是相同竖行索性，索引遍历map，把每个vector取出后，打印就行了
		for (auto &a:m)
		{
			res.push_back(a.second);
		}
		return res;
	}
};