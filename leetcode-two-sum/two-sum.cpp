/*
	作者：LeetCode - Solution
	链接：https ://leetcode.cn/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/

	 
	方法二：哈希表  
	
	思路及算法

	注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。

	使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N)O(N) 降低到 O(1)O(1)。

	这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。

 
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map <int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			auto iter = map.find(target - nums[i]);
			if (iter != map.end()) {
				return { iter->second ,i };
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		return {};
	}
};

/* 
  也学到了新的知识，vector作为函数的返回值，
  为空时，return 一个大括号。有值时直接返回大括号，里面赋上特定的值
*/