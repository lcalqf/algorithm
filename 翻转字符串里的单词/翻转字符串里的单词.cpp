//���ӣ�https ://leetcode.cn/problems/reverse-words-in-a-string/solutions/194450/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
//˫�˶���ʵ�ַ�ת���ʱȽϺ����
//����һ���µ��ʾͲ��뵽���е�ǰ�棬��push_front�������Զ�������
//����
#include <vector>
#include<string>
#include <iostream>
#include <deque>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		// ��ת�����ַ���
		reverse(s.begin(), s.end());

		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// ��һ���հ��ַ�Ȼ��idx�ƶ�����һ�����ʵĿ�ͷλ��
				//idx�����������ʵ�֮�����һ���ո��
				if (idx != 0)
					s[idx++] = ' ';

				// ѭ�����������ʵ�ĩβ
				//start����ÿ�����ʵĿ�ʼ
				int end = start;
				while (end < n && s[end] != ' ')
					s[idx++] = s[end++];

				// ��ת��������
				reverse(s.begin() + idx - (end - start), s.begin() + idx);

				// ����start��ȥ����һ������
				start = end;
			}
		}
		//ɾ���ַ���ĩβ�Ŀո��
		s.erase(s.begin() + idx, s.end());
		return s;
	}
};

class Solution_2 {
public:
	string reverseWords(string s) {
		int left = 0, right = s.size() - 1;
		// ȥ���ַ�����ͷ�Ŀհ��ַ�
		while (left <= right && s[left] == ' ') ++left;

		// ȥ���ַ���ĩβ�Ŀհ��ַ�
		while (left <= right && s[right] == ' ') --right;

		deque<string> d;
		string word;

		while (left <= right) {
			char c = s[left];
			if (word.size() && c == ' ') {
				// ������ push �����е�ͷ��
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

	//������������index����
	int left = 0;
	int right = s.size() - 1;
	//����ȥ���ַ�����ߵĿո��
	while (s[left] == ' ')
	{
		left++;
	}
	//��ȥ���ַ����ұߵĿո�
	while (s[right] == ' ')
	{
		right--;
	}

	//������һ���ַ���word�������洢��������ÿ������
	string world;
	//����һ��˫�˶��������洢�������ĵ���
	deque<string> d_str;
	//��ʼ�������ַ���
	while (left <= right)
	{
		//word.size������0��˵��word����ֵ��left�����˿ո�
		//˵��һ����������ǰ��һ�����ʵ�ĩβ
		if (world.size()&&s[left] == ' ')
		{
			//�Ѹõ��ʷŵ����е�ǰ��
			d_str.push_front(world);
			//Ȼ��Ѹ�word��ʱ������Ϊ��
			world = "";
		}
		else if (s[left] !=' ')//�����ǰ�ַ������ڿո����˵����ǰ������ʻ�û�н���
		{
			//�ѵ��ʴ浽world��
			world += s[left];
		}
		++left;//left��ǰ�ƶ�
	}
	//ע�������whileѭ����������ʱleft>=right�����һ�����ʲ�û�зŵ�������
	//���Գ�ѭ���Ժ�Ҫ�����һ�������ٷŵ�������
	d_str.push_front(world);

	//��������һ��string,���淭ת֮����ַ���
	string ans;
	while (!d_str.empty())
	{
		string str = d_str.front();
		d_str.pop_front();
		ans += str;
		//ÿ�����ʵ�β���ټ�һ���ո��
		ans += ' ';
	}
	return ans;
}
