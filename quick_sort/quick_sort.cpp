// quick_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
https://www.cnblogs.com/sxr666/p/11819574.html
它的平均运行时间为O(N logN)。该算法之所以快，主要是由于非常精炼和高度优化的内部循环。
它的最坏时间复杂度O(N ²)，但是可以避免
*/
#include <iostream>

#include<iostream>
#define max 1000
using namespace std;
//快速排序的数组，定义快速排序的区间
void q_sort(int args[], int begin, int end) {
	if (begin >= end)//bdgin<=end时结束程序
		return;
	int k = begin;//枢纽元选取
	int p = begin;//头位置指示
	int q = end;//尾位置指示
	while (p <= q)
	{
		if (args[p] > args[k] && args[q] < args[k]) {
			int t = args[p];
			args[p] = args[q];
			args[q] = t;
		}
		if (args[p] <= args[k])//头指针移动
			p++;
		if (args[q] >= args[k])//尾指针移动
			q--;
	}
	int t = args[q];
	args[q] = args[k];
	args[k] = t;
	//左右子序列进行操作
	q_sort(args, begin, q - 1);
	q_sort(args, q + 1, end);
}
