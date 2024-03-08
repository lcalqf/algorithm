/*
	���ߣ�LeetCode - Solution
	���ӣ�https ://leetcode.cn/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/

	 
	����������ϣ��  
	
	˼·���㷨

	ע�⵽����һ��ʱ�临�ӶȽϸߵ�ԭ����Ѱ�� target - x ��ʱ�临�Ӷȹ��ߡ���ˣ�������Ҫһ�ָ�����ķ������ܹ�����Ѱ���������Ƿ����Ŀ��Ԫ�ء�������ڣ�������Ҫ�ҳ�����������

	ʹ�ù�ϣ�����Խ�Ѱ�� target - x ��ʱ�临�ӶȽ��͵��� O(N)O(N) ���͵� O(1)O(1)��

	�������Ǵ���һ����ϣ������ÿһ�� x���������Ȳ�ѯ��ϣ�����Ƿ���� target - x��Ȼ�� x ���뵽��ϣ���У����ɱ�֤������ x ���Լ�ƥ�䡣

 
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
  Ҳѧ�����µ�֪ʶ��vector��Ϊ�����ķ���ֵ��
  Ϊ��ʱ��return һ�������š���ֵʱֱ�ӷ��ش����ţ����渳���ض���ֵ
*/