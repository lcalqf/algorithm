/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����:
[0,1,0,3,12]

���:
[1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

����˼·��ֻҪ��ǰֵ��Ϊ0���Ͱѵ�ǰֵ������ǰֵ��k��i ����ƶ���
������ֵΪ0ʱ��k���䣬i��1��Ȼ���ж�nums[i]�Ƿ�Ϊ0���������0����
i�±��Ӧ��ֵ������ǰ��kλ�õ�ֵ������Ϊ0��ֵ��ǰ�ƶ��ˣ�k++��������������
����K�����ֵ������Ҫ��Ϊ0
*/
#include <iostream>
#include <vector>
using namespace  std;
void move_zero(vector<int> &nums) {
	int k = 0;
	for (int i =0 ;i < nums.size(); ++i)
	{
		if (nums[i])
		{
			nums[k++] = nums[i];
		}
	}
	for (int j =k ; j<nums.size(); ++j)
	{
		nums[j] = 0;
	}

}
int main()
{
	for (int i = 0; i < 5; i = 3)
	{
		cout << i << endl;
		break;
	}
	vector<int> vec = { 1,0,2,3,12 };
	move_zero(vec);
	for (auto value :vec)
	{
		cout << value << ",";
	}
	getchar();
	return 0;
}
