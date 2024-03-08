//leetcod题目
//https://leetcode.cn/problems/next-greater-element-i/solutions/1065517/xia-yi-ge-geng-da-yuan-su-i-by-leetcode-bfcoj/
//亲们记住，一但要求下一个更大的元素，就是用单调栈解，力扣题库相似的题目都是这个解法。

#include <iostream>
#include <vector>
using namespace std;
//暴力解法
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		vector<int> res(m);
		for (int i = 0; i < m; ++i) {
			int j = 0;
			while (j < n && nums2[j] != nums1[i]) {
				++j;
			}
			int k = j + 1;
			while (k < n && nums2[k] < nums2[j]) {
				++k;
			}
			res[i] = k < n ? nums2[k] : -1;
		}
		return res;
	}
};

//单调栈解法
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		vector<int> res(m);
		for (int i = 0; i < m; ++i) {
			int j = 0;
			while (j < n && nums2[j] != nums1[i]) {
				++j;
			}
			int k = j + 1;
			while (k < n && nums2[k] < nums2[j]) {
				++k;
			}
			res[i] = k < n ? nums2[k] : -1;
		}
		return res;
	}
};
 