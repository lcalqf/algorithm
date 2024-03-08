/*
����Ա�����⾫ѡ(03)���������������
��Ŀ������һ���������飬������������Ҳ�и�����������������һ�������������һ�������飬ÿ�������鶼��һ
���͡�������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
�������������Ϊ1, -2, 3, 10, -4, 7, 2, -5��������������Ϊ3, 10, -4, 7, 2��������Ϊ��������ĺ�18��
�������������Ϊ2005���㽭��ѧ�����ϵ�Ŀ���������һ����������⣬��2006�������google���ڵĺܶ�֪����
˾���ѱ��⵱�������⡣���ڱ����������й�Ϊ����������Ҳ˳����Ϊ2006�����Ա�������о����еľ��䡣
���������ʱ�临�Ӷȣ����ǿ���ö�ٳ����������鲢������ǵĺ͡������ǳ��ź����ǣ����ڳ���Ϊn��������O(n2)
�������飻������һ������Ϊn������ĺ͵�ʱ�临�Ӷ�ΪO(n)���������˼·��ʱ����O(n3)��
��������⣬�����Ǽ���һ������ʱ���ͻ����ӣ������Ǽ���һ������ʱ���ͻ���١������ǰ�õ��ĺ��Ǹ���������
ô������ڽ��������ۼ���Ӧ���������������㣬��Ȼ�Ļ��������������ٽ������ĺ͡�����������˼·�����ǿ���
д�����´��롣
*/
//#include <stdio.h>
//�ο����룺
/////////////////////////////////////////////////////////////////////////////
// Find the greatest sum of all sub-arrays
// Return value: if the input is valid, return true, otherwise return false
/////////////////////////////////////////////////////////////////////////////
//bool FindGreatestSumOfSubArray
//(
//	int *pData, // an array
//	unsigned int nLength, // the length of array
//	int &nGreatestSum // the greatest sum of all sub-arrays
//) {
//	// if the input is invalid, return false
//	if ((pData == NULL) || (nLength == 0))
//		return false;
//	int nCurSum = nGreatestSum = 0;
//	for (unsigned int i = 0; i < nLength; ++i)
//	{
//		nCurSum += pData[i];
//		// if the current sum is negative, discard it
//		if (nCurSum < 0)
//			nCurSum = 0;
//		// if a greater sum is found, update the greatest sum
//		if (nCurSum > nGreatestSum)
//			nGreatestSum = nCurSum;
//	}
//	// if all data are negative, find the greatest element in the array
//	if (nGreatestSum == 0)
//	{
//		nGreatestSum = pData[0];
//		for (unsigned int i = 1; i < nLength; ++i)
//		{
//			if (pData[i] > nGreatestSum)
//				nGreatestSum = pData[i];
//		}
//	}
//	return true;
//}
//int main()
//{
//	int array[10] = { 3,-2,-4,-5,1,6,2,-5,-2,-3 };
//	int sum = -100000;
//	FindGreatestSumOfSubArray(array, 10, sum);
//	return 0;
//}
//��������������㷨
//https://www.cnblogs.com/AlgrithmsRookie/p/5882379.html
#include <stdio.h>
#include<vector>
#include <algorithm>
using namespace  std;
//���η�����������������
struct PositioASum {
	int low;
	int high;
	int sum;
};
//Ѱ�Ұ����е�λ�õ���������麯��
PositioASum MaxCrossingSubarray(int a[], int low, int mid, int high)
{
	//���е���ߵ����ֵ�����λ��
	int maxLeft;//��¼��ߵ����λ��
	int maxSumLeft = -10000;//��¼��ߵ�����
	int sumLeft = 0;
	for (int i = mid; i >= low; i--)
	{
		sumLeft += a[i];
		if (sumLeft > maxSumLeft)
		{
			maxSumLeft = sumLeft;
			maxLeft = i;
		}
	}
	//���е��ұߵ����ֵ�����λ��
	int maxRight = mid + 1;//��¼�ұߵ����λ��
	int maxSumRight = -10000;//��¼�ұߵ�����
	int sumRight = 0;//��¼�ұ������еĺ�
	for (int i = mid + 1; i <= high; i++)
	{
		sumRight += a[i];
		if (sumRight > maxSumRight)
		{
			maxSumRight = sumRight;
			maxRight = i;
		}
	}
	PositioASum ps;
	ps.low = maxLeft;
	ps.high = maxRight;
	ps.sum = maxSumLeft + maxSumRight;
	return ps;
}
//���η�
PositioASum FindMaxSubArray(int a[], int low, int high)
{
	if (low == high)
	{
		PositioASum ps;
		ps.low = low;
		ps.high = high;
		ps.sum = a[low];
		return ps;
	}
	else {
		int mid = (low + high) / 2;// <=(high-low)/2+low
		PositioASum left = FindMaxSubArray(a, low, mid);
		PositioASum right = FindMaxSubArray(a, mid + 1, high);
		PositioASum cross = MaxCrossingSubarray(a, low, mid, high);
		if (left.sum >= cross.sum && left.sum >= right.sum)
		{
			return left;
		}
		else if (right.sum >= left.sum && right.sum >= cross.sum)
		{
			return right;
		}
		else {
			return cross;
		}
	}
}


int maxSubArray(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	//dp��ʾָ��ָ���i��Ԫ��ʱ���������ĺ�   
	vector<int>dp = vector<int>(nums.size(), 0);
	//������������,�ʼres���϶���nums[0]��ֵ
	int res = nums[0];
	dp[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		//��Ϊdp[i]�Ǳ�ʾ�����±�iʱ�����������ĳ��ȣ�
		//����nums[i]�Ǳ����ѡ���
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		res = max(res, dp[i]);
	}
	return res;
}


int main(int argc, char* argv[])
{
	//int A[8] = { 1,0,3,0,-1 };
	//PositioASum result = FindMaxSubArray(A, 0, 4);
	//printf("%d  %d  %d", result.low, result.high, result.sum);//�������ӡ����

	vector<int> nums = { 5,4,-1,7,8 };
	int res = maxSubArray(nums);

	vector<vector<int>> dp = vector<vector<int>>(5, vector<int>(10,2));
	getchar();
	return 0;
}