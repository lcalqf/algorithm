#include<string>
#include <unordered_set>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;
// ����ظ��Ӵ�  �������ڽ���
//�ٷ�������ͨ����ϣ�����ķ���
/*
	���ߣ�LeetCode - Solution
	���ӣ�https ://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/

*/


class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//s[start,end) ǰ����� ���治����
		int start(0), end(0), length(0), result(0);
		int sSize = int(s.size());
		unordered_map<char, int> hash;
		while (end < sSize)
		{
			char tmpChar = s[end];
			//����s[start,end) �д���s[end]ʱ����start
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

 
// �ڶ��ֽⷨ����ͨ����ϣ��

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
		unordered_set<char> occ;
		int n = s.size();
		// ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
		int rk = -1, ans = 0;
		// ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
				occ.erase(s[i - 1]);
			}
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				// ���ϵ��ƶ���ָ��
				occ.insert(s[rk + 1]);
				++rk;
			}
			// �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};



/*
 start ��end �൱�ڻ������ڵ����������յ�
 ���ߣ�pinku - 2
���ӣ�https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
 
*/
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//s[start,end) ǰ����� ���治����
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

