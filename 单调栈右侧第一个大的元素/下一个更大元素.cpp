//leetcod��Ŀ
//https://leetcode.cn/problems/next-greater-element-i/solutions/1065517/xia-yi-ge-geng-da-yuan-su-i-by-leetcode-bfcoj/
//���Ǽ�ס��һ��Ҫ����һ�������Ԫ�أ������õ���ջ�⣬����������Ƶ���Ŀ��������ⷨ��

#include <iostream>
#include <vector>
using namespace std;
//�����ⷨ
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

//����ջ�ⷨ
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
 