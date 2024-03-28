//链接：https ://leetcode.cn/problems/reverse-words-in-a-string/solutions/194450/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
//双端队列实现翻转单词比较好理解
//遇到一个新单词就插入到队列的前面，即push_front，单词自动倒叙了
//插入
#include <vector>
#include<string>
#include <iostream>
#include <deque>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		// 反转整个字符串
		reverse(s.begin(), s.end());

		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// 填一个空白字符然后将idx移动到下一个单词的开头位置
				//idx是在两个单词的之间插入一个空格符
				if (idx != 0)
					s[idx++] = ' ';

				// 循环遍历至单词的末尾
				//start就是每个单词的开始
				int end = start;
				while (end < n && s[end] != ' ')
					s[idx++] = s[end++];

				// 反转整个单词
				reverse(s.begin() + idx - (end - start), s.begin() + idx);

				// 更新start，去找下一个单词
				start = end;
			}
		}
		//删除字符串末尾的空格符
		s.erase(s.begin() + idx, s.end());
		return s;
	}
};

class Solution_2 {
public:
	string reverseWords(string s) {
		int left = 0, right = s.size() - 1;
		// 去掉字符串开头的空白字符
		while (left <= right && s[left] == ' ') ++left;

		// 去掉字符串末尾的空白字符
		while (left <= right && s[right] == ' ') --right;

		deque<string> d;
		string word;

		while (left <= right) {
			char c = s[left];
			if (word.size() && c == ' ') {
				// 将单词 push 到队列的头部
				d.push_front(move(word));
				word = "";
			}
			else if (c != ' ') {
				word += c;
			}
			++left;
		}
		d.push_front(move(word));

		string ans;
		while (!d.empty()) {
			ans += d.front();
			d.pop_front();
			if (!d.empty()) ans += ' ';
		}
		return ans;
	}
};

 
int main()
{
	string str = "the sky is blue";
	Solution_2 solu;
	string result = solu.reverseWords(str);
	return 0;
 }

string reverseWords(string s) {

	//声明两个左右index坐标
	int left = 0;
	int right = s.size() - 1;
	//首先去掉字符串左边的空格符
	while (s[left] == ' ')
	{
		left++;
	}
	//再去掉字符串右边的空格
	while (s[right] == ' ')
	{
		right--;
	}

	//声明以一个字符串word，用来存储遍历到的每个单词
	string world;
	//声明一个双端队列用来存储遍历到的单词
	deque<string> d_str;
	//开始遍历该字符串
	while (left <= right)
	{
		//word.size不等于0，说明word中有值，left遇到了空格
		//说明一个遍历到了前面一个单词的末尾
		if (world.size()&&s[left] == ' ')
		{
			//把该单词放到队列的前面
			d_str.push_front(world);
			//然后把该word临时变量置为空
			world = "";
		}
		else if (s[left] !=' ')//如果当前字符不等于空格符，说明当前这个单词还没有结束
		{
			//把单词存到world中
			world += s[left];
		}
		++left;//left向前移动
	}
	//注意这里，从while循环出来，此时left>=right，最后一个单词并没有放到队列中
	//所以出循环以后，要把最后一个单词再放到队列中
	d_str.push_front(world);

	//重新声明一个string,保存翻转之后的字符串
	string ans;
	while (!d_str.empty())
	{
		string str = d_str.front();
		d_str.pop_front();
		ans += str;
		//每个单词的尾部再加一个空格符
		ans += ' ';
	}
	return ans;
}
