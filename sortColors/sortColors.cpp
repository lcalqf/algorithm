#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int p0 = 0, p1 = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 1) {
				swap(nums[i], nums[p1]);
				++p1;
			}
			else if (nums[i] == 0) {
				swap(nums[i], nums[p0]);
				if (p0 < p1) {
					swap(nums[i], nums[p1]);
				}
				++p0;
				++p1;
			}
		}
	}
};

int main()
{
	Solution solution_;
	vector<int> nums = { 2,0,2,1,1,0 };
	solution_.sortColors(nums);
	for (auto i : nums) {
		std::cout <<i << std::endl;
	}
	return 0;
}
