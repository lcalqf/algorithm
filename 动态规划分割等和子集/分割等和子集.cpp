//��̬�滮�ָ�Ⱥ��Ӽ�
//https://leetcode.cn/problems/partition-equal-subset-sum/solutions/442320/fen-ge-deng-he-zi-ji-by-leetcode-solution/
//https://www.programmercarl.com/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
class Solution {
public:
	bool canPartition(vector<int>& nums)
	{
		int sum = 0;
		vector<int>dp(10001, 0);
		for (int i =0; i< nums.size();i++)
		{
			sum += nums[i];
		}
		//Ҳ����ʹ�ÿ⺯����ֻ��Ҫһ�������
		//int sum = accumulate(nums.begin(),nums.end(),0);
		//�ָ��ۺϵ�һ��
		//����ܺ���һ����������˵�����ܲ�ֳ���ȵ�������
		if (sum %2 ==1)
		{
			return false;
		}
		int target = sum / 2;
		//��ʼ01����
		//�ȱ�����Ʒ���˴���Ʒ����������Ʒ�ļ�ֵ��ȣ����������Ԫ�ض�Ӧֵ
		for (int i = 0;i < nums.size();i++)
		{
			//���������������ǵ��������������������������target
			for (int j = target;j>nums[i];j--)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		//����Ϊtarget�ı�����ǡ�ñ�����
		if (dp[target] == target)
		{
			return true;
		}
		return false;
	}
};
int main()
{
	return 0;
}