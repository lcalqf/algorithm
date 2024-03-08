#include<string>
#include <unordered_set>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 最长无重复子串  滑动窗口解题
//官方解析和通过哈希表解题的方法
/*
	作者：LeetCode - Solution
	链接：https ://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/

*/


class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//s[start,end) 前面包含 后面不包含
		int start(0), end(0), length(0), result(0);
		int sSize = int(s.size());
		unordered_map<char, int> hash;
		while (end < sSize)
		{
			char tmpChar = s[end];
			//仅当s[start,end) 中存在s[end]时更新start
			if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
			{
				start = hash[tmpChar] + 1;
				length = end - start;
			}
			hash[tmpChar] = end;

			end++;
			length++;
			result = max(result, length);
		}
		return result;
	}
};

 
// 第二种解法，不通过哈希表

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// 哈希集合，记录每个字符是否出现过
		unordered_set<char> occ;
		int n = s.size();
		// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
		int rk = -1, ans = 0;
		// 枚举左指针的位置，初始值隐性地表示为 -1
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				// 左指针向右移动一格，移除一个字符
				occ.erase(s[i - 1]);
			}
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				// 不断地移动右指针
				occ.insert(s[rk + 1]);
				++rk;
			}
			// 第 i 到 rk 个字符是一个极长的无重复字符子串
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};



/*
 start 和end 相当于滑动窗口的左起点和右终点
 作者：pinku - 2
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
 
*/
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//s[start,end) 前面包含 后面不包含
		int start(0), end(0), length(0), result(0);
		int sSize = int(s.size());
		while (end < sSize)
		{
			char tmpChar = s[end];
			for (int index = start; index < end; index++)
			{
				if (tmpChar == s[index])
				{
					start = index + 1;
					length = end - start;
					break;
				}
			}

			end++;
			length++;
			result = max(result, length);
		}
		return result;
	}
};

