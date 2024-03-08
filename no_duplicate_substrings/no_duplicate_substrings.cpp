// no_duplicate_substrings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
 无重复字符的最长子串
 给定一个字符串，找出不含有重复字符的最长子串的长度
*/

/*
解题思路：
建立一个256位大小的整型数组来代替哈希表，这样做的原因是ASCII表共能表示256个字符，
所以可以记录所有字符，然后我们需要定义两个变量res和left，其中res用来记录最长无重复子串的长度，
left指向该无重复子串左边的起始位置，然后我们遍历整个字符串，对于每一个遍历到的字符，
如果哈希表中该字符串对应的值为0，说明没有遇到过该字符，则此时计算最长无重复子串，i - left +１，
其中ｉ是最长无重复子串最右边的位置，left是最左边的位置，还有一种情况也需要计算最长无重复子串，
就是当哈希表中的值小于left，这是由于此时出现过重复的字符，left的位置更新了，如果又遇到了新的字符，
就要重新计算最长无重复子串。最后每次都要在哈希表中将当前字符对应的值赋值为i+1
*/
//https://www.cnblogs.com/ariel-dreamland/p/8668286.html
#include <iostream>
#include <string>
#include <algorithm>
using namespace  std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int m[256] = { 0 }, res = 0, left = 0;
        for (int i =0 ;i< s.size();++i)
        {
            /*
            在上一个最长串中，某个字符已经出现过，所以m[s[i]]不等于0，后面当出现重复字符后
            最长字符串重新计算，left = m[s[0]],如果此时出现一个重复字符，但是这个重复字符
            虽然出现过且m[s[i]]!=0，但是依然需要被计算到新的最长串中，因为是重新计算的新串。
            所以判断条件为m[s[i]]==0（从来没有出现过）|| m[s[i]] <left（在上一个最长子串中出现过），但要算在新的子串中
            */
            if (m[s[i]]== 0 || m[s[i]] <left)
            {
                /*比较这次的最长串与上一次最长串哪个较长
                 如果连续出现两次相等字符，就会出现m[s[i]]<left的情况
                */
                res = max(res, i - left + 1);
            }
            else//遇到重复的字符串
            {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
    
};
int main()
{
    Solution solution;
    string str = "abcabcbb";
    int length = solution.lengthOfLongestSubstring(str);
    std::cout << "Hello World!\n";
}

 